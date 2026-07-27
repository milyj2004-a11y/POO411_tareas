#include "Podcast.h"



Podcast::Podcast(std::string titulo, std::string presentador)
    : Audio(titulo, presentador)
{

}



void Podcast::mostrar() const
{

    std::cout
        << "Podcast: "
        << titulo
        << " - Presentador: "
        << autor
        << '\n';

}




void Podcast::guardar(std::ofstream& archivo) const
{

    archivo
        << "2;"
        << titulo
        << ";"
        << autor
        << "\n";

}