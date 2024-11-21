#ifndef USUARIO_H
#define USUARIO_H

#include <Arduino.h>

/**
 * @class usuario
 * @brief Clase para gestionar usuarios con acceso RFID.
 * Permite la creación de objetos usuarios y almacena la dirección de RFID que poseen.
 */

class usuario {
    public:

        /**
         * @brief Constructor de la clase usuario
         * @param id: Referencia constante String que contiene el ID para accionar el RFID.
         * @param nombre: Referencia constante String que almancena un String con el nombre del usuario.
         * @param apellido: Referencia constante String que alamacena un String con el apellido del usuario.
         */

        usuario(const String& id, const String& nombre, const String& apellido);

        /**
         * @brief String getID() const;
         * Función constante que devuelve el ID del usuario en forma de String.
         */

        String getID() const;

        /**
         * @brief String getNombre() const;
         * Función constante que devuelve el nombre del usuario en forma de String.
         */

        String getNombre() const;

        /**
         * @brief String getApellido() const;
         * Función constante que devuelve el apellido del usuario en forma de String.
         */

        String getApellido() const;

        /**
         * @brief int getContadorAccesos() const;
         * Función constante que devuelve las veces que un usuario usó su dispotivo para accionar el RFID.
         */

        unsigned int getContadorAccesos() const;

        /**
         * @brief void incrementarAcceso() const;
         * Función constante que incrementa el dato miembro _contadorAccesos.
         */

        void incrementarAcceso();
        
    private:
        String _id; ///< Miembro privado que contiene el ID del usuario para el RFID.
        String _nombre; ///< Miembro privado que contiene el nombre del usuario.
        String _apellido; ///< Miembro privado que contiene el apellido del usuario.
        unsigned int _contadorAccesos; ///< Miembro privado que almacena las veces que el usuario usó su identificador para el RFID.
};

#endif
