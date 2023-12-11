#pragma once
#include <iostream>
#include <string>
#include "usuario.h"
using namespace std;

class usuarioNodo
{
private:
	usuario user;
	usuarioNodo* sgte;
public:
	usuarioNodo();
	usuarioNodo(usuario);

	void setUsuario(usuario);
	void setSgte(usuarioNodo*);

	usuario getUsuario();
	usuarioNodo* getSgte();
};
