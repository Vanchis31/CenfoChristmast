#pragma once
#include <stdlib.h>
#include <iostream>
#include "producto.h"
#include "productoNodo.h"

using namespace std;
class productoNodo
{
private:
	producto dato;
	productoNodo* sgte;
	productoNodo* ante;

public:
	productoNodo(producto);
	productoNodo();

	producto getDato();
	productoNodo* getSgte();
	productoNodo* getAnte();

	void setDato(producto);
	void setSgte(productoNodo*);
	void setAnte(productoNodo*);
};


