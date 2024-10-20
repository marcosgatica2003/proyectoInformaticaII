#include "accesoRFID.h"

/**
*@brief Constructor de la clase accesoRFID
*
*@param ssPin: El pin SS (Slave Select) para la comunicación SPI.
*@param rstPin: es el pin de Reset para el módulo RFID.
*@param autorizarID: El UID de la tarjeta autorizada para el acceso.
*/

accesoRFID::accesoRFID (byte ssPin, byte rstPin, String ID): rdif(ssPin, rstPin), autorizarID(ID) {}


/**
*@brief void start();
* Este método llamada a otros dos de MFRC522.h y SPI.h para iniciar la comunicación entre el RFID (rfid.PCD_Init()) y el SPI (SPI_begin()).
*/
void accesoRFID::start(){
  SPI.begin();
  rdif.PCD_Init();
}

/**
* @brief bool autorizar();
* @return true si el UID coincide con el autorizado, false en caso contrario.
*/

bool accesoRFID::autorizar() {
    String content = "";

    if (!rdif.PICC_IsNewCardPresent()) {
        return false;
    }

    if (!rdif.PICC_ReadCardSerial()) {
        return false;
    }

    for (byte i = 0; i < rdif.uid.size; ++i) {
        content.concat(String(rdif.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(rdif.uid.uidByte[i], HEX));
    }

    content.toUpperCase();
    return content.substring(1) == autorizarID;
}

/**
* @brief void mostrarID();
* 
* Este método imprime el UID de la tarjeta detectada por el lector RFID en formato hexadecimal.
*/

void accesoRFID::mostrarID() {
  Serial.print("UID de la llave: ");

  for (byte i = 0; i < rdif.uid.size; ++i) {
    Serial.print(rdif.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(rdif.uid.uidByte[i], HEX);
  }

  Serial.println();

}
/**
* @brief bool detectarTarjeta();
* 
* Este método detecta si hay una tarjeta para poder leerla.
*/
bool accesoRFID::detectarTarjeta() {
  if (!rdif.PICC_IsNewCardPresent()) {
    return false;
  }

  if (!rdif.PICC_ReadCardSerial()) {
    return false;
  }

  return true;

}
