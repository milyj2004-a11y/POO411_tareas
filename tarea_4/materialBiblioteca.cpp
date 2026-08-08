#include "MaterialBiblioteca.h"

MaterialBiblioteca::MaterialBiblioteca(
    int codigo,
    const std::string& titulo,
    bool disponible)
{
    this->codigo = codigo;
    this->titulo = titulo;
    this->disponible = disponible;
}

MaterialBiblioteca::~MaterialBiblioteca()
{
}

int MaterialBiblioteca::getCodigo() const
{
    return codigo;
}

std::string MaterialBiblioteca::getTitulo() const
{
    return titulo;
}

bool MaterialBiblioteca::estaDisponible() const
{
    return disponible;
}

void MaterialBiblioteca::prestar()
{
    disponible = false;
}

void MaterialBiblioteca::devolver()
{
    disponible = true;
}

void MaterialBiblioteca::setDisponible(bool disponible)
{
    this->disponible = disponible;
}
