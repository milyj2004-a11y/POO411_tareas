#include "SistemaAlquiler.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

SistemaAlquiler::SistemaAlquiler()
    : siguienteCodigoAlquiler(1)
{
    cargarClientes();
    cargarVehiculos();
    cargarAlquileres();
}

void SistemaAlquiler::mostrarMenu() const
{
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "      SISTEMA DE ALQUILER DE VEHICULOS\n";
    std::cout << "========================================\n";
    std::cout << "1. Registrar un cliente\n";
    std::cout << "2. Registrar un automovil\n";
    std::cout << "3. Registrar una motocicleta\n";
    std::cout << "4. Ver clientes\n";
    std::cout << "5. Ver vehiculos\n";
    std::cout << "6. Registrar un alquiler\n";
    std::cout << "7. Registrar una devolucion\n";
    std::cout << "8. Ver alquileres activos\n";
    std::cout << "9. Ver historial de alquileres\n";
    std::cout << "10. Guardar los datos y salir\n";
    std::cout << "========================================\n";
}


void SistemaAlquiler::ejecutar()
{
    int opcion = 0;

    do
    {
        mostrarMenu();

        opcion = leerEnteroPositivo("Seleccione una opcion: ");

        switch(opcion)
        {
        case 1:
            registrarCliente();
            break;

        case 2:
            registrarAutomovil();
            break;

        case 3:
            registrarMotocicleta();
            break;

        case 4:
            verClientes();
            break;

        case 5:
            verVehiculos();
            break;

        case 6:
            registrarAlquiler();
            break;

        case 7:
            registrarDevolucion();
            break;

        case 8:
            verAlquileresActivos();
            break;

        case 9:
            verHistorialAlquileres();
            break;

        case 10:
            guardarClientes();
            guardarVehiculos();
            guardarAlquileres();

            std::cout << "Datos guardados correctamente.\n";
            std::cout << "Programa finalizado.\n";
            break;

        default:
            std::cout << "Opcion invalida.\n";
            break;
        }

    } while(opcion != 10);
}


int SistemaAlquiler::leerEnteroPositivo(
    const std::string& mensaje) const
{
    int valor = 0;

    while(true)
    {
        std::cout << mensaje;

        if(std::cin >> valor && valor > 0)
        {
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n');

            return valor;
        }

        std::cout << "Error: debe introducir un numero positivo.\n";

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n');
    }
}


double SistemaAlquiler::leerDoublePositivo(
    const std::string& mensaje) const
{
    double valor = 0.0;

    while(true)
    {
        std::cout << mensaje;

        if(std::cin >> valor && valor > 0.0)
        {
            std::cin.ignore(
                std::numeric_limits<std::streamsize>::max(),
                '\n');

            return valor;
        }

        std::cout << "Error: debe introducir un valor positivo.\n";

        std::cin.clear();

        std::cin.ignore(
            std::numeric_limits<std::streamsize>::max(),
            '\n');
    }
}


std::string SistemaAlquiler::leerTextoObligatorio(
    const std::string& mensaje) const
{
    std::string texto;

    while(true)
    {
        std::cout << mensaje;
        std::getline(std::cin, texto);

        if(!texto.empty())
        {
            return texto;
        }

        std::cout << "Error: este campo no puede estar vacio.\n";
    }
}


Cliente* SistemaAlquiler::buscarCliente(
    const std::string& documento)
{
    for(Cliente& cliente : clientes)
    {
        if(cliente.getDocumento() == documento)
        {
            return &cliente;
        }
    }

    return nullptr;
}

Vehiculo* SistemaAlquiler::buscarVehiculo(
    const std::string& matricula)
{
    for(const std::unique_ptr<Vehiculo>& vehiculo : vehiculos)
    {
        if(vehiculo->getMatricula() == matricula)
        {
            return vehiculo.get();
        }
    }

    return nullptr;
}


const Vehiculo* SistemaAlquiler::buscarVehiculo(
    const std::string& matricula) const
{
    for(const std::unique_ptr<Vehiculo>& vehiculo : vehiculos)
    {
        if(vehiculo->getMatricula() == matricula)
        {
            return vehiculo.get();
        }
    }

    return nullptr;
}


