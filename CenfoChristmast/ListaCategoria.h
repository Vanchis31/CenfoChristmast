// ListaCategoria.h
#ifndef LISTACATEGORIA_H
#define LISTACATEGORIA_H

#include "Categoria.h"
#include "CategoriaNodo.h"

class ListaCategoria {
public:
    ListaCategoria();
    ~ListaCategoria();

    void CrearListaCategoria();
    void AgregarCategoria();
    void ObtenerCategoria();
    void EliminarCategoria();

private:
    CategoriaNodo* primero;
};

#endif // LISTACATEGORIA_H
