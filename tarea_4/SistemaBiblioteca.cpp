#include "SistemaBiblioteca.h"

#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>

SistemaBiblioteca::SistemaBiblioteca()
{
    siguienteUsuario = 1;
    siguienteMaterial = 100;

    cargarUsuarios();
    cargarMateriales();
    cargarPrestamos();
}

SistemaBiblioteca::~SistemaBiblioteca()
{
    guardarUsuarios();
    guardarMateriales();
    guardarPrestamos();
}

void SistemaBiblioteca::menu() const
{
    std::cout << "\n========== BIBLIOTECA ==========\n";
    std::cout << "1. Registrar usuario\n";
    std::cout << "2. Registrar libro\n";
    std::cout << "3. Registrar revista\n";
    std::cout << "4. Mostrar usuarios\n";
    std::cout << "5. Mostrar materiales\n";
    std::cout << "6. Realizar prestamo\n";
    std::cout << "7. Devolver material\n";
    std::cout << "8. Mostrar prestamos\n";
    std::cout << "9. Salir\n";
}

void SistemaBiblioteca::ejecutar()
{
    int opcion;

    do
    {
        menu();

        std::cout << "\nOpcion: ";
        std::cin >> opcion;

        switch(opcion)
        {
        case 1:
            registrarUsuario();
            break;

        case 2:
            registrarLibro();
            break;

        case 3:
            registrarRevista();
            break;

        case 4:
            mostrarUsuarios();
            break;

        case 5:
            mostrarMateriales();
            break;

        case 6:
            realizarPrestamo();
            break;

        case 7:
            devolverMaterial();
            break;

        case 8:
            mostrarPrestamos();
            break;

        case 9:
            std::cout << "Hasta luego.\n";
            break;

        default:
            std::cout << "Opcion invalida.\n";
        }

    } while(opcion != 9);
}


void SistemaBiblioteca::registrarUsuario()
{
    std::string nombre;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);

    usuarios.emplace_back(siguienteUsuario, nombre);

    siguienteUsuario++;

    std::cout << "Usuario registrado correctamente.\n";
}


void SistemaBiblioteca::registrarLibro()
{
    std::string titulo;
    std::string autor;
    int paginas;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Titulo: ";
    std::getline(std::cin, titulo);

    std::cout << "Autor: ";
    std::getline(std::cin, autor);

    std::cout << "Paginas: ";
    std::cin >> paginas;

    materiales.push_back(
        std::make_shared<Libro>(
            siguienteMaterial,
            titulo,
            autor,
            paginas
        )
    );

    siguienteMaterial++;

    std::cout << "Libro registrado correctamente.\n";
}


void SistemaBiblioteca::registrarRevista()
{
    std::string titulo;
    std::string mes;
    int edicion;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Titulo: ";
    std::getline(std::cin, titulo);

    std::cout << "Numero de edicion: ";
    std::cin >> edicion;

    std::cin.ignore();

    std::cout << "Mes: ";
    std::getline(std::cin, mes);

    materiales.push_back(
        std::make_shared<Revista>(
            siguienteMaterial,
            titulo,
            edicion,
            mes
        )
    );

    siguienteMaterial++;

    std::cout << "Revista registrada correctamente.\n";
}



void SistemaBiblioteca::mostrarUsuarios() const
{
    if(usuarios.empty())
    {
        std::cout << "No hay usuarios registrados.\n";
        return;
    }

    for(const Usuario& usuario : usuarios)
    {
        usuario.mostrar();
    }
}


void SistemaBiblioteca::mostrarMateriales() const
{
    if(materiales.empty())
    {
        std::cout << "No hay materiales registrados.\n";
        return;
    }

    for(const auto& material : materiales)
    {
        material->mostrar();
    }
}

int SistemaBiblioteca::contarPrestamos(int codigoUsuario) const
{
    int cantidad = 0;

    for(const Prestamo& prestamo : prestamos)
    {
        if(prestamo.getCodigoUsuario() == codigoUsuario &&
           prestamo.estaActivo())
        {
            cantidad++;
        }
    }

    return cantidad;
}
void SistemaBiblioteca::realizarPrestamo()
{
    int codigoUsuario;
    int codigoMaterial;
    std::string fecha;

    std::cout << "Codigo del usuario: ";
    std::cin >> codigoUsuario;

    bool usuarioExiste = false;

    for(const Usuario& usuario : usuarios)
    {
        if(usuario.getCodigo() == codigoUsuario)
        {
            usuarioExiste = true;
            break;
        }
    }

    if(!usuarioExiste)
    {
        std::cout << "Usuario no encontrado.\n";
        return;
    }


    if(contarPrestamos(codigoUsuario) >= 3)
    {
        std::cout << "El usuario ya tiene 3 prestamos activos.\n";
        return;
    }


    std::cout << "Codigo del material: ";
    std::cin >> codigoMaterial;


    for(auto& material : materiales)
    {
        if(material->getCodigo() == codigoMaterial)
        {

            if(!material->estaDisponible())
            {
                std::cout << "El material no esta disponible.\n";
                return;
            }


            std::cout << "Fecha del prestamo: ";
            std::cin >> fecha;


            material->prestar();


            prestamos.emplace_back(
                codigoUsuario,
                codigoMaterial,
                fecha
            );


            std::cout << "Prestamo realizado correctamente.\n";
            return;
        }
    }


    std::cout << "Material no encontrado.\n";
}


