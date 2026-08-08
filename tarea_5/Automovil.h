#ifndef AUTOMOVIL_H
#define AUTOMOVIL_H

#include "Vehiculo.h"

class Automovil : public Vehiculo
{
private:
    int puertas;

public:
    Automovil(
        const std::string& matricula,
        const std::string& marca,
        const std::string& modelo,
        int anio,
        double tarifaDiaria,
        int puertas,
        bool disponible = true
    );

    int getPuertas() const;

    std::string obtenerTipo() const override;

    double calcularTarifaDiaria() const override;

    std::string guardar() const override;

    void mostrar() const override;
};

#endif