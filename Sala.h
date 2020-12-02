#ifndef SALA_H_INCLUDED
#define SALA_H_INCLUDED
#include "Horario.h"
#include <string>

using namespace std;
class Sala
{
private:
    Horario *horarios;
	string tipo_de_sala;
    int numero_de_sillas;
    int numero_de_sillas_preferencial;
    int numero_de_sillas_general;
public:
	void establecer_tipo_de_sala();
	void establecer_numero_de_sillas();
	void establecer_numero_de_sillas_preferencial();
	void establecer_numero_de_sillas_general();
	void agregar_horario();
	string obtener_tipo_de_sala();
	int obtener_numero_de_sillas();
	int obtener_numero_de_sillas_preferencial();
	int obtener_numero_de_sillas_general();
	Horario* obtener_horarios();
	void mostrarDatos();
};
#endif // SALA_H_INCLUDED
