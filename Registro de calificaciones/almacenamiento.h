#ifndef ALMACENAMIENTO_H
#define ALMACENAMIENTO_H

#include <vector>

#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"
#include "Calificacion.h"

class Almacenamiento {
public:

    // Estudiantes
    static void guardarEstudiantes(
        const std::vector<Estudiante>& estudiantes);

    static void cargarEstudiantes(
        std::vector<Estudiante>& estudiantes);

    // Profesores
    static void guardarProfesores(
        const std::vector<Profesor>& profesores);

    static void cargarProfesores(
        std::vector<Profesor>& profesores);

    // Materias
    static void guardarMaterias(
        const std::vector<Materia>& materias);

    static void cargarMaterias(
        std::vector<Materia>& materias);

    // Calificaciones
    static void guardarCalificaciones(
        const std::vector<Calificacion>& calificaciones);
};

#endif