Alquiler* SistemaAlquiler::buscarAlquiler(int codigo)
{
    for(Alquiler& alquiler : alquileres)
    {
        if(alquiler.getCodigo() == codigo)
        {
            return &alquiler;
        }
    }

    return nullptr;
}


const Alquiler* SistemaAlquiler::buscarAlquiler(
    int codigo) const
{
    for(const Alquiler& alquiler : alquileres)
    {
        if(alquiler.getCodigo() == codigo)
        {
            return &alquiler;
        }
    }

    return nullptr;
}

void SistemaAlquiler::registrarCliente()
{
    std::cout << "\n===== REGISTRAR CLIENTE =====\n";

    std::string documento = leerTextoObligatorio(
        "Documento de identidad: ");

    if(buscarCliente(documento) != nullptr)
    {
        std::cout << "Error: ya existe un cliente con ese documento.\n";
        return;
    }

    std::string nombre = leerTextoObligatorio(
        "Nombre completo: ");

    std::string telefono = leerTextoObligatorio(
        "Numero telefonico: ");

    clientes.emplace_back(
        documento,
        nombre,
        telefono
    );

    std::cout << "Cliente registrado correctamente.\n";
}


void SistemaAlquiler::registrarAutomovil()
{
    std::cout << "\n===== REGISTRAR AUTOMOVIL =====\n";

    std::string matricula = leerTextoObligatorio(
        "Matricula: ");

    if(buscarVehiculo(matricula) != nullptr)
    {
        std::cout << "Error: ya existe un vehiculo con esa matricula.\n";
        return;
    }

    std::string marca = leerTextoObligatorio(
        "Marca: ");

    std::string modelo = leerTextoObligatorio(
        "Modelo: ");

    int anio = leerEnteroPositivo(
        "Anio: ");

    double tarifa = leerDoublePositivo(
        "Tarifa diaria: ");

    int puertas = leerEnteroPositivo(
        "Cantidad de puertas: ");

    vehiculos.push_back(
        std::make_unique<Automovil>(
            matricula,
            marca,
            modelo,
            anio,
            tarifa,
            puertas
        )
    );

    std::cout << "Automovil registrado correctamente.\n";
}


void SistemaAlquiler::registrarMotocicleta()
{
    std::cout << "\n===== REGISTRAR MOTOCICLETA =====\n";

    std::string matricula = leerTextoObligatorio(
        "Matricula: ");

    if(buscarVehiculo(matricula) != nullptr)
    {
        std::cout << "Error: ya existe un vehiculo con esa matricula.\n";
        return;
    }

    std::string marca = leerTextoObligatorio(
        "Marca: ");

    std::string modelo = leerTextoObligatorio(
        "Modelo: ");

    int anio = leerEnteroPositivo(
        "Anio: ");

    double tarifa = leerDoublePositivo(
        "Tarifa diaria: ");

    int cilindrada = leerEnteroPositivo(
        "Cilindrada (cc): ");

    vehiculos.push_back(
        std::make_unique<Motocicleta>(
            matricula,
            marca,
            modelo,
            anio,
            tarifa,
            cilindrada
        )
    );

    std::cout << "Motocicleta registrada correctamente.\n";
}


void SistemaAlquiler::verClientes() const
{
    std::cout << "\n================ CLIENTES ================\n";

    if(clientes.empty())
    {
        std::cout << "No hay clientes registrados.\n";
        return;
    }

    std::cout
        << std::left
        << std::setw(20) << "DOCUMENTO"
        << std::setw(30) << "NOMBRE"
        << std::setw(20) << "TELEFONO"
        << '\n';

    std::cout << "--------------------------------------------------------------\n";

    for(const Cliente& cliente : clientes)
    {
        std::cout
            << std::left
            << std::setw(20) << cliente.getDocumento()
            << std::setw(30) << cliente.getNombre()
            << std::setw(20) << cliente.getTelefono()
            << '\n';
    }
}

