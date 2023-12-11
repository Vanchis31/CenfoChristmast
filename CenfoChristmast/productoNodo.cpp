#include "productoNodo.h"
#include "producto.h"
#include <cstddef>


productoNodo::productoNodo(producto dato)
{
	this->dato = dato;
	this->sgte = NULL;
	this->ante = NULL;
}

productoNodo::productoNodo()
{
	this->dato = producto();
	this->sgte = NULL;
	this->ante = NULL;
}


void productoNodo::setDato(producto dato)
{
	this->dato = dato;
}

void productoNodo::setSgte(productoNodo* ptr)
{
	this->sgte = ptr;
}

void productoNodo::setAnte(productoNodo* ptr)
{
	this->ante = ptr;
}

 producto productoNodo::getDato()
{
	return this->dato;
}

productoNodo* productoNodo::getSgte()
{
	return this->sgte;
}

productoNodo* productoNodo::getAnte()
{
	return this->ante;
}