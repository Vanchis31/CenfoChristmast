#include "listaProducto.h"
#include "producto.h"
#include <stdlib.h>
#include <iostream>

using namespace std;

listaProducto::listaProducto()
{
	this->cab = NULL;
	this->largo = 0;
}

listaProducto::~listaProducto()
{
}

productoNodo* listaProducto::getCab()
{
	return this->cab;
}

int listaProducto::getLargo()
{
	return this->largo;
}

void listaProducto::setCab(productoNodo* ptr)
{
	this->cab = ptr;
}

void listaProducto::setLargo(int n)
{
	this->largo = n;
}

bool listaProducto::esVacia()
{
	return this->getLargo() == 0;
}

productoNodo* listaProducto::dirNodo(string pnum)
{ //Devolver la direcci�n donde se ubica pnum
	productoNodo* aux = getCab();
	producto prod = aux->getDato();
	do {
		aux = aux->getSgte();
		
	} while ((aux != NULL) && (aux->getDato().getCodigo() != pnum));
	return aux;
}

productoNodo* listaProducto::dirAnterior(string pdato)
{
	productoNodo* aux = dirNodo(pdato);
	if (aux != nullptr) {
		return aux->getAnte();
	}
	else {
		return nullptr;
	}
}

productoNodo* listaProducto::dirSiguiente(string pdato)
{
	productoNodo* aux = dirNodo(pdato);
	if (aux != nullptr) {
		return aux->getSgte();
	}
	else {
		return nullptr;
	}
}

productoNodo* listaProducto::dirUltimo()
{
	productoNodo* aux = getCab();

	if (aux != nullptr) {
		return aux->getAnte();
	}
}

bool listaProducto::eliminar(string pdato)
{
	bool eliminado = false;
	if (!esVacia()) {
		productoNodo* aux = dirNodo(pdato); //Paso0 1. Encuentro el nodoa eliminar
		if (aux != nullptr) {
			//Paso 2. Reacomodo la lista sin el nuevo nodo
			if (getLargo() == 1) {
				setCab(nullptr);
			}
			else {
				aux->getAnte()->setSgte(aux->getSgte());
				aux->getSgte()->setAnte(aux->getAnte());
				if (aux == getCab())
					setCab(getCab()->getSgte());
			}
			//Paso 3. Borrar el aux y reajustar
			delete aux;
			setLargo(getLargo() - 1);
			eliminado = true;
		}
	}
	return eliminado;
}

void listaProducto::desplegar() {

	if (esVacia()) {
		cout << "La lista esta vacia, no hay elementos a desplegar" << endl;
	}
	else {
		productoNodo* aux = getCab();
		for (int i = 1; i <= getLargo(); i++) {
			producto Prod = aux->getDato();
			cout << Prod.getNombre() << "-";
			aux = aux->getSgte();
		}
	}
}

void listaProducto::desplegarReves() {

	if (esVacia()) {
		cout << "La lista esta vacia, no hay elementos a desplegar" << endl;
	}
	else {
		productoNodo* aux = getCab()->getAnte();
		while (aux != getCab()) {
			producto Prod = aux->getDato();
			cout << Prod.getNombre() << "-";
			aux = aux->getAnte();
		}
		producto cab = aux->getDato();
		cout << cab.getNombre() << "";

	}
}

void listaProducto::agregarInicio(producto pdato)
{
	//Paso 1. Crear el nodo
	productoNodo* nuevo = new productoNodo(pdato);
	//Paso 2. Enlazar el nuevo nodo a la lista
	if (esVacia()) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
	}
	else {
		nuevo->setSgte(getCab());
		nuevo->setAnte(getCab()->getAnte());

		//Paso 3. Reacomodar la lista con el nuevo nodo
		getCab()->getAnte()->setSgte(nuevo);
		getCab()->setAnte(nuevo);
	}

	setCab(nuevo);
	setLargo(getLargo() + 1);
}

void listaProducto::agregarFinal(producto pdato)
{
	//Paso 1. Crear el nodo
	productoNodo* nuevo = new productoNodo(pdato);
	if (esVacia()) {
		nuevo->setSgte(nuevo);
		nuevo->setAnte(nuevo);
	}
	else {
		nuevo->setSgte(getCab());
		nuevo->setAnte(getCab()->getAnte());

		//Paso 3. Reacomodar la lista con el nuevo nodo
		getCab()->getAnte()->setSgte(nuevo);
		getCab()->setAnte(nuevo);
	}

	setLargo(getLargo() + 1);

}

producto listaProducto::consultarPorNombre(string nombre) {
	if (esVacia()) {
		cout << "La lista esta vacia, no hay elementos a desplegar" << endl;
	}
	else {
		productoNodo* aux = getCab();
		for (int i = 1; i <= getLargo(); i++) {
			producto Prod = aux->getDato();
			if (Prod.getNombre() == nombre) {
				cout << Prod.getCodigo() << "-";
				cout << Prod.getNombre() << "-";
				cout << Prod.getPrecio() << "-";
				cout << Prod.getCantidad() << "-";
				cout << Prod.getDescuento() << "";
				return Prod;
			}
			aux = aux->getSgte();
		}
	}
}

