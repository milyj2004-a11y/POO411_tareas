#include "Revista.h"

#include <iostream>
#include <sstream>

Revista::Revista(
    int codigo,
    const std::string& titulo,
    int numeroEdicion,
    const std::string& mes,
    bool disponible)
    : MaterialBiblioteca(codigo, titulo, disponible)
{
    this->numeroEdicion = numeroEdicion;
    this->mes = mes;
}

void Revista::mostrar() const
{
    std::cout
        << "Revista\n"
        << "Codigo: " << getCodigo() << '\n'
        << "Titulo: " << getTitulo() << '\n'
        << "Edicion: " << numeroEdicion << '\n'
        << "Mes: " << mes << '\n'
        << "Disponible: "
        << (estaDisponible() ? "Si" : "No")
        << "\n\n";
}

std::string Revista::getTipo() const
{
    return "REVISTA";
}

std::string Revista::guardar() const
{
    std::ostringstream salida;

    salida
        << "REVISTA;"
        << getCodigo() << ';'
        << getTitulo() << ';'
        << estaDisponible() << ';'
        << numeroEdicion << ';'
        << mes;

    return salida.str();
}