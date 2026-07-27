#ifndef PODCAST_H
#define PODCAST_H

#include "Audio.h"


class Podcast : public Audio
{

public:

    Podcast(std::string titulo, std::string presentador);


    void mostrar() const override;


    void guardar(std::ofstream& archivo) const override;


};


#endif
