#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente
{
private:
    std::string documento;
    std::string nombre;
    std::string telefono;

public:
    Cliente();

    Cliente(
        const std::string& documento,
        const std::string& nombre,
        const std::string& telefono
    );

    std::string getDocumento() const;
    std::string getNombre() const;
    std::string getTelefono() const;

    void mostrar() const;

    std::string guardar() const;
};

#endif