// CenfoChristmast.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include "ListaCategoria.h"
#include "Categoria.h"
#include "CategoriaNodo.h"
#include <iostream>
#include <stdlib.h>
#include "producto.h"
#include "listaProducto.h"
using namespace std;
listaProducto* listaProd = new listaProducto();
void agregarProductos() {
    string codigo;
    string nombre;
    float precio;
    int cantidad;
    int descuento;
    cout << "Codigo" << endl;
    cin >> codigo;
    cout << "Nombre" << endl;
    cin >> nombre;
    cout << "Precio" << endl;
    cin >> precio;
    cout << "Cantidad" << endl;
    cin >> cantidad;
    cout << "Descuento" << endl;
    cin >> descuento;
    producto Prod = producto(codigo, nombre, precio, cantidad, descuento);
    listaProd->agregarFinal(Prod);
}

void listarProductos() {
    listaProd->desplegar();
}

void listarProductosReves() {
    listaProd->desplegarReves();
}

void consultarPorNombre() {
    string nombre = "";
    int opc = -1;
    int cantidad = 0;
    while (nombre == "") {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "Digite el nombre del producto" << endl;
        cin >> nombre;
        cout << "===================================" << endl;
        producto Prod = listaProd->consultarPorNombre(nombre);
        cout << "Desea comprar el producto?" << endl;
        cout << "(1) Si" << endl;
        cout << "(2) No" << endl;
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            cout << "Cuantos desea comprar" << endl;
            cin >> cantidad;
            Prod.comprarProducto(cantidad);
            listaProd->eliminar(Prod.getCodigo());
            listaProd->agregarInicio(Prod);
            listaProd->consultarPorNombre(nombre);
            break;
        }
        case 2: {
            break;
        }
        }
    }
}

void cantidadBajo() {
    int cantidad = 0;
    cout << "Cuantos desea comprar" << endl;
    cin >> cantidad;
    listaProd->consultarCantidadLimite(cantidad);
}

void descuentos() {
    listaProd->cambioDePrecio();
}

void menu3() {
    cout << "(3)" << endl;
}

void eliminarPorNombre() {
    string nombre = "";
    int opc = -1;
    int cantidad = 0;
    while (nombre == "") {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "Digite el nombre del producto" << endl;
        cin >> nombre;
        cout << "===================================" << endl;
        producto Prod = listaProd->consultarPorNombre(nombre);
        cout << "Desea comprar el eliminar?" << endl;
        cout << "(1) Si" << endl;
        cout << "(2) No" << endl;
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            listaProd->eliminar(Prod.getCodigo());
            break;
        }
        case 2: {
            break;
        }
        }
    }
}

void agregarInventario() {
    string nombre = "";
    int cantidad = 0;
    cout << "Digite el nombre del producto" << endl;
    cin >> nombre;
    producto Prod = listaProd->consultarPorNombre(nombre);
    cout << "===================================" << endl;
    cout << "Digite cuantos productos desea annadir" << endl;
    cin >> cantidad;
    Prod.setCantidad(Prod.getCantidad() + cantidad);
    listaProd->eliminar(Prod.getCodigo());
    listaProd->agregarInicio(Prod);
    listaProd->consultarPorNombre(nombre);
}


//-------------------------------------
void menuClienteProducto() {
    producto Prod2 = producto("001", "Jabon", 1000.0, 10, 10);
    producto Prod3 = producto("002", "Cepillo Dental", 700.0, 10, 10);
    producto Prod4 = producto("003", "Shampoo", 7000.0, 10, 10);
    listaProd->agregarInicio(Prod2);
    listaProd->agregarInicio(Prod3);
    listaProd->agregarInicio(Prod4);
    int opc = -1;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Listar Productos" << endl;
        cout << "(2) Listar Productos descendentemente" << endl;
        cout << "(3) Consultar por nombre" << endl;
        cout << "(4) Consultar por cantidad de disponibles" << endl;
        cout << "(5) Consultar descuentos" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            listarProductos();
            break;
        }
        case 2: {
            listarProductosReves();
            break;
        }
        case 3: {
            consultarPorNombre();
            break;
        }
        case 4:{
            cantidadBajo();
            break;
        }
        case 5: {
            descuentos();
            break;
        }
        case 6: {
            descuentos();
            break;
        }
        }
    }
}

void menuAdminProducto() {
    producto Prod2 = producto("004", "Almohada", 8000.0, 10, 5);
    producto Prod3 = producto("006", "Funda", 8000.0, 10, 10);
    listaProd->agregarInicio(Prod2);
    listaProd->agregarInicio(Prod3);
    int opc = -1;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Listar Productos" << endl;
        cout << "(2) Listar Productos descendentemente" << endl;
        cout << "(3) Eliminar por nombre" << endl;
        cout << "(4) Consultar por cantidad de disponibles" << endl;
        cout << "(5) Consultar descuentos" << endl;
        cout << "(6) Annadir productos" << endl;
        cout << "(7) Annadir inventario" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            listarProductos();
            break;
        }
        case 2: {
            listarProductosReves();
            break;
        }
        case 3: {
            eliminarPorNombre();
            break;
        }
        case 4: {
            cantidadBajo();
            break;
        }
        case 5: {
            descuentos();
            break;
        }
        case 6: {
            agregarProductos();
            break;
        }
        case 7: {
            agregarInventario();
            break;
        }
        }
    }
}

