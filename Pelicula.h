#ifndef PELICULA_H_INCLUDED
#define PELICULA_H_INCLUDED
#include <string>

using namespace std;
class Pelicula
{
private:
	string titulo;
    string *genero;
    string *idioma;
    int duracion;
    string director;
    string sinopsis;
public:
	void establecer_titulo(string);
	void establecer_duracion(int);
	void establecer_director(string);
	void establecer_sinopsis(string);
	void agregar_genero();
	void agregar_idioma();
	string obtener_titulo();
	int obtener_duracion();
	string obtener_director();
	string obtener_sinopsis();
	string* obtener_generos();
	string* obtener_idiomas();
	void mostrarDatos();
};
#endif // PELICULA_H_INCLUDED
