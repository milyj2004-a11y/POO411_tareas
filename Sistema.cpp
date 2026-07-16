#include "Sistema.h"

#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

Sistema::Sistema() {
}

int Sistema::mostrarMenu() const {
    int opcion;

    std::cout << "\n===== SISTEMA DE REGISTRO =====\n";
    std::cout << "1. Registrar estudiante\n";
    std::cout << "2. Registrar profesor\n";
    std::cout << "3. Registrar materia\n";
    std::cout << "4. Registrar calificacion\n";
    std::cout << "5. Ver estudiantes\n";
    std::cout << "6. Ver profesores\n";
    std::cout << "7. Ver materias\n";
    std::cout << "8. Ver calificaciones\n";
    std::cout << "9. Salir\n";
    std::cout << "Opcion: ";

    std::cin >> opcion;

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return opcion;
}

void Sistema::registrarEstudiante() {
    std::string nombre;
    std::string matricula;
    std::string sesion;

    do {
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);

        if (nombre.empty()) {
            std::cout << "Nombre invalido.\n";
        }

    } while (nombre.empty());

    std::cout << "Matricula: ";
    std::getline(std::cin, matricula);

    std::cout << "Sesion: ";
    std::getline(std::cin, sesion);

    agregar(
        Estudiante(nombre, matricula, sesion)
    );
}

void Sistema::registrarProfesor() {
    std::string nombre;
    std::string codigo;

    do {
        std::cout << "Nombre: ";
        std::getline(std::cin, nombre);

        if (nombre.empty()) {
            std::cout << "Nombre invalido.\n";
        }

    } while (nombre.empty());

    do {
        std::cout << "Codigo: ";
        std::getline(std::cin, codigo);

        if (codigo.empty()) {
            std::cout << "Codigo invalido.\n";
        }

    } while (codigo.empty());

    agregar(
        Profesor(nombre, codigo)
    );
}

void Sistema::registrarMateria() {
    std::string nombre;
    std::string codigo;
    int creditos;

    do {
        std::cout << "Nombre materia: ";
        std::getline(std::cin, nombre);

        if (nombre.empty()) {
            std::cout << "Nombre invalido.\n";
        }

    } while (nombre.empty());

    do {
        std::cout << "Codigo materia: ";
        std::getline(std::cin, codigo);

        if (codigo.empty()) {
            std::cout << "Codigo invalido.\n";
        }

    } while (codigo.empty());

    do {
        std::cout << "Creditos: ";
        std::cin >> creditos;

        if (creditos <= 0) {
            std::cout << "Cantidad invalida.\n";
        }

    } while (creditos <= 0);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    agregar(
        Materia(nombre, codigo, creditos)
    );
}
void Sistema::agregar(const Estudiante& estudiante) {
    estudiantes.push_back(estudiante);
}

void Sistema::agregar(const Profesor& profesor) {
    profesores.push_back(profesor);
}

void Sistema::agregar(const Materia& materia) {
    materias.push_back(materia);
}