void SistemaAlquiler::verVehiculos() const
{
    std::cout << "\n================ VEHICULOS ================\n";

    if(vehiculos.empty())
    {
        std::cout << "No hay vehiculos registrados.\n";
        return;
    }

    std::cout
        << std::left
        << std::setw(15) << "TIPO"
        << std::setw(15) << "MATRICULA"
        << std::setw(15) << "MARCA"
        << std::setw(15) << "MODELO"
        << std::setw(8) << "ANIO"
        << std::setw(15) << "TARIFA"
        << std::setw(20) << "ESTADO"
        << '\n';

    std::cout << "--------------------------------------------------------------------------------\n";

    for(const std::unique_ptr<Vehiculo>& vehiculo : vehiculos)
    {
        std::cout
            << std::left
            << std::setw(15) << vehiculo->obtenerTipo()
            << std::setw(15) << vehiculo->getMatricula()
            << std::setw(15) << vehiculo->getMarca()
            << std::setw(15) << vehiculo->getModelo()
            << std::setw(8) << vehiculo->getAnio()
            << std::setw(15)
            << std::fixed
            << std::setprecision(2)
            << vehiculo->calcularTarifaDiaria()
            << std::setw(20)
            << (vehiculo->estaDisponible()
                ? "Disponible"
                : "No disponible")
            << '\n';
    }
}



int SistemaAlquiler::contarAlquileresActivos(
    const std::string& documento) const
{
    int cantidad = 0;

    for(const Alquiler& alquiler : alquileres)
    {
        if(alquiler.getDocumentoCliente() == documento &&
           alquiler.estaActivo())
        {
            cantidad++;
        }
    }

    return cantidad;
}

void SistemaAlquiler::registrarAlquiler()
{
    std::cout << "\n===== REGISTRAR ALQUILER =====\n";

    std::string documento = leerTextoObligatorio(
        "Documento del cliente: ");

    Cliente* cliente = buscarCliente(documento);

    if(cliente == nullptr)
    {
        std::cout << "Error: el cliente no existe.\n";
        return;
    }

    int alquileresActivos = contarAlquileresActivos(documento);

    if(alquileresActivos >= 2)
    {
        std::cout
            << "Error: el cliente ya tiene "
            << "el maximo de 2 alquileres activos.\n";

        return;
    }

    std::string matricula = leerTextoObligatorio(
        "Matricula del vehiculo: ");

    Vehiculo* vehiculo = buscarVehiculo(matricula);

    if(vehiculo == nullptr)
    {
        std::cout << "Error: el vehiculo no existe.\n";
        return;
    }

    if(!vehiculo->estaDisponible())
    {
        std::cout
            << "Error: el vehiculo no esta disponible.\n";

        return;
    }

    std::string fecha = leerTextoObligatorio(
        "Fecha de inicio: ");

    int dias = leerEnteroPositivo(
        "Cantidad de dias: ");

    double tarifa = vehiculo->calcularTarifaDiaria();

    int codigo = siguienteCodigoAlquiler;

    Alquiler nuevoAlquiler(
        codigo,
        documento,
        matricula,
        fecha,
        dias,
        tarifa
    );

    alquileres.push_back(nuevoAlquiler);

    vehiculo->alquilar();

    siguienteCodigoAlquiler++;

    std::cout << "\nAlquiler registrado correctamente.\n";
    std::cout << "Codigo del alquiler: " << codigo << '\n';
    std::cout << "Tarifa diaria aplicada: "
              << std::fixed
              << std::setprecision(2)
              << tarifa << '\n';
    std::cout << "Costo acordado: "
              << std::fixed
              << std::setprecision(2)
              << nuevoAlquiler.calcularCostoTotal()
              << '\n';
}


