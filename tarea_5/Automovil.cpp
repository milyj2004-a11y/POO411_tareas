#include "Automovil.h"

#include <iostream>
#include <sstream>

Automovil::Automovil(
    const std::string& matricula,
    const std::string& marca,
    const std::string& modelo,
    int anio,
    double tarifaDiaria,
    int puertas,
    bool disponible)
    : Vehiculo(
        matricula,
        marca,
        modelo,
        anio,
        tarifaDiaria,
        disponible),
      puertas(puertas)
{
}

int Automovil::getPuertas() const
{
    return puertas;
}

std::string Automovil::obtenerTipo() const
{
    return "Automovil";
}

double Automovil::calcularTarifaDiaria() const
{
    return getTarifaDiaria();
}

std::string Automovil::guardar() const
{
    std::ostringstream salida;

    salida << obtenerTipo() << ';'
           << getMatricula() << ';'
           << getMarca() << ';'
           << getModelo() << ';'
           << getAnio() << ';'
           << getTarifaDiaria() << ';'
           << (estaDisponible() ? 1 : 0) << ';'
           << puertas;

    return salida.str();
}

void Automovil::mostrar() const
{
    std::cout
        << obtenerTipo() << " | "
        << getMatricula() << " | "
        << getMarca() << " | "
        << getModelo() << " | "
        << getAnio() << " | "
        << getTarifaDiaria() << " | "
        << puertas << " puertas | "
        << (estaDisponible() ? "Disponible" : "No disponible")
        << '\n';
}