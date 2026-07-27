#ifndef CANCION_H
#define CANCION_H

#include "Audio.h"


class Cancion : public Audio
{

public:

    Cancion(std::string titulo, std::string artista);


    void mostrar() const override;


    void guardar(std::ofstream& archivo) const override;


};


#endif