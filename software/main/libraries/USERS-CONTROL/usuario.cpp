#include "usuario.h"

usuario::usuario(const String& id, const String& nombre, const String& apellido): _id(id), _nombre(nombre), _apellido(apellido), _contadorAccesos(0) {}

String usuario::getID() const { return _id; }

String usuario::getNombre() const { return _nombre; }

String usuario::getApellido() const { return _apellido; }

unsigned int usuario::getContadorAccesos() const { return _contadorAccesos; }

void usuario::incrementarAcceso() { _contadorAccesos++; }


