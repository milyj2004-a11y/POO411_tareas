#include "Estudiante.h"

Estudiante::Estudiante() {
}
Estudiante::Estudiante(
    const std::string& nombreCompleto,
    const std::string& matricula,
    const std::string& sesion)
    : Persona(nombreCompleto),
      matricula(matricula),
      sesion(sesion)
{
}


Estudiante::Estudiante(const Estudiante& otro)
    : Persona(otro),
      matricula(otro.matricula),
      sesion(otro.sesion)
{
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
        Persona::operator=(otro);
        matricula = otro.matricula;
        sesion = otro.sesion;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& salida,
                         const Estudiante& estudiante)
{
    salida
        << estudiante.getNombreCompleto() << '|'
        << estudiante.getMatricula() << '|'
        << estudiante.getSesion();

    return salida;
}
std::istream& operator>>(std::istream& entrada,
                         Estudiante& estudiante)
{
    std::getline(entrada, estudiante.nombreCompleto, '|');
    std::getline(entrada, estudiante.matricula, '|');
    std::getline(entrada, estudiante.sesion);

    return entrada;
}
