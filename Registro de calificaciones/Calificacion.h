#ifndef CALIFICACION_H
#define CALIFICACION_H

#include <iostream>
#include "Estudiante.h"
#include "Profesor.h"
#include "Materia.h"

class Calificacion {
private:
    Estudiante estudiante;
    Profesor profesor;
    Materia materia;
    double nota;

public:
    Calificacion();

    Calificacion(
        const Estudiante& estudiante,
        const Profesor& profesor,
        const Materia& materia,
        double nota
    );

    Calificacion(const Calificacion& otra);

    Calificacion& operator=(const Calificacion& otra);

    Estudiante getEstudiante() const;
    Profesor getProfesor() const;
    Materia getMateria() const;
    double getNota() const;

    friend std::ostream& operator<<(std::ostream& salida,
                                    const Calificacion& calificacion);

    friend std::istream& operator>>(std::istream& entrada,
                                    Calificacion& calificacion);
};

#endif
