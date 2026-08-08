#include "Alquiler.h"

#include <iostream>
#include <sstream>
#include <iomanip>

Alquiler::Alquiler()
    : codigo(0),
      documentoCliente(""),
      matriculaVehiculo(""),
      fechaInicio(""),
      dias(0),
      tarifaDiaria(0.0),
      activo(false)
{
}

Alquiler::Alquiler(
    int codigo,
    const std::string& documentoCliente,
    const std::string& matriculaVehiculo,
    const std::string& fechaInicio,
    int dias,
    double tarifaDiaria,
    bool activo)
    : codigo(codigo),
      documentoCliente(documentoCliente),
      matriculaVehiculo(matriculaVehiculo),
      fechaInicio(fechaInicio),
      dias(dias),
      tarifaDiaria(tarifaDiaria),
      activo(activo)
{
}

int Alquiler::getCodigo() const
{
    return codigo;
}

std::string Alquiler::getDocumentoCliente() const
{
    return documentoCliente;
}

std::string Alquiler::getMatriculaVehiculo() const
{
    return matriculaVehiculo;
}

std::string Alquiler::getFechaInicio() const
{
    return fechaInicio;
}

int Alquiler::getDias() const
{
    return dias;
}

double Alquiler::getTarifaDiaria() const
{
    return tarifaDiaria;
}

bool Alquiler::estaActivo() const
{
    return activo;
}

void Alquiler::finalizar()
{
    activo = false;
}

double Alquiler::calcularCostoTotal() const
{
    return dias * tarifaDiaria;
}

void Alquiler::mostrar() const
{
    std::cout
        << codigo << " | "
        << documentoCliente << " | "
        << matriculaVehiculo << " | "
        << fechaInicio << " | "
        << dias << " | "
        << std::fixed << std::setprecision(2)
        << tarifaDiaria << " | "
        << (activo ? "Activo" : "Finalizado")
        << '\n';
}

std::string Alquiler::guardar() const
{
    std::ostringstream salida;

    salida << codigo << ';'
           << documentoCliente << ';'
           << matriculaVehiculo << ';'
           << fechaInicio << ';'
           << dias << ';'
           << tarifaDiaria << ';'
           << (activo ? 1 : 0);

    return salida.str();
}