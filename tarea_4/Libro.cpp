#include <iostream>
#include <sstream>

#include "Libro.h"

Libro::Libro(
    int codigo,
    const std::string& titulo,
    const std::string& autor,
    int paginas,
    bool disponible)
    : MaterialBiblioteca(codigo, titulo, disponible)
{
    this->autor = autor;
    this->paginas = paginas;
}

void Libro::mostrar() const
{
    std::cout
        << "Libro\n"
        << "Codigo: " << getCodigo() << '\n'
        << "Titulo: " << getTitulo() << '\n'
        << "Autor: " << autor << '\n'
        << "Paginas: " << paginas << '\n'
        << "Disponible: "
        << (estaDisponible() ? "Si" : "No")
        << "\n\n";
}

std::string Libro::getTipo() const
{
    return "LIBRO";
}

std::string Libro::guardar() const
{
    std::ostringstream salida;

    salida
        << "LIBRO;"
        << getCodigo() << ';'
        << getTitulo() << ';'
        << estaDisponible() << ';'
        << autor << ';'
        << paginas;

    return salida.str();
}