
#include <iostream>
#include "Structs.h"
using namespace std;

bool ListaDoble::isEmpty() {
    return primerNodo == nullptr;
}

void ListaDoble::insertar(int dato) {
    if (this->isEmpty())
        primerNodo = ultimoNodo = new Nodo(dato);
    else{
        ultimoNodo->siguiente = new Nodo(dato);
        ultimoNodo->siguiente->anterior = ultimoNodo;
        ultimoNodo = ultimoNodo->siguiente;
    }
}

void ListaDoble::print() {
    Nodo * temp = primerNodo;
    cout << " [ ";
    while (temp != nullptr){
        cout << temp->dato << " ";
        temp = temp->siguiente;
    }
    cout << "]\n";
}

int ListaDoble::size() {
    Nodo * temp = primerNodo;
    int count = 0;
    while (temp != nullptr){
        count++;
        temp = temp->siguiente;
    }
    return count;
}

Nodo * ListaDoble::getPosition(int position) {
    Nodo * temp = primerNodo;
    if (position < this->size()){
        for (int i = 0; i < position; i++)
            temp = temp->siguiente;
        return  temp;
    }
    return nullptr;
}

