#include "Motocicleta.h"

#include <iostream>
#include <sstream>

Motocicleta::Motocicleta(
    const std::string& matricula,
    const std::string& marca,
    const std::string& modelo,
    int anio,
    double tarifaDiaria,
    int cilindrada,
    bool disponible)
    : Vehiculo(
        matricula,
        marca,
        modelo,
        anio,
        tarifaDiaria,
        disponible),
      cilindrada(cilindrada)
{
}

int Motocicleta::getCilindrada() const
{
    return cilindrada;
}

std::string Motocicleta::obtenerTipo() const
{
    return "Motocicleta";
}

double Motocicleta::calcularTarifaDiaria() const
{
    return getTarifaDiaria();
}

std::string Motocicleta::guardar() const
{
    std::ostringstream salida;

    salida << obtenerTipo() << ';'
           << getMatricula() << ';'
           << getMarca() << ';'
           << getModelo() << ';'
           << getAnio() << ';'
           << getTarifaDiaria() << ';'
           << (estaDisponible() ? 1 : 0) << ';'
           << cilindrada;

    return salida.str();
}

void Motocicleta::mostrar() const
{
    std::cout
        << obtenerTipo() << " | "
        << getMatricula() << " | "
        << getMarca() << " | "
        << getModelo() << " | "
        << getAnio() << " | "
        << getTarifaDiaria() << " | "
        << cilindrada << " cc | "
        << (estaDisponible() ? "Disponible" : "No disponible")
        << '\n';
}