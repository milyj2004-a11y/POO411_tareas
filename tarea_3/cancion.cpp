#include "Cancion.h"


Cancion::Cancion(std::string titulo, std::string artista)
    : Audio(titulo, artista)
{

}



void Cancion::mostrar() const
{

    std::cout 
        << "Cancion: "
        << titulo
        << " - Artista: "
        << autor
        << '\n';

}



void Cancion::guardar(std::ofstream& archivo) const
{

    archivo 
        << "1;"
        << titulo
        << ";"
        << autor
        << "\n";

}