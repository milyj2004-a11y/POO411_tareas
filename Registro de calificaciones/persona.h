#ifndef PERSONA_H
#define PERSONA_H

#include <string>

class Persona {
protected:
    std::string nombreCompleto;

public:
    Persona();

    Persona(const std::string& nombreCompleto);

    Persona(const Persona& otra);

    Persona& operator=(const Persona& otra);

    std::string getNombreCompleto() const;

    void setNombreCompleto(const std::string& nombreCompleto);

    virtual ~Persona();
};

#endif
