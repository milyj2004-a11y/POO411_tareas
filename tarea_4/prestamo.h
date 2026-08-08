#ifndef PRESTAMO_H
#define PRESTAMO_H

#include <string>

class Prestamo
{
private:
    int codigoUsuario;
    int codigoMaterial;
    std::string fecha;
    bool activo;

public:
    Prestamo();

    Prestamo(int codigoUsuario,
             int codigoMaterial,
             const std::string& fecha,
             bool activo = true);

    int getCodigoUsuario() const;

    int getCodigoMaterial() const;

    std::string getFecha() const;

    bool estaActivo() const;

    void devolver();

    void mostrar() const;

    std::string guardar() const;
};

#endif