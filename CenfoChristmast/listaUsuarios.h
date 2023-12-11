#pragma once
#include "usuario.h"
#include "usuarioNodo.h"
class listaUsuarios
{
private:
	usuarioNodo* cab;
	int largo;

public:
	listaUsuarios();
	~listaUsuarios();

	usuarioNodo* getCab();
	int getLargo();

	void setCab(usuarioNodo*);
	void setLargo(int);

	/*UTILITARIOS */
	bool esVacia();
	usuarioNodo* dirNodo(int);
	usuarioNodo* dirAnterior(int);
	usuarioNodo* dirUltimo();




	void agregarInicio(usuario);
	void agregarFinal(usuario);
	bool agregarAntesDe(usuario, int);
	bool agregarDespuesDe(usuario, int);

	bool modificar(int, usuario);

	bool eliminar(int);

	void consultarNombre(string);
	void consultarCedula(int);


	void desplegar();
	void desplegarTodo();
};