void menuUsuarios() {
    listaUsuarios* lista = new listaUsuarios();
    int opc = -1;
    int dato = 0;
    string respuesta;
    usuario user;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU DE USUARIOS" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Agregar al inicio" << endl;
        cout << "(2) Agregar al final " << endl;
        cout << "(3) Agregar antes de...  " << endl;
        cout << "(4) Agregar despues de...  " << endl;
        cout << "(5) Modificar un usuario de la lista  " << endl;
        cout << "(6) Eliminar un usuario de la lista  " << endl;
        cout << "(7) Consultar un usuario de la lista" << endl;
        cout << "(8) Desplegar la lista" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;

        switch (opc) {
        case 1: {
            cout << "////AL INICIO////";
            bool perfil = false;
            int cedula;
            string nombre;
            string apellido;
            string correo;
            int telefono;

            int choice = -1;

            cout << "Sera un administrador? R/ 1-0" << endl;
            cin >> choice;
            switch (choice) {
            case 1: {
                perfil = true;
                break;
            }
            case 2: {
                perfil = false;
                break;
            }
            }
            cout << "Cual cedula va a tener?" << endl;
            cin >> cedula;
            cout << "Cual nombre va a tener?" << endl;
            cin >> nombre;
            cout << "Cual apellido va a tener?" << endl;
            cin >> apellido;
            cout << "Cual correo va a tener?" << endl;
            cin >> correo;
            cout << "Cual sera su numero de telefono?" << endl;
            cin >> telefono;
            usuario user = usuario(perfil, cedula, nombre, apellido, correo, telefono);
            lista->agregarInicio(user);
            break;
        }
        case 2: {
            cout << "////AL FINAL////";
            bool perfil = false;
            int cedula;
            string nombre;
            string apellido;
            string correo;
            int telefono;

            int choice = -1;

            cout << "Sera un administrador? R/ 1-0" << endl;
            cin >> choice;
            switch (choice) {
            case 1: {
                perfil = true;
                break;
            }
            case 2: {
                perfil = false;
                break;
            }
            }
            cout << "Cual cedula va a tener?" << endl;
            cin >> cedula;
            cout << "Cual nombre va a tener?" << endl;
            cin >> nombre;
            cout << "Cual apellido va a tener?" << endl;
            cin >> apellido;
            cout << "Cual correo va a tener?" << endl;
            cin >> correo;
            cout << "Cual sera su numero de telefono?" << endl;
            cin >> telefono;
            usuario user = usuario(perfil, cedula, nombre, apellido, correo, telefono);
            lista->agregarFinal(user);
            break;
        }
        case 3: {
            int ref = 0;
            cout << "Usuario de referencia en la lista?->";
            cin >> ref;
            cout << "Usuario que desea agregar antes de " << ref << " ->";
            bool perfil = false;
            int cedula;
            string nombre;
            string apellido;
            string correo;
            int telefono;

            int choice = -1;

            cout << "Sera un administrador? R/ 1-0" << endl;
            cin >> choice;
            switch (choice) {
            case 1: {
                perfil = true;
                break;
            }
            case 2: {
                perfil = false;
                break;
            }
            }
            cout << "Cual cedula va a tener?" << endl;
            cin >> cedula;
            cout << "Cual nombre va a tener?" << endl;
            cin >> nombre;
            cout << "Cual apellido va a tener?" << endl;
            cin >> apellido;
            cout << "Cual correo va a tener?" << endl;
            cin >> correo;
            cout << "Cual sera su numero de telefono?" << endl;
            cin >> telefono;
            usuario user = usuario(perfil, cedula, nombre, apellido, correo, telefono);
            if (lista->agregarAntesDe(user, ref))
                cout << "Agregado correctamente" << endl;
            else
                cout << "No se pudo agregar" << endl;
            break;
        }
        case 4: {
            int ref = 0;
            cout << "Usuario de referencia en la lista?->";
            cin >> ref;
            cout << "Usuario que desea agregar despues de " << ref << " ->";
            bool perfil = false;
            int cedula;
            string nombre;
            string apellido;
            string correo;
            int telefono;

            int choice = -1;

            cout << "Sera un administrador? R/ 1-0" << endl;
            cin >> choice;
            switch (choice) {
            case 1: {
                perfil = true;
                break;
            }
            case 2: {
                perfil = false;
                break;
            }
            }
            cout << "Cual cedula va a tener?" << endl;
            cin >> cedula;
            cout << "Cual nombre va a tener?" << endl;
            cin >> nombre;
            cout << "Cual apellido va a tener?" << endl;
            cin >> apellido;
            cout << "Cual correo va a tener?" << endl;
            cin >> correo;
            cout << "Cual sera su numero de telefono?" << endl;
            cin >> telefono;
            usuario user = usuario(perfil, cedula, nombre, apellido, correo, telefono);
            if (lista->agregarDespuesDe(user, ref))
                cout << "Agregado correctamente" << endl;
            else
                cout << "No se pudo agregar" << endl;
            break;
        }
        case 5: {
            cout << "Cedula del usuario que desea modificar de la lista: ";
            cin >> dato;
            bool perfil = false;
            int cedula;
            string nombre;
            string apellido;
            string correo;
            int telefono;

            int choice = -1;

            cout << "Sera un administrador? R/ 1-0" << endl;
            cin >> choice;
            switch (choice) {
            case 1: {
                perfil = true;
                break;
            }
            case 2: {
                perfil = false;
                break;
            }
            }
            cout << "Cual cedula va a tener?" << endl;
            cin >> cedula;
            cout << "Cual nombre va a tener?" << endl;
            cin >> nombre;
            cout << "Cual apellido va a tener?" << endl;
            cin >> apellido;
            cout << "Cual correo va a tener?" << endl;
            cin >> correo;
            cout << "Cual sera su numero de telefono?" << endl;
            cin >> telefono;
            usuario user = usuario(perfil, cedula, nombre, apellido, correo, telefono);
            if (lista->modificar(dato, user))
                cout << "El numero " << dato << " ha sido modificado exitosamente" << endl;
            else
                cout << "El numero " << dato << " no está en la lista" << endl;

            break;
        }
        case 6: {
            cout << "Cedula del usuario que desea eliminar de la lista: ";
            cin >> dato;
            if (lista->eliminar(dato))
                cout << "El numero " << dato << " ha sido eliminado exitosamente" << endl;
            else
                cout << "El numero " << dato << " no está en la lista" << endl;

            break;
        }
        case 7: {
            int choice = -1;

            cout << "1 - Busqueda por cedula" << endl;
            cout << "2 - Busqueda por nombre" << endl;
            cout << "-----------------------" << endl;

            cin >> choice;
            switch (choice) {
            case 1:
                cout << "Cedula del usuario que desea encontrar ";
                cin >> dato;
                lista->consultarCedula(dato);
                break;

            case 2:
                cout << "Nombre del usuario que desea encontrar ";
                cin >> dato;
                lista->consultarNombre(respuesta);
                break;
            }
            break;
        }
        case 8: {
            int choice = -1;

            cout << "1 - Desplegar filtrado" << endl;
            cout << "2 - Desplegar informacion total" << endl;
            cout << "-----------------------" << endl;

            cin >> choice;
            switch (choice) {
            case 1:
                lista->desplegar();
                break;

            case 2:
                lista->desplegarTodo();
                break;
            }
            break;
        }
        case 0:
            cout << "Finalizando el programa... ";
            break;
        default:
            cout << "Opcion no válida..." << endl;
        }
        cout << "\n\n";
        system("pause");
        system("cls");
    }
}

