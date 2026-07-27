#ifndef AUDIO_H
#define AUDIO_H

#include <iostream>
#include <string>
#include <fstream>

class Audio
{

protected:

    std::string titulo;
    std::string autor;


public:

    Audio(std::string titulo, std::string autor);


    virtual void mostrar() const = 0;


    virtual void guardar(std::ofstream& archivo) const = 0;


    virtual ~Audio();

};


#endif