#include "libcompuesta.h"
#include "windows.h"
#include "stdio.h"
#include "libarboles.h"
#include "libCanciones.h"
#define arSeries "series.dat"

///* FUNCIONES LISTAS Y ARBOLES ////
nodoLista2Cancion* pasarArbol2Lista2(nodoArbolCancion* A, nodoLista2Cancion* lista) ///no ordena los primeros 3
{
    if (A!=NULL)
    {
        nodoLista2Cancion* aux;
        aux = crearNodo2(A->c);
        lista=agregarenOrden2(lista, aux); //el primero lo agrega, sabiendo que la lista esta vacia
        lista= pasarArbol2Lista2(A->der, lista); ///le paso los menores
        lista= pasarArbol2Lista2(A->izq, lista); ///le paso los mayores
    }

    return lista;
}

///* FUNCIONES ARREGLOS DE LISTAS DOBLES////
int altaArregloLista2 (stCeldaLista2Cancion array[], stCancion cancion, int validos) ///arreglo de generos
{
    nodoLista2Cancion * aux= crearNodo2(cancion);
    int pos = buscaPosGeneroArreglo (array, cancion.genero, validos);

    if (pos == -1)
    {
        validos = agregarGeneroArregloLista2(array, cancion.genero, validos);
        pos = validos -1;
    }
    array[pos].lista2Canciones = agregarenOrden2(array[pos].lista2Canciones,aux);

    return validos;
}

int buscaPosGeneroArreglo (stCeldaLista2Cancion array[],char genero[20],int validos)
{
    int rta = -1;
    int i = 0;

    while ((i<validos) && (rta ==-1))
    {
        nodoLista2Cancion* X= array[i].lista2Canciones;
        if (strcmpi(X->c.genero,genero) ==0)
        {
            rta =i;
        }
        i++;
    }
    return rta;
}

int agregarGeneroArregloLista2 (stCeldaLista2Cancion array[],char genero[],int validos)
{
    nodoLista2Cancion* temporal= array[validos].lista2Canciones;
    strcpy(temporal->c.genero,genero);

    array[validos].lista2Canciones = inicLista2();

    validos++;

    return validos;
}


///* FUNCIONES ARREGLO DE ARBOLES //////
int altaArregloArbol (stCeldaArbolCancion array[], stCancion cancion, int validos)
{
    nodoArbolCancion * aux= crearNodoA(cancion);
    int pos = buscaPosTipoArregloArbol(array, cancion.tipo, validos);

    if (pos == -1)
    {
        validos = agregarTipoArregloArbol(array, cancion.tipo, validos);
        pos = validos -1;
    }
    array[pos].arbol = agregarA(array[pos].arbol,aux);

    return validos;
}

int buscaPosTipoArregloArbol (stCeldaArbolCancion array[],int tipo ,int validos)
{
    int rta = -1;
    int i = 0;

    while ((i<validos) && (rta ==-1))
    {
        nodoArbolCancion* A = array[i].arbol;
        if (A->c.tipo == tipo)
        {
            rta = i;
        }
        i++;
    }
    return rta;
}


int agregarTipoArregloArbol (stCeldaArbolCancion array[], int tipo ,int validos)
{
    array[validos].c.tipo= tipo;
    array[validos].arbol = inicArbol();
    validos++;

    return validos;
}

int pasarArreglo2ADACancion(stCancion canciones[], int valCanciones, stCeldaArbolCancion ADACancion[], int valArbCan)
{
    for (int i=0; i<valCanciones; i++)
    {
        altaArregloArbol(ADACancion, canciones[i], valArbCan);
    }
    return valArbCan;
}

void muestraUnArbolCanciones(nodoArbolCancion* Arbol)
{
    if (Arbol != NULL)
    {
        muestraUnArbolCanciones(Arbol->izq);
        muestraUnaCancion(Arbol->c);
        muestraUnArbolCanciones(Arbol->der);

    }
}

void mostrarADACanciones(stCeldaArbolCancion arregloArbolesCancion[], int val)
{
    for (int i=0; i<val; i++)
    {
        muestraUnArbolCanciones(arregloArbolesCancion[i].arbol);
    }
}

///* OTRAS FUNCIONES////
int cuentaRegistrosArCanciones ()
{
    FILE* pArchiCanciones= fopen(arCanciones, "rb");
    int i=0;
    if (pArchiCanciones)
    {
        stCancion auxc;
        while (fread(&auxc, sizeof(stCancion), 1, pArchiCanciones)>0);
        i++;
    }
    return i;
}

int pasaRegistrosArCanciones2arreglo(stCancion arreglo[], int val)
{
    FILE* pArchiCanciones= fopen(arCanciones, "rb");
    if (pArchiCanciones)
    {
        stCancion auxc;
        while (fread(&auxc, sizeof(stCancion), 1, pArchiCanciones)>0);
        arreglo[val]= auxc;
        val++;
    }
    return val;
}

/*
///* FUNCIONES ARCHIVO Y LISTAS - con otra estructura//////
stnodo* cargarNodo_desde_Archivo(stnodo* lista) ///es un BUCLE DE CARGA que va agregando a la lista desde un archivo
{

    stnodo* nuevoNodo;
    FILE* pArchi=fopen(series, "rb");
    if (pArchi!=NULL)
    {
        while (fread(&legajo, sizeof(int), 1, pArchi)>0)
        {
            nuevoNodo=crearNodo(legajo);
            list=AddStart(list, nuevoNodo);
        }
        fclose(pArchi);
    }
    return list;
}

stnodo* archi_A_list_ORDENADO(stnodo*list)
{
    int legajo;
    stnodo* nuevoNodo;
    FILE* pArchi=fopen("elementos", "rb");
    if (pArchi!=NULL)
    {
        while (fread(&legajo, sizeof(int), 1, pArchi)>0)
        {
            nuevoNodo=crearNodo(legajo);
            list=Add_In_Order(list, nuevoNodo);
        }
        fclose(pArchi);
    }
    return list;
}

*/
