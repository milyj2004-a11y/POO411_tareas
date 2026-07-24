#include "Almacenamiento.h"

#include <fstream>
#include <sstream>

void Almacenamiento::guardarEstudiantes(
    const std::vector<Estudiante>& estudiantes)
{
    std::ofstream archivo("estudiantes.txt");

    for (const Estudiante& e : estudiantes) {
        archivo << e << '\n';
    }
}

void Almacenamiento::cargarEstudiantes(
    std::vector<Estudiante>& estudiantes)
{
    std::ifstream archivo("estudiantes.txt");

    Estudiante estudiante;

    while (archivo >> estudiante) {
        estudiantes.push_back(estudiante);
    }
}

void Almacenamiento::guardarProfesores(
    const std::vector<Profesor>& profesores)
{
    std::ofstream archivo("profesores.txt");

    for (const Profesor& profesor : profesores) {
        archivo << profesor << '\n';
    }
}

void Almacenamiento::cargarProfesores(
    std::vector<Profesor>& profesores)
{
    std::ifstream archivo("profesores.txt");

    Profesor profesor;

    while (archivo >> profesor) {
        profesores.push_back(profesor);
    }
}

void Almacenamiento::guardarMaterias(
    const std::vector<Materia>& materias)
{
    std::ofstream archivo("materias.txt");

    for (const Materia& materia : materias) {
        archivo << materia << '\n';
    }
}

void Almacenamiento::cargarMaterias(
    std::vector<Materia>& materias)
{
    std::ifstream archivo("materias.txt");

    Materia materia;

    while (archivo >> materia) {
        materias.push_back(materia);
    }
}

void Almacenamiento::guardarCalificaciones(
    const std::vector<Calificacion>& calificaciones)
{
    std::ofstream archivo("calificaciones.txt");

    for (const Calificacion& calificacion : calificaciones) {
        archivo << calificacion << '\n';
    }
}
