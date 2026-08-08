#include "Vehiculo.h"

Vehiculo::Vehiculo(
    const std::string& matricula,
    const std::string& marca,
    const std::string& modelo,
    int anio,
    double tarifaDiaria,
    bool disponible)
    : matricula(matricula),
      marca(marca),
      modelo(modelo),
      anio(anio),
      tarifaDiaria(tarifaDiaria),
      disponible(disponible)
{
}

std::string Vehiculo::getMatricula() const
{
    return matricula;
}

std::string Vehiculo::getMarca() const
{
    return marca;
}

std::string Vehiculo::getModelo() const
{
    return modelo;
}

int Vehiculo::getAnio() const
{
    return anio;
}

double Vehiculo::getTarifaDiaria() const
{
    return tarifaDiaria;
}

bool Vehiculo::estaDisponible() const
{
    return disponible;
}

void Vehiculo::alquilar()
{
    disponible = false;
}

void Vehiculo::devolver()
{
    disponible = true;
}

void Vehiculo::setDisponible(bool disponible)
{
    this->disponible = disponible;
}