void Sistema::registrarCalificacion() {
    if (estudiantes.empty() ||
        profesores.empty() ||
        materias.empty()) {

        std::cout << "Debe registrar estudiantes, profesores y materias primero.\n";
        return;
    }

    int estudianteIndex;
    int profesorIndex;
    int materiaIndex;
    double nota;

    for (std::size_t i = 0; i < estudiantes.size(); i++) {
        std::cout << i + 1 << ". "
                  << estudiantes[i].getNombreCompleto()
                  << '\n';
    }

    do {
        std::cout << "Seleccione estudiante: ";
        std::cin >> estudianteIndex;

        if (estudianteIndex < 1 ||
            estudianteIndex > static_cast<int>(estudiantes.size())) {

            std::cout << "Opcion invalida.\n";
        }

    } while (estudianteIndex < 1 ||
             estudianteIndex > static_cast<int>(estudiantes.size()));

    while (estudianteIndex < 1 ||
           estudianteIndex > static_cast<int>(estudiantes.size())) {

        std::cout << "Seleccione estudiante valido: ";
        std::cin >> estudianteIndex;
    }

    for (std::size_t i = 0; i < profesores.size(); i++) {
        std::cout << i + 1 << ". "
                  << profesores[i].getNombreCompleto()
                  << '\n';
    }

    std::cout << "Seleccione profesor: ";
    std::cin >> profesorIndex;

    while (profesorIndex < 1 ||
           profesorIndex > static_cast<int>(profesores.size())) {

               do {
                   std::cout << "Seleccione profesor: ";
                   std::cin >> profesorIndex;

                   if (profesorIndex < 1 ||
                       profesorIndex > static_cast<int>(profesores.size())) {

                       std::cout << "Opcion invalida.\n";
                   }

               } while (profesorIndex < 1 ||
                        profesorIndex > static_cast<int>(profesores.size()));
    }

    for (std::size_t i = 0; i < materias.size(); i++) {
        std::cout << i + 1 << ". "
                  << materias[i].getNombreMateria()
                  << '\n';
    }

    do {
        std::cout << "Seleccione materia: ";
        std::cin >> materiaIndex;

        if (materiaIndex < 1 ||
            materiaIndex > static_cast<int>(materias.size())) {

            std::cout << "Opcion invalida.\n";
        }

    } while (materiaIndex < 1 ||
             materiaIndex > static_cast<int>(materias.size()));

    while (materiaIndex < 1 ||
           materiaIndex > static_cast<int>(materias.size())) {

        std::cout << "Seleccione materia valida: ";
        std::cin >> materiaIndex;
    }

    do {
        std::cout << "Nota (0-100): ";
        std::cin >> nota;

        if (nota < 0 || nota > 100) {
            std::cout << "Nota invalida.\n";
        }

    } while (nota < 0 || nota > 100);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    calificaciones.push_back(
        Calificacion(
            estudiantes[estudianteIndex - 1],
            profesores[profesorIndex - 1],
            materias[materiaIndex - 1],
            nota
        )
    );
}

void Sistema::verEstudiantes() const {
    std::cout << "\nESTUDIANTES\n\n";

    std::cout
        << std::left
        << std::setw(35) << "Nombre"
        << std::setw(15) << "Matricula"
        << std::setw(15) << "Sesion"
        << '\n';

    for (const Estudiante& e : estudiantes) {
        std::cout
            << std::setw(35) << e.getNombreCompleto()
            << std::setw(15) << e.getMatricula()
            << std::setw(15) << e.getSesion()
            << '\n';
    }
}


void Sistema::verProfesores() const {
    std::cout << "\nPROFESORES\n";

    for (const Profesor& p : profesores) {
        std::cout
            << p.getNombreCompleto() << " | "
            << p.getCodigoProfesor() << '\n';
    }
}

void Sistema::verMaterias() const {
    std::cout << "\nMATERIAS\n";

    for (const Materia& m : materias) {
        std::cout
            << m.getNombreMateria() << " | "
            << m.getCodigoMateria() << " | "
            << m.getCantidadCreditos() << '\n';
    }
}

void Sistema::verCalificaciones() const {
    std::cout << "\nCALIFICACIONES\n";

    for (const Calificacion& c : calificaciones) {
        std::cout
            << c.getEstudiante().getNombreCompleto() << " | "
            << c.getProfesor().getNombreCompleto() << " | "
            << c.getMateria().getNombreMateria() << " | "
            << c.getNota() << '\n';
    }
}

