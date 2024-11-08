#ifndef USUARIO_H
#define USUARIO_H

#include <Arduino.h>

class usuario {
    public:
        usuario(const String& id, const String& nombre, const String& apellido);
        String getID() const;
        String getNombre() const;
        String getApellido() const;
        unsigned int getContadorAccesos() const;
        void incrementarAcceso();
        
    private:
        String _id;
        String _nombre;
        String _apellido;
        unsigned int _contadorAccesos;
};

#endif
