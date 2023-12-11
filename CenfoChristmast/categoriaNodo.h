// CategoriaNodo.h
#ifndef CATEGORIANODO_H
#define CATEGORIANODO_H

#include "Categoria.h"

class CategoriaNodo {
public:
    CategoriaNodo(Categoria* categoria);
    ~CategoriaNodo();

    Categoria* getCategoria() const;
    CategoriaNodo* getSiguiente() const;
    void setSiguiente(CategoriaNodo* siguiente);

private:
    Categoria* CategoriaPtr;
    CategoriaNodo* siguiente;
};

#endif // CATEGORIANODO_H
