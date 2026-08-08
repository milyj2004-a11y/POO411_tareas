#ifndef SISTEMAALQUILER_H
#define SISTEMAALQUILER_H

#include <memory>
#include <string>
#include <vector>

#include "Alquiler.h"
#include "Automovil.h"
#include "Cliente.h"
#include "Motocicleta.h"
#include "Vehiculo.h"

class SistemaAlquiler
{
private:
    std::vector<Cliente> clientes;

    std::vector<std::unique_ptr<Vehiculo>> vehiculos;

    std::vector<Alquiler> alquileres;

    int siguienteCodigoAlquiler;

    void mostrarMenu() const;

    void registrarCliente();
    void registrarAutomovil();
    void registrarMotocicleta();

    void verClientes() const;
    void verVehiculos() const;

    void registrarAlquiler();
    void registrarDevolucion();

    void verAlquileresActivos() const;
    void verHistorialAlquileres() const;

    int leerEnteroPositivo(const std::string& mensaje) const;
    double leerDoublePositivo(const std::string& mensaje) const;
    std::string leerTextoObligatorio(const std::string& mensaje) const;

    Cliente* buscarCliente(const std::string& documento);
    const Cliente* buscarCliente(const std::string& documento) const;

    Vehiculo* buscarVehiculo(const std::string& matricula);
    const Vehiculo* buscarVehiculo(const std::string& matricula) const;

    Alquiler* buscarAlquiler(int codigo);
    const Alquiler* buscarAlquiler(int codigo) const;

    int contarAlquileresActivos(
        const std::string& documento) const;

    void guardarClientes() const;
    void guardarVehiculos() const;
    void guardarAlquileres() const;

    void cargarClientes();
    void cargarVehiculos();
    void cargarAlquileres();

public:
    SistemaAlquiler();

    void ejecutar();
};

#endif