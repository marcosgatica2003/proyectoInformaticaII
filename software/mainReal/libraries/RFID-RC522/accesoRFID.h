#ifndef ACCESORRFID_H
#define ACCESORRFID_H

#include <SPI.h>
#include "MFRC522.h"

/**

* @class accesoRFID
* @brief Clase para manejar el acceso usando el módulo RFID-RC522
*
*Esta clase permite inicializar el lector RFID y verificar si una tarjeta tiene autorización para entrar.
*/


class accesoRFID {
    public:

      /**
      *@brief Constructor de la clase accesoRFID
      *
      *@param ssPin: El pin SS (Slave Select) para la comunicación SPI.
      *@param rstPin: es el pin de Reset para el módulo RFID.
      *@param autorizarID: El UID de la tarjeta autorizada para el acceso.
      */

      accesoRFID(byte ssPin, byte rstPin, String autorizarID);

      /**
      *@brief void start();
      * Inicia la comunicación SPI con el módulo RFID (usando sus métodos).
      */

      void start();
        
      /**
      *@brief void mostrarID(); 
      *Imprime por puerto serie el UID de la tarjeta detectada por el RFID
      *
      */

      void mostrarID();

      /**
      *@brief bool autorizar();
      *Compara el UID de la tarjeta con el UID autorizado. Devuelve true (acceso permitido) o un false (acceso denegado).
      */

      String autorizar();

      /**
      *@brief bool detectarTarjeta();
      *Lee el UID de la tarjeta para implementarla en el sistema.
      */

      bool detectarTarjeta();

    private:
        MFRC522 rdif; ///< Instancia del lector RFID.
        String autorizarID; ///< UID de la tarjeta con acceso autorizado.

};

#endif
