// Categoria.h
#ifndef CATEGORIA_H
#define CATEGORIA_H

#include <string>
#include <vector>

class Articulo;

class Categoria {
public:
    Categoria();
    Categoria(std::string nombre);
    ~Categoria();

    void CrearCategoria(std::string nombre);
    void ObtenerCategoria(std::string nombre);
    std::string getNombre() const;  // Nuevo método para obtener el nombre

private:
    std::string Nombre;
    std::vector<Articulo*> ListaArticulos;
};

#endif // CATEGORIA_H
