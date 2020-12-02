#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include "Reserva.h"
#include <QString>
#include "Persona.h"

class Cliente:public Persona
{
private:
    Reserva *reservas;
public:
    QString tarjid;
	void agregar_reserva();
	void obtener_reserva();
    Cliente();
    Cliente(QString, QString, QString, int, QString, QString);
};
#endif // CLIENTE_H_INCLUDED
