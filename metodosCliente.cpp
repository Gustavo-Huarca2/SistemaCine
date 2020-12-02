#include <string>
#include "Cliente.h"

using namespace std;


Cliente::Cliente(QString nom, QString user, QString pass, int ed, QString rol, QString tarid){
    registrar_nombre(nom);
    registrar_edad(ed);
    registrar_usuario(user);
    registrar_contrasenia(pass);
    registrar_tipo(rol);
    tarjid=tarid;
}
