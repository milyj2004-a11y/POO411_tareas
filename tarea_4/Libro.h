#ifndef LIBRO_H
#define LIBRO_H

#include "MaterialBiblioteca.h"

class Libro : public MaterialBiblioteca
{
private:
    std::string autor;
    int paginas;

public:
    Libro(int codigo,
           const std::string& titulo,
           const std::string& autor,
           int paginas,
           bool disponible = true);

    void mostrar() const override;

    std::string getTipo() const override;

    std::string guardar() const override;
};

#endif