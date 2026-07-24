#include "Profesor.h"

Profesor::Profesor() {
}

Profesor::Profesor(
    const std::string& nombreCompleto,
    const std::string& codigoProfesor)
    : Persona(nombreCompleto),
      codigoProfesor(codigoProfesor)
{
}

Profesor::Profesor(const Profesor& otro)
    : Persona(otro),
      codigoProfesor(otro.codigoProfesor)
{
}

std::string Profesor::getCodigoProfesor() const {
    return codigoProfesor;
}

Profesor& Profesor::operator=(const Profesor& otro) {
    if (this != &otro) {
        Persona::operator=(otro);
        codigoProfesor = otro.codigoProfesor;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& salida,
                         const Profesor& profesor)
{
    salida
        << profesor.getNombreCompleto() << '|'
        << profesor.getCodigoProfesor();

    return salida;
}

std::istream& operator>>(std::istream& entrada,
                         Profesor& profesor)
{
    std::string nombre;

    std::getline(entrada, nombre, '|');
    profesor.setNombreCompleto(nombre);

    std::getline(entrada, profesor.codigoProfesor);

    return entrada;
}