void SistemaAlquiler::registrarDevolucion()
{
    std::cout << "\n===== REGISTRAR DEVOLUCION =====\n";

    int codigo = leerEnteroPositivo(
        "Codigo del alquiler: ");

    Alquiler* alquiler = buscarAlquiler(codigo);

    if(alquiler == nullptr)
    {
        std::cout << "Error: el alquiler no existe.\n";
        return;
    }

    if(!alquiler->estaActivo())
    {
        std::cout
            << "Error: este alquiler ya fue finalizado.\n";

        return;
    }

    Vehiculo* vehiculo = buscarVehiculo(
        alquiler->getMatriculaVehiculo());

    if(vehiculo == nullptr)
    {
        std::cout
            << "Error: no se encontro el vehiculo asociado.\n";

        return;
    }

    double costoTotal = alquiler->calcularCostoTotal();

    alquiler->finalizar();

    vehiculo->devolver();

    std::cout << "\nDevolucion registrada correctamente.\n";

    std::cout
        << "Codigo del alquiler: "
        << alquiler->getCodigo()
        << '\n';

    std::cout
        << "Costo total del alquiler: $"
        << std::fixed
        << std::setprecision(2)
        << costoTotal
        << '\n';

    std::cout
        << "El vehiculo vuelve a estar disponible.\n";
}

void SistemaAlquiler::verAlquileresActivos() const
{
    std::cout << "\n================ ALQUILERES ACTIVOS ================\n";

    bool hayActivos = false;

    std::cout
        << std::left
        << std::setw(8) << "CODIGO"
        << std::setw(18) << "CLIENTE"
        << std::setw(18) << "MATRICULA"
        << std::setw(15) << "FECHA"
        << std::setw(8) << "DIAS"
        << std::setw(15) << "TARIFA"
        << '\n';

    std::cout
        << "--------------------------------------------------------------------------\n";

    for(const Alquiler& alquiler : alquileres)
    {
        if(alquiler.estaActivo())
        {
            hayActivos = true;

            std::cout
                << std::left
                << std::setw(8) << alquiler.getCodigo()
                << std::setw(18)
                << alquiler.getDocumentoCliente()
                << std::setw(18)
                << alquiler.getMatriculaVehiculo()
                << std::setw(15)
                << alquiler.getFechaInicio()
                << std::setw(8)
                << alquiler.getDias()
                << std::setw(15)
                << std::fixed
                << std::setprecision(2)
                << alquiler.getTarifaDiaria()
                << '\n';
        }
    }

    if(!hayActivos)
    {
        std::cout << "No hay alquileres activos.\n";
    }
}


void SistemaAlquiler::verHistorialAlquileres() const
{
    std::cout << "\n================ HISTORIAL DE ALQUILERES ================\n";

    if(alquileres.empty())
    {
        std::cout << "No hay alquileres registrados.\n";
        return;
    }

    std::cout
        << std::left
        << std::setw(8) << "CODIGO"
        << std::setw(18) << "CLIENTE"
        << std::setw(18) << "MATRICULA"
        << std::setw(15) << "FECHA"
        << std::setw(8) << "DIAS"
        << std::setw(15) << "TARIFA"
        << std::setw(15) << "ESTADO"
        << '\n';

    std::cout
        << "--------------------------------------------------------------------------------\n";

    for(const Alquiler& alquiler : alquileres)
    {
        std::cout
            << std::left
            << std::setw(8)
            << alquiler.getCodigo()
            << std::setw(18)
            << alquiler.getDocumentoCliente()
            << std::setw(18)
            << alquiler.getMatriculaVehiculo()
            << std::setw(15)
            << alquiler.getFechaInicio()
            << std::setw(8)
            << alquiler.getDias()
            << std::setw(15)
            << std::fixed
            << std::setprecision(2)
            << alquiler.getTarifaDiaria()
            << std::setw(15)
            << (alquiler.estaActivo()
                ? "Activo"
                : "Finalizado")
            << '\n';
    }
}

void SistemaAlquiler::guardarClientes() const
{
    std::ofstream archivo("clientes.txt");

    if(!archivo)
    {
        std::cout << "Error al abrir clientes.txt para guardar.\n";
        return;
    }

    for(const Cliente& cliente : clientes)
    {
        archivo << cliente.guardar() << '\n';
    }
}


void SistemaAlquiler::guardarVehiculos() const
{
    std::ofstream archivo("vehiculos.txt");

    if(!archivo)
    {
        std::cout << "Error al abrir vehiculos.txt para guardar.\n";
        return;
    }

    for(const std::unique_ptr<Vehiculo>& vehiculo : vehiculos)
    {
        archivo << vehiculo->guardar() << '\n';
    }
}


