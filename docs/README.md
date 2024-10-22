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
- Programación de microcontroladores
- Lógica de control
- Interfaz de usuario
- Sistemas de alerta

### `/hardware` (rama `hardware`)
Documentación y especificaciones del hardware, incluyendo:
- Lista de componentes
- Diagramas de conexión
- Especificaciones técnicas

### `/docs` (rama `docs`)
Toda la documentación del proyecto:
- Datasheet's
- Guías de instalación
- Documentación técnica

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
