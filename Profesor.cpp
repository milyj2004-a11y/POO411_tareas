#include "Profesor.h"

Profesor::Profesor() {
}

Profesor::Profesor(const std::string& nombreCompleto,
                   const std::string& codigoProfesor)
    : nombreCompleto(nombreCompleto),
      codigoProfesor(codigoProfesor) {
}

Profesor::Profesor(const Profesor& otro)
    : nombreCompleto(otro.nombreCompleto),
      codigoProfesor(otro.codigoProfesor) {
}

std::string Profesor::getNombreCompleto() const {
    return nombreCompleto;
}

std::string Profesor::getCodigoProfesor() const {
    return codigoProfesor;
}

Profesor& Profesor::operator=(const Profesor& otro) {
    if (this != &otro) {
        nombreCompleto = otro.nombreCompleto;
        codigoProfesor = otro.codigoProfesor;
    }
    return *this;
}
