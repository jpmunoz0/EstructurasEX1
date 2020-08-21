
#ifndef EXAMEN_1_ORDENAMIENTOS_STRUCTS_H
#define EXAMEN_1_ORDENAMIENTOS_STRUCTS_H

#include "Templates.h"

struct Nodo;
struct ListaDoble;

struct Nodo{
    Nodo * siguiente, *anterior;
    int dato;

    Nodo(int dato){
        siguiente = anterior = nullptr;
        this->dato = dato;
    }
};

struct ListaDoble{
    Nodo *primerNodo, *ultimoNodo;

    ListaDoble(){
        primerNodo = ultimoNodo = nullptr;
    }

    bool isEmpty();
    void insertar(int);
    void print();
    int size();
    Nodo * getPosition(int);
};

void insertSort(ListaDoble*);
void bubbleSort(ListaDoble*);
void selectSort(ListaDoble*);
void quickSort(ListaDoble*);
void quickSortAux(ListaDoble*,int,int);
void bucketSort(ListaDoble*,int);
void bucketSortAux(SimpleList<ListaDoble*>*, ListaDoble*, int, int);
void insertSortNoPrint(ListaDoble*);
void radixSort(ListaDoble*);
void radixSortAux(ListaDoble*, bool);
int mayor(ListaDoble*);
int cuentaDigitos(int);
int getDigito(int,int);

#endif //EXAMEN_1_ORDENAMIENTOS_STRUCTS_H