void SistemaBiblioteca::devolverMaterial()
{
    int codigoMaterial;

    std::cout << "Codigo del material: ";
    std::cin >> codigoMaterial;


    for(Prestamo& prestamo : prestamos)
    {
        if(prestamo.getCodigoMaterial() == codigoMaterial &&
           prestamo.estaActivo())
        {

            prestamo.devolver();


            for(auto& material : materiales)
            {
                if(material->getCodigo() == codigoMaterial)
                {
                    material->devolver();
                    break;
                }
            }


            std::cout << "Material devuelto correctamente.\n";
            return;
        }
    }


    std::cout << "No existe un prestamo activo para ese material.\n";
}

void SistemaBiblioteca::mostrarPrestamos() const
{
    if(prestamos.empty())
    {
        std::cout << "No hay prestamos registrados.\n";
        return;
    }

    for(const Prestamo& prestamo : prestamos)
    {
        prestamo.mostrar();
    }
}
void SistemaBiblioteca::guardarUsuarios()
{
    std::ofstream archivo("usuarios.txt");

    if(!archivo)
    {
        std::cout << "No se pudo guardar usuarios.\n";
        return;
    }

    for(const Usuario& usuario : usuarios)
    {
        archivo << usuario.guardar() << '\n';
    }
}

void SistemaBiblioteca::guardarMateriales()
{
    std::ofstream archivo("materiales.txt");

    if(!archivo)
    {
        std::cout << "No se pudo guardar materiales.\n";
        return;
    }

    for(const auto& material : materiales)
    {
        archivo << material->guardar() << '\n';
    }
}

void SistemaBiblioteca::guardarPrestamos()
{
    std::ofstream archivo("prestamos.txt");

    if(!archivo)
    {
        std::cout << "No se pudo guardar prestamos.\n";
        return;
    }

    for(const Prestamo& prestamo : prestamos)
    {
        archivo << prestamo.guardar() << '\n';
    }
}

void SistemaBiblioteca::cargarUsuarios()
{
    std::ifstream archivo("usuarios.txt");

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
        std::string nombre;

        std::getline(ss, codigoTexto, ';');
        std::getline(ss, nombre);

        int codigo = std::stoi(codigoTexto);

        usuarios.emplace_back(codigo, nombre);

        if(codigo >= siguienteUsuario)
        {
            siguienteUsuario = codigo + 1;
        }
    }
}

void SistemaBiblioteca::cargarMateriales()
{
    std::ifstream archivo("materiales.txt");

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
        std::string codigoTexto;
        std::string titulo;
        std::string disponibleTexto;

        std::getline(ss, tipo, ';');
        std::getline(ss, codigoTexto, ';');
        std::getline(ss, titulo, ';');
        std::getline(ss, disponibleTexto, ';');

        int codigo = std::stoi(codigoTexto);
        bool disponible = std::stoi(disponibleTexto) != 0;

        if(tipo == "LIBRO")
        {
            std::string autor;
            std::string paginasTexto;

            std::getline(ss, autor, ';');
            std::getline(ss, paginasTexto);

            int paginas = std::stoi(paginasTexto);

            auto libro = std::make_shared<Libro>(
                codigo,
                titulo,
                autor,
                paginas,
                disponible
            );

            materiales.push_back(libro);
        }
        else if(tipo == "REVISTA")
        {
            std::string edicionTexto;
            std::string mes;

            std::getline(ss, edicionTexto, ';');
            std::getline(ss, mes);

            int edicion = std::stoi(edicionTexto);

            auto revista = std::make_shared<Revista>(
                codigo,
                titulo,
                edicion,
                mes,
                disponible
            );

            materiales.push_back(revista);
        }

        if(codigo >= siguienteMaterial)
        {
            siguienteMaterial = codigo + 1;
        }
    }
}

void SistemaBiblioteca::cargarPrestamos()
{
    std::ifstream archivo("prestamos.txt");

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

        std::string usuarioTexto;
        std::string materialTexto;
        std::string fecha;
        std::string activoTexto;

        std::getline(ss, usuarioTexto, ';');
        std::getline(ss, materialTexto, ';');
        std::getline(ss, fecha, ';');
        std::getline(ss, activoTexto);

        int codigoUsuario = std::stoi(usuarioTexto);
        int codigoMaterial = std::stoi(materialTexto);
        bool activo = std::stoi(activoTexto) != 0;

        prestamos.emplace_back(
            codigoUsuario,
            codigoMaterial,
            fecha,
            activo
        );

        if(activo)
        {
            for(auto& material : materiales)
            {
                if(material->getCodigo() == codigoMaterial)
                {
                    material->setDisponible(false);
                    break;
                }
            }
        }
    }
} 

