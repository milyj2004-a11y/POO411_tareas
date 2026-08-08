#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>

class Vehiculo
{
private:
    std::string matricula;
    std::string marca;
    std::string modelo;
    int anio;
    double tarifaDiaria;
    bool disponible;

public:
    Vehiculo(
        const std::string& matricula,
        const std::string& marca,
        const std::string& modelo,
        int anio,
        double tarifaDiaria,
        bool disponible = true
    );

    virtual ~Vehiculo() = default;

    std::string getMatricula() const;
    std::string getMarca() const;
    std::string getModelo() const;
    int getAnio() const;
    double getTarifaDiaria() const;
    bool estaDisponible() const;

    void alquilar();
    void devolver();
    void setDisponible(bool disponible);

    virtual std::string obtenerTipo() const = 0;
    virtual double calcularTarifaDiaria() const = 0;
    virtual std::string guardar() const = 0;
    virtual void mostrar() const = 0;
};

#endif