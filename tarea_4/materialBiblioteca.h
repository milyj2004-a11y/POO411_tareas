#ifndef MATERIALBIBLIOTECA_H
#define MATERIALBIBLIOTECA_H

#include <string>

class MaterialBiblioteca
{
private:
    int codigo;
    std::string titulo;
    bool disponible;

public:
    MaterialBiblioteca(int codigo,
                       const std::string& titulo,
                       bool disponible = true);

    virtual ~MaterialBiblioteca();

    int getCodigo() const;
    std::string getTitulo() const;

    bool estaDisponible() const;

    void prestar();
    void devolver();
void setDisponible(bool disponible);


    virtual void mostrar() const = 0;

    virtual std::string getTipo() const = 0;

    virtual std::string guardar() const = 0;
};

#endif