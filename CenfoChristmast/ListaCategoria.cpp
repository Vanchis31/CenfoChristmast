// ListaCategoria.cpp
#include "ListaCategoria.h"
#include <iostream>

ListaCategoria::ListaCategoria() : primero(nullptr) {}

ListaCategoria::~ListaCategoria() {
    CategoriaNodo* actual = primero;
    while (actual) {
        CategoriaNodo* siguiente = actual->getSiguiente();
        delete actual->getCategoria();
        delete actual;
        actual = siguiente;
    }
}

void ListaCategoria::CrearListaCategoria() {
    if (!primero) {
        std::cout << "Lista de categor�as creada.\n";
    }
    else {
        std::cout << "Error: La lista de categor�as ya existe.\n";
    }
}

void ListaCategoria::AgregarCategoria() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la categor�a: ";
    std::cin >> nombre;

    Categoria* nuevaCategoria = new Categoria(nombre);
    CategoriaNodo* nuevoNodo = new CategoriaNodo(nuevaCategoria);
    nuevoNodo->setSiguiente(primero);
    primero = nuevoNodo;

    std::cout << "Categor�a '" << nombre << "' agregada exitosamente.\n";
}

void ListaCategoria::ObtenerCategoria() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la categor�a: ";
    std::cin >> nombre;

    CategoriaNodo* actual = primero;
    while (actual) {
        if (actual->getCategoria()->getNombre() == nombre) {
            std::cout << "Categor�a '" << nombre << "' encontrada.\n";
            return;
        }
        actual = actual->getSiguiente();
    }

    std::cout << "Error: La categor�a '" << nombre << "' no existe.\n";
}

void ListaCategoria::EliminarCategoria() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la categor�a: ";
    std::cin >> nombre;

    CategoriaNodo* actual = primero;
    CategoriaNodo* anterior = nullptr;

    while (actual) {
        if (actual->getCategoria()->getNombre() == nombre) {
            if (anterior) {
                anterior->setSiguiente(actual->getSiguiente());
            }
            else {
                primero = actual->getSiguiente();
            }

            std::cout << "Categor�a '" << nombre << "' eliminada exitosamente.\n";
            delete actual->getCategoria();
            delete actual;
            return;
        }

        anterior = actual;
        actual = actual->getSiguiente();
    }

    std::cout << "Error: La categor�a '" << nombre << "' no existe.\n";
}
