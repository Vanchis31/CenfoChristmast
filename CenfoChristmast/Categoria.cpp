
#include "Categoria.h"
#include <iostream>

Categoria::Categoria() {}

Categoria::Categoria(std::string nombre) : Nombre(nombre) {}

Categoria::~Categoria() {
    for (Articulo* articulo : ListaArticulos) {
        delete articulo;
    }
    ListaArticulos.clear();
}

void Categoria::CrearCategoria(std::string nombre) {

    std::cout << "Categoría creada exitosamente: " << nombre << "\n";
}

void Categoria::ObtenerCategoria(std::string nombre) {
    std::cout << "Categoría encontrada: " << nombre << "\n";
}

std::string Categoria::getNombre() const {
    return Nombre;
}
