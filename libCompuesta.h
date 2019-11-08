#ifndef LIBCOMPUESTA_H_INCLUDED
#define LIBCOMPUESTA_H_INCLUDED
#include "liblistas2.h"
#include "libarboles.h"
#include "libUsuarios.h"
#include "libCanciones.h"



typedef struct stCeldaArbolCancion
{
    stCancion c;
    nodoArbolCancion * arbol;
}stCeldaArbolCancion;


typedef struct stCeldaLista2Cancion
{
    stUsuario usr;
    nodoLista2Cancion* lista2Canciones;
} stCeldaLista2Cancion;

/*
agregarUsuario() // crea un nuevo usuario en el arreglo
buscarUsuario() // busca un usuario por idUsuario y retorna la posición que ocupa en el arreglo
mostrarUsuarios() // muestra todo el arreglo de listas, cada usuario con sus canciones escuchadas
agregarCancionToUsuario() // agrega una Cancion al Usuario correspondiente
limpiarArregloDeListas() // esta función “vacía” todo el arreglo de listas, dejando la estructura preparada para volver a trabajar
persistirCancionesEscuchadas() // esta función realizará la persistencia de todas las canciones escuchadas en el archivo correspondiente
*/

///* FUNCIONES LISTAS Y ARBOLES ////
nodoLista2Cancion* pasarArbol2Lista2(nodoArbolCancion* A, nodoLista2Cancion* lista); ///agrega en orden de ID

///* FUNCIONES ARREGLOS DE LISTAS DOBLES////
int altaArregloLista2 (stCeldaLista2Cancion arreglo[], stCancion cancion, int validos);
int buscaPosGeneroArreglo (stCeldaLista2Cancion arreglo[],char genero[20],int validos);
int agregarGeneroArregloLista2 (stCeldaLista2Cancion arreglo[],char genero[],int validos);


///* FUNCIONES ARREGLO DE ARBOLES //////
int altaArregloArbol (stCeldaArbolCancion arreglo[], stCancion cancion, int validos);
int buscaPosserieArregloArbol (stCeldaArbolCancion arreglo[],int tipo, int validos);
int agregarTipoArregloArbol (stCeldaArbolCancion arreglo[], int tipo ,int validos);
int pasarArreglo2ADACancion(stCancion canciones[], int valCanciones, stCeldaArbolCancion ADACancion[], int valArbCan);
void muestraUnArbolCanciones(nodoArbolCancion* Arbol);
void mostrarADACanciones(stCeldaArbolCancion arregloArbolesCancion[], int val);

///*OTRAS FUNCIONES ////
int cuentaRegistrosArCanciones ();
int pasaRegistrosArCanciones2arreglo(stCancion arreglo[], int val);

#endif // LIBCOMPUESTA_H_INCLUDED
