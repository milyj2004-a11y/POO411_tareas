#include "Prestamo.h"

#include <iostream>
#include <sstream>

Prestamo::Prestamo()
{
    codigoUsuario = 0;
    codigoMaterial = 0;
    fecha = "";
    activo = false;
}

Prestamo::Prestamo(int codigoUsuario,
                   int codigoMaterial,
                   const std::string& fecha,
                   bool activo)
{
    this->codigoUsuario = codigoUsuario;
    this->codigoMaterial = codigoMaterial;
    this->fecha = fecha;
    this->activo = activo;
}

int Prestamo::getCodigoUsuario() const
{
    return codigoUsuario;
}

int Prestamo::getCodigoMaterial() const
{
    return codigoMaterial;
}

std::string Prestamo::getFecha() const
{
    return fecha;
}

bool Prestamo::estaActivo() const
{
    return activo;
}

void Prestamo::devolver()
{
    activo = false;
}

void Prestamo::mostrar() const
{
    std::cout
        << "Usuario: " << codigoUsuario << '\n'
        << "Material: " << codigoMaterial << '\n'
        << "Fecha: " << fecha << '\n'
        << "Estado: "
        << (activo ? "Prestado" : "Devuelto")
        << "\n\n";
}

std::string Prestamo::guardar() const
{
    std::ostringstream salida;

    salida
        << codigoUsuario << ';'
        << codigoMaterial << ';'
        << fecha << ';'
        << activo;

    return salida.str();
}