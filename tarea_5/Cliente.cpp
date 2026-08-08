#include "Cliente.h"

#include <iostream>
#include <sstream>

Cliente::Cliente()
    : documento(""),
      nombre(""),
      telefono("")
{
}

Cliente::Cliente(
    const std::string& documento,
    const std::string& nombre,
    const std::string& telefono)
    : documento(documento),
      nombre(nombre),
      telefono(telefono)
{
}

std::string Cliente::getDocumento() const
{
    return documento;
}

std::string Cliente::getNombre() const
{
    return nombre;
}

std::string Cliente::getTelefono() const
{
    return telefono;
}

void Cliente::mostrar() const
{
    std::cout
        << documento << " | "
        << nombre << " | "
        << telefono << '\n';
}

std::string Cliente::guardar() const
{
    std::ostringstream salida;

    salida << documento << ';'
           << nombre << ';'
           << telefono;

    return salida.str();
}