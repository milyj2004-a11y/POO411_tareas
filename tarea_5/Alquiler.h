#ifndef ALQUILER_H
#define ALQUILER_H

#include <string>

class Alquiler
{
private:
    int codigo;
    std::string documentoCliente;
    std::string matriculaVehiculo;
    std::string fechaInicio;
    int dias;
    double tarifaDiaria;
    bool activo;

public:
    Alquiler();

    Alquiler(
        int codigo,
        const std::string& documentoCliente,
        const std::string& matriculaVehiculo,
        const std::string& fechaInicio,
        int dias,
        double tarifaDiaria,
        bool activo = true
    );

    int getCodigo() const;
    std::string getDocumentoCliente() const;
    std::string getMatriculaVehiculo() const;
    std::string getFechaInicio() const;
    int getDias() const;
    double getTarifaDiaria() const;
    bool estaActivo() const;

    void finalizar();

    double calcularCostoTotal() const;

    void mostrar() const;

    std::string guardar() const;
};

#endif