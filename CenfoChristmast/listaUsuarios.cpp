#include <stdlib.h>
#include <iostream>

#include "listaUsuarios.h"
using namespace std;

listaUsuarios::listaUsuarios()
{
	this->cab = NULL;
	this->largo = 0;
}

listaUsuarios::~listaUsuarios()
{
}

usuarioNodo* listaUsuarios::getCab()
{
	return this->cab;
}

int listaUsuarios::getLargo()
{
	return this->largo;
}

void listaUsuarios::setCab(usuarioNodo* ptr)
{
	this->cab = ptr;
}

void listaUsuarios::setLargo(int n)
{
	this->largo = n;
}

bool listaUsuarios::esVacia()
{
	return this->getLargo() == 0;
}

usuarioNodo* listaUsuarios::dirNodo(int pCedula)
{
	usuarioNodo* aux = getCab();
	usuario user = aux->getUsuario();
	while ((aux != NULL) && (user.getCedula() != pCedula)) {
		aux = aux->getSgte();
	}
	return aux;
}

usuarioNodo* listaUsuarios::dirAnterior(int pnum)
{
	usuarioNodo* ant = NULL;

	if (!esVacia()) {
		ant = getCab();


		while ((ant != NULL) && (ant->getSgte() != NULL)) {

			if (ant->getSgte()->getUsuario().getCedula() == pnum) {
				return ant;
			}
			else {
				ant = ant->getSgte();
			}
		}
		return NULL;
	}
	else {
		return NULL;
	}
}

usuarioNodo* listaUsuarios::dirUltimo()
{
	usuarioNodo* aux = getCab();

	while (aux != NULL && aux->getSgte() != NULL) {
		aux = aux->getSgte();
	}
	return aux;
}

void listaUsuarios::desplegar()
{
	usuarioNodo* aux = getCab();
	if (aux == NULL) {
		cout << "AUN NO HAY USUARIOS..." << endl;
	}
	else {
		cout << "USUARIOS EN LA LISTA:" << endl;
		cout << "-----Administradores-----" << endl;
		while (aux != NULL) {
			usuario user = aux->getUsuario();
			if (user.getPerfil()) {
				cout << user.getCedula() << " - " << user.getNombre() << " " << user.getApellido() << std::endl;
				aux = aux->getSgte();
			}
			else {
				aux = aux->getSgte();
			}
		}

		aux = getCab();
		cout << "-----Clientes-----" << endl;
		while (aux != NULL) {
			usuario user = aux->getUsuario();
			if (!user.getPerfil()) {
				cout << user.getCedula() << " - " << user.getNombre() << " " << user.getApellido() << std::endl;
				aux = aux->getSgte();
			}
			else {
				aux = aux->getSgte();
			}
		}
		cout << "//";
	}

}

void listaUsuarios::desplegarTodo()
{
	usuarioNodo* aux = getCab();
	if (aux == NULL) {
		cout << "AUN NO HAY USUARIOS..." << endl;
	}
	else {
		cout << "TODOS LOS USUARIOS:" << endl;
		while (aux != NULL) {
			usuario user = aux->getUsuario();
			cout << user.getCedula() << " - " << user.getNombre() << " " << user.getApellido() << std::endl;
			aux = aux->getSgte();
		}
		cout << "//";
	}

}

void listaUsuarios::agregarInicio(usuario user)
{
	usuarioNodo* nuevo = new usuarioNodo(user);
	nuevo->setSgte(getCab());
	setCab(nuevo);
	largo++;
}

void listaUsuarios::agregarFinal(usuario user)
{
	usuarioNodo* nuevo = new usuarioNodo(user);
	usuarioNodo* ultimo = dirUltimo();
	ultimo->setSgte(nuevo);
	largo++;
}

bool listaUsuarios::agregarAntesDe(usuario user, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		usuario user = getCab()->getUsuario();
		if (user.getCedula() == ref) {
			agregarInicio(user);
			agregado = true;
		}
		else {
			usuarioNodo* ant = dirAnterior(ref);
			if (ant != NULL) {
				usuarioNodo* nuevo = new usuarioNodo(user);
				nuevo->setSgte(ant->getSgte());
				ant->setSgte(nuevo);
				largo++;
				agregado = true;
			}
		}

	}
	return agregado;
}

bool listaUsuarios::agregarDespuesDe(usuario user, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		usuarioNodo* ant = dirNodo(ref);
		if (ant != NULL) {
			usuarioNodo* nuevo = new usuarioNodo(user);
			nuevo->setSgte(ant->getSgte());
			ant->setSgte(nuevo);
			largo++;
			agregado = true;
		}
	}
	return agregado;
}

bool listaUsuarios::modificar(int pCedula, usuario user)
{
	bool modificado = false;
	if (!esVacia()) {

		usuarioNodo* aux = getCab();

		while (aux != NULL && !modificado) {
			usuario ref = aux->getUsuario();
			if (ref.getCedula() == pCedula) {
				aux->setUsuario(user);
				modificado = true;
			}
			else {
				aux = aux->getSgte();
			}
		}
	}
	return modificado;
}

bool listaUsuarios::eliminar(int pCedula)
{
	bool eliminado = false;
	if (!esVacia()) {

		usuarioNodo* aux;
		if (getCab()->getUsuario().getCedula() == pCedula) {
			aux = getCab();
			setCab(aux->getSgte());
			setLargo(getLargo() - 1);
			delete aux;
			eliminado = true;
		}
		else {
			usuarioNodo* ant = dirAnterior(pCedula);
			if (ant != NULL) {
				aux = ant->getSgte();
				ant->setSgte(aux->getSgte());
				setLargo(getLargo() - 1);
				delete aux;
				eliminado = true;
			}
		}
	}
	return eliminado;
}

void listaUsuarios::consultarNombre(string pNombre)
{
	bool encontrado = false;
	if (!esVacia()) {

		usuarioNodo* aux = getCab();

		while (aux != NULL && !encontrado) {
			usuario ref = aux->getUsuario();
			if (ref.getNombre() == pNombre) {
				cout << ref.getCedula() << " - " << ref.getNombre() << " " << ref.getApellido() << ". Contacto: " << ref.getCorreo() << " - " << ref.getTelefono() << std::endl;
				encontrado = true;
			}
			else {
				aux = aux->getSgte();
			}
		}
		if (!encontrado) {
			cout << "NO HAY NADIE CON TAL NOMBRE " << endl;
		}
	}
	else {
		cout << "NO HAY NADA" << endl;
	}
}

void listaUsuarios::consultarCedula(int pCedula)
{
	bool encontrado = false;
	if (!esVacia()) {

		usuarioNodo* aux = getCab();

		while (aux != NULL && !encontrado) {
			usuario ref = aux->getUsuario();
			if (ref.getCedula() == pCedula) {
				cout << ref.getCedula() << " - " << ref.getNombre() << " " << ref.getApellido() << ". Contacto: " << ref.getCorreo() << " - " << ref.getTelefono() << std::endl;
				encontrado = true;
			}
			else {
				aux = aux->getSgte();
			}
		}
		if (!encontrado) {
			cout << "NO HAY NINGUNA CEDULA " << pCedula << endl;
		}
	}
	else {
		cout << "NO HAY NADA" << endl;
	}
}