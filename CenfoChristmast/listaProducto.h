#pragma once
#include "productoNodo.h"
#include "producto.h"
class listaProducto
{
private:
	productoNodo* cab;
	int largo;
public:
	listaProducto();
	~listaProducto();

	productoNodo* getCab();
	int getLargo();

	void setCab(productoNodo*);
	void setLargo(int);

	bool esVacia();
	productoNodo* dirNodo(string);
	productoNodo* dirAnterior(string);
	productoNodo* dirSiguiente(string);
	productoNodo* dirUltimo();

	void agregarInicio(producto);
	void agregarFinal(producto); 
	//bool agregarAntesDe(int, int);
	//bool agregarDespuesDe(int, int);
	//bool agregarAscendente(int);
	//bool agregarOrdenadoDescendente(int dato);
	
	producto consultarPorNombre(string);
	void consultarCantidadLimite(int);
	void cambioDePrecio();
	void desplegar();
	void desplegarReves();


	/*bool completarSecuencia();Considere una lista ordenada ascendentemente, modifique la lista para que incluya los
		valores que hacen falta para completar la secuencia iniciando con el primer valor de la lista y finalizando con el
		�ltimo valor de la lista.Ejemplo Si la lista es igual a 4 - 7 - 10. Deber� modificar la lista para que la lista sea igual a 4 - 5 - 6 -
		7 - 8 - 9 - 10. Es decir se agregaron los valores 5, 6, 8, 9. Esto se debe realizar en un O(n) y es modificadora.*/

	bool eliminar(string);

	void eliminarTodos();
};

