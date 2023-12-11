#pragma once
#include <iostream>
#include <string>
using namespace std;

class producto
{
private:
	string codigo;
	string nombre;
	float precio;
	int cantidadDisponible;
	int descuento;
public:
	producto();
	producto(string, string, float, int, int);
	string getCodigo();
	string getNombre();
	float getPrecio();
	int getCantidad();
	int getDescuento();
	void setNombre(string);
	void setPrecio(float);
	void setCantidad(int);
	void setDescuento(int);
	void comprarProducto(int);
};