void Sistema::cargarDatos() {
    std::string linea;

    std::ifstream archivoEstudiantes("estudiantes.txt");

    if (archivoEstudiantes.is_open()) {
        while (std::getline(archivoEstudiantes, linea)) {
            std::stringstream ss(linea);

            std::string nombre;
            std::string matricula;
            std::string sesion;

            std::getline(ss, nombre, '|');
            std::getline(ss, matricula, '|');
            std::getline(ss, sesion, '|');

            estudiantes.push_back(
                Estudiante(nombre, matricula, sesion)
            );
        }

        archivoEstudiantes.close();


    }

    std::ifstream archivoProfesores("profesores.txt");

    if (archivoProfesores.is_open()) {
        while (std::getline(archivoProfesores, linea)) {
            std::stringstream ss(linea);

            std::string nombre;
            std::string codigo;

            std::getline(ss, nombre, '|');
            std::getline(ss, codigo, '|');

            profesores.push_back(
                Profesor(nombre, codigo)
            );
        }

        archivoProfesores.close();
    }

    std::ifstream archivoMaterias("materias.txt");

    if (archivoMaterias.is_open()) {
        while (std::getline(archivoMaterias, linea)) {
            std::stringstream ss(linea);

            std::string nombre;
            std::string codigo;
            std::string creditosTexto;

            std::getline(ss, nombre, '|');
            std::getline(ss, codigo, '|');
            std::getline(ss, creditosTexto, '|');

            materias.push_back(
                Materia(
                    nombre,
                    codigo,
                    std::stoi(creditosTexto)
                )
            );
        }

        archivoMaterias.close();
    }
    std::ifstream archivoCalificaciones("calificaciones.txt");

    if (archivoCalificaciones.is_open()) {
        while (std::getline(archivoCalificaciones, linea)) {
            std::stringstream ss(linea);

            std::string matricula;
            std::string codigoProfesor;
            std::string codigoMateria;
            std::string notaTexto;

            std::getline(ss, matricula, '|');
            std::getline(ss, codigoProfesor, '|');
            std::getline(ss, codigoMateria, '|');
            std::getline(ss, notaTexto, '|');

            Estudiante estudianteEncontrado;
            Profesor profesorEncontrado;
            Materia materiaEncontrada;

            bool estudianteExiste = false;
            bool profesorExiste = false;
            bool materiaExiste = false;

            for (const Estudiante& e : estudiantes) {
                if (e.getMatricula() == matricula) {
                    estudianteEncontrado = e;
                    estudianteExiste = true;
                    break;
                }
            }

            for (const Profesor& p : profesores) {
                if (p.getCodigoProfesor() == codigoProfesor) {
                    profesorEncontrado = p;
                    profesorExiste = true;
                    break;
                }
            }

            for (const Materia& m : materias) {
                if (m.getCodigoMateria() == codigoMateria) {
                    materiaEncontrada = m;
                    materiaExiste = true;
                    break;
                }
            }

            if (estudianteExiste &&
                profesorExiste &&
                materiaExiste) {

                calificaciones.push_back(
                    Calificacion(
                        estudianteEncontrado,
                        profesorEncontrado,
                        materiaEncontrada,
                        std::stod(notaTexto)
                    )
                );
            }
        }

        archivoCalificaciones.close();

        std::ofstream archivoCalificaciones("calificaciones.txt");

        for (const Calificacion& c : calificaciones) {
            archivoCalificaciones
                << c.getEstudiante().getMatricula() << '|'
                << c.getProfesor().getCodigoProfesor() << '|'
                << c.getMateria().getCodigoMateria() << '|'
                << c.getNota()
                << '\n';
        }

        archivoCalificaciones.close();
    }
}

void Sistema::guardarDatos() {

    std::cout << "Calificaciones guardadas: "
              << calificaciones.size()
              << '\n';

    std::ofstream archivoEstudiantes("estudiantes.txt");

    for (const Estudiante& e : estudiantes) {
        archivoEstudiantes
            << e.getNombreCompleto() << '|'
            << e.getMatricula() << '|'
            << e.getSesion()
            << '\n';
    }

    archivoEstudiantes.close();

    std::ofstream archivoProfesores("profesores.txt");

    for (const Profesor& p : profesores) {
        archivoProfesores
            << p.getNombreCompleto() << '|'
            << p.getCodigoProfesor()
            << '\n';
    }

    archivoProfesores.close();

    std::ofstream archivoMaterias("materias.txt");

    for (const Materia& m : materias) {
        archivoMaterias
            << m.getNombreMateria() << '|'
            << m.getCodigoMateria() << '|'
            << m.getCantidadCreditos()
            << '\n';
    }

    archivoMaterias.close();

    std::ofstream archivoCalificaciones("calificaciones.txt");

    for (const Calificacion& c : calificaciones) {
        archivoCalificaciones
            << c.getEstudiante().getMatricula() << '|'
            << c.getProfesor().getCodigoProfesor() << '|'
            << c.getMateria().getCodigoMateria() << '|'
            << c.getNota()
            << '\n';
    }

    archivoCalificaciones.close();
}


void Sistema::ejecutar() {
    cargarDatos();

    int opcion;

    do {
        opcion = mostrarMenu();

        switch (opcion) {
        case 1:
            registrarEstudiante();
            break;

        case 2:
            registrarProfesor();
            break;

        case 3:
            registrarMateria();
            break;

        case 4:
            registrarCalificacion();
            break;

        case 5:
            verEstudiantes();
            break;

        case 6:
            verProfesores();
            break;

        case 7:
            verMaterias();
            break;

        case 8:
            verCalificaciones();
            break;

        case 9:
            guardarDatos();
            break;

        default:
            std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 9);
}
