#ifndef MATERIA_H
#define MATERIA_H

#include <iostream>
#include <string>

class Materia {
private:
    std::string nombreMateria;
    std::string codigoMateria;
    int cantidadCreditos;

public:
    Materia();
    Materia(const std::string& nombreMateria,
            const std::string& codigoMateria,
            int cantidadCreditos);

    Materia(const Materia& otra);

    Materia& operator=(const Materia& otra);

    std::string getNombreMateria() const;
    std::string getCodigoMateria() const;
    int getCantidadCreditos() const;
    friend std::ostream& operator<<(std::ostream& salida,
                                    const Materia& materia);

    friend std::istream& operator>>(std::istream& entrada,
                                    Materia& materia);
};

#endif
