#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED
#include <string>
#include <QString>
using namespace std;
class Persona
{
private:
    QString nombre;
    int edad;
    QString usuario;
    QString contrasenia;
    QString tipo;
public:
    void registrar_nombre(QString);
	void registrar_edad(int);
    void registrar_usuario(QString);
    void registrar_contrasenia(QString);
    void registrar_tipo(QString);
    QString obtener_nombre();
	int obtener_edad();
    QString obtener_usuario();
    QString obtener_contrasenia();
    QString obtener_tipo();
    Persona(QString, QString, QString, int, QString);
    Persona();
};
#endif // PERSONA_H_INCLUDED
