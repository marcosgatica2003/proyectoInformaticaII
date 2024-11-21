#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

void mostrarMenu() {
    printf("\n=== MENÚ DE OPCIONES ===\n");
    printf("1. Leer temperatura (getTemp)\n");
    printf("2. Leer cantidad de accesos (cantAperturas)\n");
    printf("3. Cambiar tiempo del servo (tiempoServo)\n");
    printf("4. Cambiar tiempo de acceso (tiempoAcceso)\n");
    printf("5. Forzar salida\n");
    printf("6. Salir y guardar historial.\n");
    printf("Ingrese una opción: ");

}

int comunicacionSerial(int fd, const char *mensaje, char *respuesta, size_t len) {
    ssize_t bytes_escritos = write(fd, mensaje, strlen(mensaje));
    if(bytes_escritos == -1) {
        perror("Error al escribir el puerto serie");
        return 1;
    }

    tcflush(fd, TCIFLUSH);
    sleep(5);

    ssize_t bytes_leidos = read(fd, respuesta, len -1);
    if(bytes_leidos > 0) {
        respuesta[bytes_leidos] = '\0';
    }

    return 0;
}

void cleanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main (void){
    int fd;
    /* char buffer[256] = {'\0'}; */
    char opcion[2];
    struct termios options;

    fd = open("/dev/ttyUSB0", O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd == -1) {
        perror("Error al abrir el puerto");
        return 1;
    }

    tcgetattr(fd, &options); // Obtener la configuración actual
    cfsetispeed(&options, B9600); // Velocidad de entrada (baud rate)
    cfsetospeed(&options, B9600); // Velocidad de salida
    options.c_cflag |= (CLOCAL | CREAD); // Habilitar lectura
    options.c_cflag &= ~PARENB; // Sin paridad
    options.c_cflag &= ~CSTOPB; // Un bit de parada
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8; // Ocho bits de datos
    tcsetattr(fd, TCSANOW, &options); // Aplicar la configuración

    FILE *archivo = fopen("datos.txt", "w");
    if (!archivo) {
        perror("Error al abrir el archivo");
        close(fd);
        return 1;
    }

    sleep(2);
    while(1) {
        /* memset(buffer, 0, sizeof(buffer)); */
        char buffer[256] = {'\0'};
        ssize_t bytes_leidos = read(fd, buffer, sizeof(buffer) - 1); 
        buffer[bytes_leidos] = '\0';
        printf("\nMensajes: %s\n", buffer);

        mostrarMenu();
        fgets(opcion, sizeof(opcion), stdin);
        if (opcion[0] < '1' || opcion[0] > '6') {
            printf("Opción no válida, intente de nuevo. \n");
            continue;
        }

        if(opcion[0] == '6') {
            printf("Saliendo...\n");
            break;
        }

        if(opcion[0] == '1') {
            char buffer[256] = {'\0'};
            const char *comando = "getTemp";
            if (comunicacionSerial(fd, comando, buffer, sizeof(buffer)) == 0) {
                printf("\nRespuesta: %s\n", buffer);
                fprintf(archivo, "Comando: %s\nRespuesta: %s\n\n", comando, buffer);
            }
        }

        if(opcion[0] == '5') {
            char buffer[256] = {'\0'};

            const char *comando = "forzar entrada";
            if (comunicacionSerial(fd, comando, buffer, sizeof(buffer)) == 0) {
                printf("\nRespuesta: %s\n", buffer);
                fprintf(archivo, "Comando: %s\nRespuesta: %s\n\n", comando, buffer);

            }
        }

        if(opcion[0] == '2') {
            char buffer[256] = {'\0'};

            const char *comando = "cantidad de accesos"; 
            if (comunicacionSerial(fd, comando, buffer, sizeof(buffer)) == 0) {
                printf("\nRespuesta: %s\n", buffer);
                fprintf(archivo, "Comando: %s\nRespuesta: %s\n\n", comando, buffer);

            }
        }

        if(opcion[0] == '4') {
            char buffer[256] = {'\0'};
            printf("Nuevo valor del temporizador (en milisegundos): ");
            int nuevoValor = 0;
            scanf("%d", &nuevoValor);
            printf("Valor ingresado: %d\n", nuevoValor);
            const char *comando = "tiempo";
            write(fd, comando, strlen(comando));
            sleep(3);
            char bufferValor[16];
            snprintf(bufferValor, sizeof(bufferValor), "%d\n", nuevoValor);
            write(fd, bufferValor, strlen(bufferValor));
            sleep(3);
            ssize_t bytes_leidos = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_leidos > 0) {
                buffer[bytes_leidos] = '\0';
                printf("Respuesta: %s\n", buffer);
            }
            fprintf(archivo, "Comando: %s\nRespuesta: %s\n\n", comando, buffer);
        }

        if(opcion[0] == '3') {
            char buffer[256] = {'\0'};
            printf("Nuevo valor del tiempo servo (en milisegundos): ");
            int nuevoValor = 0;
            scanf("%d", &nuevoValor);
            printf("Valor ingresado: %d\n", nuevoValor);
            const char *comando = "tiempoServo";
            ssize_t bytes_escritos = write(fd, comando, strlen(comando));
            sleep(3);
            char bufferValor[16];
            snprintf(bufferValor, sizeof(bufferValor), "%d\n", nuevoValor);
            bytes_escritos = write(fd, bufferValor, strlen(bufferValor));
            sleep(3);
            ssize_t bytes_leidos = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_leidos > 0) {
                buffer[bytes_leidos] = '\0';
                printf("Respuesta: %s\n", buffer);
            }
            fprintf(archivo, "Comando: %s\nRespuesta: %s\n\n", comando, buffer);
        }

        sleep(3);
        cleanBuffer();
    }
    fclose(archivo);
    close(fd);
    return 0;
}
