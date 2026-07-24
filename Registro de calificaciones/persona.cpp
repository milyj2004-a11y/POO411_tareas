#include "Persona.h"

Persona::Persona()
    : nombreCompleto("")
{
}

Persona::Persona(const std::string& nombreCompleto)
    : nombreCompleto(nombreCompleto)
{
}

Persona::Persona(const Persona& otra)
    : nombreCompleto(otra.nombreCompleto)
{
}

Persona& Persona::operator=(const Persona& otra) {

    if (this != &otra) {
        nombreCompleto = otra.nombreCompleto;
    }

    return *this;
}

std::string Persona::getNombreCompleto() const {


  return nombreCompleto;
}

void Persona::setNombreCompleto(const std::string& nombreCompleto)
{
    this->nombreCompleto = nombreCompleto;
}

Persona::~Persona() {
}
