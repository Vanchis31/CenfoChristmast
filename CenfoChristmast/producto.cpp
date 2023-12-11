#include "producto.h"

producto::producto() {
	this->codigo = "0";
	this->nombre = "nombre";
	this->precio = 0.0;
	this->cantidadDisponible = 0;
	this->descuento = 0;
}

producto::producto(string codigo, string nombre, float precio, int cantidadDisponible, int descuento) {
	this->codigo = codigo;
	this->nombre = nombre;
	this->precio = precio - (precio / 100 * descuento);
	this->cantidadDisponible = cantidadDisponible;
	this->descuento = descuento;
}

string producto::getCodigo() {
	return this->codigo;
}

string producto::getNombre() {
	return this->nombre;
}

float producto::getPrecio() {
	return this->precio;
}

int producto::getCantidad() {
	return this->cantidadDisponible;
}

int producto::getDescuento() {
	return this->descuento;
}

void producto::setNombre(string nombre) {
	this->nombre = nombre;
}

void producto::setPrecio(float precio) {
	if (this->descuento = 0) {
		this->precio = precio;
	}
	else this->precio = precio + (precio * 100 / this->descuento);
}

void producto::setCantidad(int cantidad) {
	this->cantidadDisponible = cantidad;
}

void producto::setDescuento(int descuento) {
	this->descuento = descuento;
}

void producto::comprarProducto(int cantidad) {
	this->cantidadDisponible = this->cantidadDisponible - cantidad;
}