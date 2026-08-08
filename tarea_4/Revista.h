#ifndef REVISTA_H
#define REVISTA_H

#include "MaterialBiblioteca.h"
#include <string>

class Revista : public MaterialBiblioteca
{
private:
    int numeroEdicion;
    std::string mes;

public:
    Revista(int codigo,
             const std::string& titulo,
             int numeroEdicion,
             const std::string& mes,
             bool disponible = true);

    void mostrar() const override;

    std::string getTipo() const override;

    std::string guardar() const override;
};

#endif