#include "Materia.h"

Materia::Materia()
    : cantidadCreditos(0) {
}

Materia::Materia(const std::string& nombreMateria,
                 const std::string& codigoMateria,
                 int cantidadCreditos)
    : nombreMateria(nombreMateria),
      codigoMateria(codigoMateria),
      cantidadCreditos(cantidadCreditos) {
}

Materia::Materia(const Materia& otra)
    : nombreMateria(otra.nombreMateria),
      codigoMateria(otra.codigoMateria),
      cantidadCreditos(otra.cantidadCreditos) {
}

std::string Materia::getNombreMateria() const {
    return nombreMateria;
}

std::string Materia::getCodigoMateria() const {
    return codigoMateria;
}

int Materia::getCantidadCreditos() const {
    return cantidadCreditos;
}

Materia& Materia::operator=(const Materia& otra) {
    if (this != &otra) {
        nombreMateria = otra.nombreMateria;
        codigoMateria = otra.codigoMateria;
        cantidadCreditos = otra.cantidadCreditos;
    }
    return *this;
}
