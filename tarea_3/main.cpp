#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

#include "Cancion.h"
#include "Podcast.h"


using namespace std;



void registrarCancion(vector<Audio*>& lista)
{

    string titulo;
    string artista;


    cout << "Titulo de la cancion: ";
    getline(cin,titulo);


    cout << "Artista: ";
    getline(cin,artista);



    lista.push_back(
        new Cancion(titulo,artista)
    );


    cout<<"Cancion registrada.\n";

}




void registrarPodcast(vector<Audio*>& lista)
{

    string titulo;
    string presentador;



    cout<<"Titulo del podcast: ";
    getline(cin,titulo);



    cout<<"Presentador: ";
    getline(cin,presentador);



    lista.push_back(
        new Podcast(titulo,presentador)
    );


    cout<<"Podcast registrado.\n";

}




void mostrarAudios(const vector<Audio*>& lista)
{

    if(lista.empty())
    {

        cout<<"No hay audios registrados.\n";
        return;

    }



    cout<<"\n--- Lista de audios ---\n";



    for(Audio* audio : lista)
    {

        audio->mostrar();

    }

}




void guardarAudios(const vector<Audio*>& lista)
{

    ofstream archivo("audios.txt");



    for(Audio* audio : lista)
    {

        audio->guardar(archivo);

    }



    archivo.close();

}





void cargarAudios(vector<Audio*>& lista)
{

    ifstream archivo("audios.txt");



    if(!archivo)
        return;



    string linea;



    while(getline(archivo,linea))
    {

        stringstream ss(linea);



        string tipo;
        string titulo;
        string autor;



        getline(ss,tipo,';');

        getline(ss,titulo,';');

        getline(ss,autor,';');



        if(tipo=="1")
        {

            lista.push_back(
                new Cancion(titulo,autor)
            );

        }
        else if(tipo=="2")
        {

            lista.push_back(
                new Podcast(titulo,autor)
            );

        }

    }



    archivo.close();

}





int main()
{

    vector<Audio*> lista;



    cargarAudios(lista);



    int opcion=-1;



    while(opcion!=0)
    {


        cout<<"\n=== Registro de audios ===\n";

        cout<<"1. Registrar cancion\n";

        cout<<"2. Registrar podcast\n";

        cout<<"3. Mostrar audios\n";

        cout<<"0. Salir\n";

        cout<<"Opcion: ";



        cin>>opcion;

        cin.ignore();



        switch(opcion)
        {


            case 1:

                registrarCancion(lista);

                break;



            case 2:

                registrarPodcast(lista);

                break;



            case 3:

                mostrarAudios(lista);

                break;



            case 0:

                guardarAudios(lista);

                cout<<"Programa finalizado.\n";

                break;



            default:

                cout<<"Opcion no valida.\n";

        }


    }




    for(Audio* audio : lista)
    {

        delete audio;

    }



    return 0;

}