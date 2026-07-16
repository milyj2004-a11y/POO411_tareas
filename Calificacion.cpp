#include "Calificacion.h"

Calificacion::Calificacion()
    : nota(0.0) {
}

Calificacion::Calificacion(
    const Estudiante& estudiante,
    const Profesor& profesor,
    const Materia& materia,
    double nota)
    : estudiante(estudiante),
      profesor(profesor),
      materia(materia),
      nota(nota) {
}

Calificacion::Calificacion(const Calificacion& otra)
    : estudiante(otra.estudiante),
      profesor(otra.profesor),
      materia(otra.materia),
      nota(otra.nota) {
}

Estudiante Calificacion::getEstudiante() const {
    return estudiante;
}

Profesor Calificacion::getProfesor() const {
    return profesor;
}

Materia Calificacion::getMateria() const {
    return materia;
}

double Calificacion::getNota() const {
    return nota;
}

Calificacion& Calificacion::operator=(const Calificacion& otra) {
    if (this != &otra) {
        estudiante = otra.estudiante;
        profesor = otra.profesor;
        materia = otra.materia;
        nota = otra.nota;
    }
    return *this;
}