void listaProducto::cambioDePrecio() {
	if (esVacia()) {
		cout << "La lista esta vacia, no hay elementos a desplegar" << endl;
	}
	else {
		productoNodo* aux = getCab();
		for (int i = 1; i <= getLargo(); i++) {
			producto Prod = aux->getDato();
			if (Prod.getDescuento() != 0) {
				cout << Prod.getNombre() << "-";
				cout << Prod.getPrecio() << "-";
				cout << Prod.getDescuento() << "";
			}
			aux = aux->getSgte();
		}
	}
}


void listaProducto::consultarCantidadLimite(int tope) {
	if (esVacia()) {
		cout << "La lista esta vacia, no hay elementos a desplegar" << endl;
	}
	else {
		productoNodo* aux = getCab();
		for (int i = 1; i <= getLargo(); i++) {
			producto Prod = aux->getDato();
			if (Prod.getCantidad() < tope) {
				cout << Prod.getNombre() << "-";
				cout << Prod.getPrecio() << "-";
				cout << Prod.getCantidad() << " || ";
			}
			aux = aux->getSgte();
		}
	}
}
/*bool listaProducto::agregarAntesDe(int x, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		if (getCab()->getDato() == ref) {
			agregarInicio(x);
			agregado = true;
		}
		else {
			productoNodo* sig = dirSiguiente(ref);
			if (sig != NULL) {						//Aunque este If no sea realmente necesario, funciona para detectar una cola mal conectada.
				// Paso #1, crear el nodo
				productoNodo* nuevo = new productoNodo(x);
				// Paso #2, enlazar el nuevo nodo a la lista, guinde el nodo
				nuevo->setAnte(sig->getAnte());
				nuevo->setSgte(sig);
				// Paso #3, reacomodo la lista con el nuevo nodo
				sig->setAnte(nuevo);
				productoNodo* ant = nuevo->getAnte();
				ant->setSgte(nuevo);
				largo++;
				agregado = true;
			}
		}

	}
	return agregado;
}

bool listaProducto::agregarDespuesDe(int x, int ref)
{
	bool agregado = false;
	if (getCab() != NULL) {
		productoNodo* ant = dirAnterior(ref);
		if (ant != NULL) {							//Aunque este If no sea realmente necesario, funciona para detectar una cola mal conectada
			// Paso #1, crear el nodo
			productoNodo* nuevo = new productoNodo(x);
			// Paso #2, enlazar el nuevo nodo a la lista, guinde el nodo
			nuevo->setSgte(ant->getSgte());
			nuevo->setAnte(ant);
			// Paso #3, reacomodo la lista con el nuevo nodo
			ant->setSgte(nuevo);
			productoNodo* sig = nuevo->getSgte();
			sig->setAnte(nuevo);
			largo++;
			agregado = true;
		}
	}
	return agregado;

	return false;
}

bool listaProducto::agregarAscendente(int pnum)
{ //Agregar en forma ascendente (de menor a mayor) en la lista, considerando que no
 // pueden darse valores repetidos
	bool agregado = false;
	bool repetido = false;
	if (esVacia() or pnum < getCab()->getDato()) {
		agregarInicio(pnum);
		agregado = true;
	}
	else {
		productoNodo* ant = getCab();
		productoNodo* aux = NULL;
		while (ant != NULL && !repetido && !agregado) {
			if (pnum == ant->getDato()) {
				repetido = true;
			}
			else {
				productoNodo* aux = ant->getSgte();
				if (ant->getSgte() == NULL || pnum < aux->getDato()) {
					productoNodo* nuevo = new productoNodo(pnum);
					nuevo->setSgte(aux);
					ant->setSgte(nuevo);
					largo++;
					agregado = true;
				}
				else {
					ant = ant->getSgte();
				}
			}
		}
	}
	return agregado;
}
bool listaProducto::agregarDescendente(int numD)
{
	bool numAgregado = false;
	if (esVacia() || numD > getCab()->getDato()) {
		agregarInicio(numD);
		numAgregado = true;
	}
	else {
		productoNodo* ant = getCab();
		productoNodo* current = nullptr;

		while (ant != nullptr && !numAgregado) {
			current = ant->getSgte();

			if (current == nullptr || numD >= current->getDato()) {

				if (current == nullptr || numD != current->getDato()) {
					productoNodo* nuevo = new productoNodo(numD);
					nuevo->setSgte(current);
					ant->setSgte(nuevo);
					largo++;
					numAgregado = true;
				}
			}

			ant = ant->getSgte();
		}
	}

	return numAgregado;
}
*/

void listaProducto::eliminarTodos()
{
	productoNodo* aux = getCab();
	while (aux != NULL) {
		setCab(getCab()->getSgte());
		delete aux;
		aux = getCab();
	}
	setLargo(0);
}