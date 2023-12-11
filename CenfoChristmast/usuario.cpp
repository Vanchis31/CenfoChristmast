#include "usuario.h"

usuario::usuario()
{
	this->cedula = 0;
	this->nombre = " ";
	this->apellido = " ";
	this->correo = " ";
	this->telefono = 0;
}

usuario::usuario(bool pPerfil, int pCedula, string pNombre, string pApellido, string pCorreo, int pTelefono)
{
	this->perfil = pPerfil;
	this->cedula = pCedula;
	this->nombre = pNombre;
	this->apellido = pApellido;
	this->correo = pCorreo;
	this->telefono = pTelefono;
}

void usuario::setPerfil(bool pPerfil)
{
	this->perfil = pPerfil;
}

void usuario::setCedula(int pCedula)
{
	this->cedula = pCedula;
}

void usuario::setNombre(string pNombre)
{
	this->nombre = pNombre;
}

void usuario::setApellido(string pApellido)
{
	this->apellido = pApellido;
}

void usuario::setCorreo(string pCorreo)
{
	this->correo = pCorreo;
}

void usuario::setTelefono(int pTelefono)
{
	this->telefono = pTelefono;
}

bool usuario::getPerfil()
{
	return this->perfil;
}

int usuario::getCedula()
{
	return this->cedula;
}

string usuario::getNombre()
{
	return this->nombre;
}

string usuario::getApellido()
{
	return this->apellido;
}

string usuario::getCorreo()
{
	return this->correo;
}

int usuario::getTelefono()
{
	return this->telefono;
}