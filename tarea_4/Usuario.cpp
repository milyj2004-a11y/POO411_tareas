#include "Usuario.h"

#include <iostream>
#include <sstream>

Usuario::Usuario()
{
    codigo = 0;
    nombre = "";
}

Usuario::Usuario(int codigo,
                 const std::string& nombre)
{
    this->codigo = codigo;
    this->nombre = nombre;
}

int Usuario::getCodigo() const
{
    return codigo;
}

std::string Usuario::getNombre() const
{
    return nombre;
}

void Usuario::mostrar() const
{
    std::cout
        << "Codigo: "
        << codigo
        << "\nNombre: "
        << nombre
        << "\n\n";
}

std::string Usuario::guardar() const
{
    std::ostringstream salida;

    salida
        << codigo
        << ';'
        << nombre;

    return salida.str();
}