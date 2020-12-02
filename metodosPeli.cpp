#include <string>
#include "Pelicula.h"
#include <iostream>

using namespace std;

void Pelicula::establecer_titulo(string tit){
    titulo=tit;
}
void Pelicula::establecer_duracion(int dur){
    duracion=dur;
}
void Pelicula::establecer_director(string dir){
    director=dir;
}
void Pelicula::establecer_sinopsis(string sin){
    sinopsis=sin;
}
void Pelicula::agregar_genero(){
}
void Pelicula::agregar_idioma(){
}
string Pelicula::obtener_titulo(){
    return titulo;
}
string* Pelicula:: obtener_generos(){
    return genero;
}
string* Pelicula:: obtener_idiomas(){
    return idioma;
}
int Pelicula::obtener_duracion(){
    return duracion;
}
string Pelicula::obtener_director(){
    return director;
}
string Pelicula::obtener_sinopsis(){
    return sinopsis;
}
void Pelicula::mostrarDatos(){
    cout << "Titulo: " << titulo<<endl;
    cout << "Genero: " << endl;
    cout << "Idioma: " << endl;
    cout << "Director: "<< director<<endl;
    cout << "Duracion: "<< duracion<<endl;
    cout << "Sinopsis: " << sinopsis<<endl;
}
