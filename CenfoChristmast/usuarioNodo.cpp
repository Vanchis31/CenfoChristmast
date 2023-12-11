#include "usuarioNodo.h"



usuarioNodo::usuarioNodo(usuario user)
{
	this->user = user;
	this->sgte = NULL;
}

usuarioNodo::usuarioNodo()
{
	this->user = usuario();
	this->sgte = NULL;
}

void usuarioNodo::setUsuario(usuario user)
{
	this->user = user;
}

void usuarioNodo::setSgte(usuarioNodo* ptr)
{
	this->sgte = ptr;
}

usuario usuarioNodo::getUsuario()
{
	return this->user;
}

usuarioNodo* usuarioNodo::getSgte()
{
	return this->sgte;
}