#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>

class Estudiante {
private:
    std::string nombreCompleto;
    std::string matricula;
    std::string sesion;

public:
    Estudiante();
    Estudiante(const std::string& nombreCompleto,
               const std::string& matricula,
               const std::string& sesion);

    Estudiante(const Estudiante& otro);

    Estudiante& operator=(const Estudiante& otro);

    std::string getNombreCompleto() const;
    std::string getMatricula() const;
    std::string getSesion() const;
};

#endif
