#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario
{
private:
    int codigo;
    std::string nombre;

public:
    Usuario();

    Usuario(int codigo,
             const std::string& nombre);

    int getCodigo() const;

    std::string getNombre() const;

    void mostrar() const;

    std::string guardar() const;
};

#endif