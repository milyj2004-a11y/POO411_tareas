#ifndef PROFESOR_H
#define PROFESOR_H

#include <iostream>
#include <string>
#include "Persona.h"

class Profesor : public Persona {

private:
    std::string codigoProfesor;

public:
    Profesor();

    Profesor(const std::string& nombreCompleto,
             const std::string& codigoProfesor);

    Profesor(const Profesor& otro);

    Profesor& operator=(const Profesor& otro);

    std::string getCodigoProfesor() const;

    friend std::ostream& operator<<(std::ostream& salida,
                                    const Profesor& profesor);

    friend std::istream& operator>>(std::istream& entrada,
                                    Profesor& profesor);
};

#endif
