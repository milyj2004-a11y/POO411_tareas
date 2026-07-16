#include "Estudiante.h"

Estudiante::Estudiante() {
}

Estudiante::Estudiante(const std::string& nombreCompleto,
                       const std::string& matricula,
                       const std::string& sesion)
    : nombreCompleto(nombreCompleto),
      matricula(matricula),
      sesion(sesion) {
}

Estudiante::Estudiante(const Estudiante& otro)
    : nombreCompleto(otro.nombreCompleto),
      matricula(otro.matricula),
      sesion(otro.sesion) {
}

std::string Estudiante::getNombreCompleto() const {
    return nombreCompleto;
}

std::string Estudiante::getMatricula() const {
    return matricula;
}

std::string Estudiante::getSesion() const {
    return sesion;
}

Estudiante& Estudiante::operator=(const Estudiante& otro) {
    if (this != &otro) {
        nombreCompleto = otro.nombreCompleto;
        matricula = otro.matricula;
        sesion = otro.sesion;
    }
    return *this;
}