void menuAdminCategorias(ListaCategoria* listaCategorias) {
    int opc = -1;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "         MENU DE CATEGORIAS" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Crear Categoría" << endl;
        cout << "(2) Agregar Categoría" << endl;
        cout << "(3) Obtener Categoría" << endl;
        cout << "(4) Eliminar Categoría" << endl;
        cout << "(0) Regresar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            listaCategorias->CrearListaCategoria();
            break;
        }
        case 2: {
            listaCategorias->AgregarCategoria();
            break;
        }
        case 3: {
            listaCategorias->ObtenerCategoria();
            break;
        }
        case 4: {
            listaCategorias->EliminarCategoria();
            break;
        }
        }
    }
}

void menuClienteCategorias(ListaCategoria* listaCategorias) {
    int opc = -1;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "         MENU DE CATEGORIAS" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Obtener Categoría" << endl;
        cout << "(0) Regresar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            listaCategorias->ObtenerCategoria();
            break;
        }
        }
    }
}

int main() {
    ListaCategoria* listaCategorias = new ListaCategoria();

    int opc = -1;
    while (opc != 0) {
        cout << "----------------------------------" << endl;
        cout << "              MENU" << endl;
        cout << "----------------------------------" << endl;
        cout << "(1) Productos Usuario" << endl;
        cout << "(2) Productos Administrador" << endl;
        cout << "(3) Categorias Usuario" << endl;
        cout << "(4) Categorias Administrador" << endl;
        cout << "(0) Finalizar" << endl;
        cout << "Opcion seleccionada ->";
        cin >> opc;
        cout << "===================================" << endl;
        switch (opc) {
        case 1: {
            menuClienteProducto();
            break;
        }
        case 2: {
            menuAdminProducto();
            break;
        }
        case 3: {
            menuClienteCategorias(listaCategorias);
            break;
        }
        case 4: {
            menuAdminCategorias(listaCategorias);
            break;
        }
        }
    }

    // Liberar memoria al finalizar el programa
    delete listaCategorias;

    return 0;
}


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
