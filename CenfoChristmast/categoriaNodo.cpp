// CategoriaNodo.cpp
#include "CategoriaNodo.h"

CategoriaNodo::CategoriaNodo(Categoria* categoria)
    : CategoriaPtr(categoria), siguiente(nullptr) {}

CategoriaNodo::~CategoriaNodo() {
}

Categoria* CategoriaNodo::getCategoria() const {
    return CategoriaPtr;
}

CategoriaNodo* CategoriaNodo::getSiguiente() const {
    return siguiente;
}

void CategoriaNodo::setSiguiente(CategoriaNodo* siguiente) {
    this->siguiente = siguiente;
}
