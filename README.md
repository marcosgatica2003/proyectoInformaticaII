# Sistema de Seguridad para Cámaras Frigoríficas

## Descripción
Este proyecto implementa un sistema de seguridad diseñado específicamente para cámaras frigoríficas industriales, con el objetivo de prevenir accidentes y garantizar la seguridad de los operarios que trabajan en ambientes de temperaturas extremadamente bajas.

El sistema cuenta con múltiples características de seguridad:
- Control de acceso para personal autorizado
- Sistema de temporización dual con alertas visuales
- Monitoreo de temperatura en tiempo real
- Sistema de alarma de emergencia
- Interfaz LED para visualización de tiempo restante
- Sensor de apertura de puerta
- Botón de reinicio de temporizadores

## Estructura del Proyecto
El repositorio está organizado en tres áreas principales de desarrollo:

### `/software` (rama `devel`)
Contiene todo el código fuente relacionado con el software del sistema, incluyendo:
- Documentación del código con Doxygen, con salida a LaTeX.
- El directorio main, con el archivo main.ino y un directorio de librerías.

### `/hardware` (rama `hardware`)
Documentación y especificaciones del hardware, incluyendo:
- Lista de componentes.
- Datasheet's de los componentes.

### `/docs` (rama `docs`)
Toda la documentación del proyecto:
- Diagrama de bloques.
- Presentación.
- Una guía de cómo generar aportes a este repositorio.

## Requisitos de Instalación
### Sistemas basados en Debian/Ubuntu
```bash
# Actualizar repositorios
sudo apt update
sudo apt full-upgrade
# Instalar herramientas de desarrollo
sudo apt install git build-essential
# Instalar Arduino IDE y herramientas AVR
sudo apt install arduino arduino-core
sudo apt install gcc-avr avr-libc avrdude
# Instalar bibliotecas adicionales
sudo apt install arduino-mk
# Dependencias para generar documentación de código
sudo apt install doxygen texlive-latex-base texlive-latex-extra texlive-fonts-recommended
```
### Sistemas basados en Arch Linux
```bash
# Actualizar sistema
sudo pacman -Syu
# Instalar herramientas de desarrollo
sudo pacman -S git base-devel
# Instalar Arduino IDE y herramientas AVR
sudo pacman -S arduino arduino-avr-core
sudo pacman -S avr-gcc avr-libc avrdude
# Instalar bibliotecas adicionales
sudo pacman -S arduino-builder
# Dependencias para generar documentación de código
sudo pacman -Syu doxygen texlive-most
```
## Configuración del Entorno
1. Clone el repositorio:
```bash
git clone git@github.com:marcosgatica2003/proyectoInformaticaII.git
cd proyectoInformaticaII
```
2. Configure los permisos de puerto serie para Arduino:
```bash
# Agregar usuario al grupo dialout (Debian/Ubuntu)
sudo usermod -a -G dialout $USER
# Agregar usuario al grupo uucp (Arch Linux)
sudo usermod -a -G uucp $USER
# Puede comprobar el grupo al cual debe pertenecer para configurar el puerto serie haciendo
sudo dmesg
# Con el comando anterior, puede conocer cómo se listó su Arduino, a continuación haga:
ls -l /dev/ttyXXX
```
3. Reinicie su sesión para que los cambios de grupo surtan efecto.
## Contribuir al Proyecto
Por favor, lea nuestra [guía de contribución](/docs/generarAportes/comoGenerarAportes.pdf) para detalles sobre nuestro código de conducta y el proceso para enviar pull requests.
## Autores
- Salas Joaquín (Leg. 98368)
- Zacco Facundo (Leg. 97663)
- Mercadal Juan Ignacio (Leg. 95561)
- Marcos Raúl Gatica (Leg. 402006)
## Licencia
Este proyecto está licenciado bajo la Licencia GPL - vea el archivo [LICENSE](/LICENSE) para más detalles.