void SistemaAlquiler::guardarAlquileres() const
{
    std::ofstream archivo("alquileres.txt");

    if(!archivo)
    {
        std::cout << "Error al abrir alquileres.txt para guardar.\n";
        return;
    }

    for(const Alquiler& alquiler : alquileres)
    {
        archivo << alquiler.guardar() << '\n';
    }
}



void SistemaAlquiler::cargarClientes()
{
    std::ifstream archivo("clientes.txt");

    if(!archivo)
    {
        return;
    }

    std::string linea;

    while(std::getline(archivo, linea))
    {
        if(linea.empty())
        {
            continue;
        }

        std::stringstream ss(linea);

        std::string documento;
        std::string nombre;
        std::string telefono;

        std::getline(ss, documento, ';');
        std::getline(ss, nombre, ';');
        std::getline(ss, telefono);

        if(!documento.empty() && !nombre.empty())
        {
            clientes.emplace_back(
                documento,
                nombre,
                telefono
            );
        }
    }
}



void SistemaAlquiler::cargarVehiculos()
{
    std::ifstream archivo("vehiculos.txt");

    if(!archivo)
    {
        return;
    }

    std::string linea;

    while(std::getline(archivo, linea))
    {
        if(linea.empty())
        {
            continue;
        }

        std::stringstream ss(linea);

        std::string tipo;
        std::string matricula;
        std::string marca;
        std::string modelo;
        std::string anioTexto;
        std::string tarifaTexto;
        std::string disponibleTexto;
        std::string datoEspecifico;

        std::getline(ss, tipo, ';');
        std::getline(ss, matricula, ';');
        std::getline(ss, marca, ';');
        std::getline(ss, modelo, ';');
        std::getline(ss, anioTexto, ';');
        std::getline(ss, tarifaTexto, ';');
        std::getline(ss, disponibleTexto, ';');
        std::getline(ss, datoEspecifico);

        int anio = std::stoi(anioTexto);
        double tarifa = std::stod(tarifaTexto);
        bool disponible = std::stoi(disponibleTexto) != 0;

        if(tipo == "Automovil")
        {
            int puertas = std::stoi(datoEspecifico);

            vehiculos.push_back(
                std::make_unique<Automovil>(
                    matricula,
                    marca,
                    modelo,
                    anio,
                    tarifa,
                    puertas,
                    disponible
                )
            );
        }
        else if(tipo == "Motocicleta")
        {
            int cilindrada = std::stoi(datoEspecifico);

            vehiculos.push_back(
                std::make_unique<Motocicleta>(
                    matricula,
                    marca,
                    modelo,
                    anio,
                    tarifa,
                    cilindrada,
                    disponible
                )
            );
        }
    }
}


void SistemaAlquiler::cargarAlquileres()
{
    std::ifstream archivo("alquileres.txt");

    if(!archivo)
    {
        return;
    }

    std::string linea;

    while(std::getline(archivo, linea))
    {
        if(linea.empty())
        {
            continue;
        }

        std::stringstream ss(linea);

        std::string codigoTexto;
        std::string documento;
        std::string matricula;
        std::string fecha;
        std::string diasTexto;
        std::string tarifaTexto;
        std::string activoTexto;

        std::getline(ss, codigoTexto, ';');
        std::getline(ss, documento, ';');
        std::getline(ss, matricula, ';');
        std::getline(ss, fecha, ';');
        std::getline(ss, diasTexto, ';');
        std::getline(ss, tarifaTexto, ';');
        std::getline(ss, activoTexto);

        int codigo = std::stoi(codigoTexto);
        int dias = std::stoi(diasTexto);
        double tarifa = std::stod(tarifaTexto);
        bool activo = std::stoi(activoTexto) != 0;

        alquileres.emplace_back(
            codigo,
            documento,
            matricula,
            fecha,
            dias,
            tarifa,
            activo
        );

        if(codigo >= siguienteCodigoAlquiler)
        {
            siguienteCodigoAlquiler = codigo + 1;
        }
    }
}