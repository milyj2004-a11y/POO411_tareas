#ifndef MOTOCICLETA_H
#define MOTOCICLETA_H

#include "Vehiculo.h"

class Motocicleta : public Vehiculo
{
private:
    int cilindrada;

public:
    Motocicleta(
        const std::string& matricula,
        const std::string& marca,
        const std::string& modelo,
        int anio,
        double tarifaDiaria,
        int cilindrada,
        bool disponible = true
    );

    int getCilindrada() const;

    std::string obtenerTipo() const override;

    double calcularTarifaDiaria() const override;

    std::string guardar() const override;

    void mostrar() const override;
};

#endif