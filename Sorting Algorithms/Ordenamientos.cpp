
#include <iostream>
#include "Structs.h"
#include "Templates.h"
#include <cmath>
using namespace std;

void insertSort(ListaDoble * lista){
    for (int i = 1; i < lista->size(); i++){
        int aux = lista->getPosition(i)->dato;
        int j = i - 1;
        for (j; j >= 0 && lista->getPosition(j)->dato > aux; j--) {
            lista->getPosition(j + 1)->dato = lista->getPosition(j)->dato;
        }
        lista->getPosition(j+1)->dato = aux;
        cout << "lista[" << j + 1 << "] = " << aux << "\n";
        lista->print();
    }
}

void bubbleSort(ListaDoble * lista){
    for (int i = 1; i < lista->size(); i++){
        cout << "Loop #" << i << "\n";
        for (int j = 0; j < lista->size() - i; j++){
            if (lista->getPosition(j)->dato > lista->getPosition(j+1)->dato){
                int temp = lista->getPosition(j)->dato;
                lista->getPosition(j)->dato = lista->getPosition(j+1)->dato;
                lista->getPosition(j+1)->dato = temp;
                cout << "Swap:";
                lista->print();
            }
        }
    }
}

void selectSort(ListaDoble * lista){
    for (int i = 0; i < lista->size() - 1; i++){
        cout << "Loop #" << i << "\n";
        int min = i;
        for (int j = i + 1; j < lista->size(); j++){
            if (lista->getPosition(j)->dato < lista->getPosition(min)->dato){
                min = j;
            }
        }
        if (min != i){
            int temp = lista->getPosition(i)->dato;
            lista->getPosition(i)->dato = lista->getPosition(min)->dato;
            lista->getPosition(min)->dato = temp;
            cout << "Swap:";
            lista->print();
        }
    }
}

void quickSort(ListaDoble * lista){
    quickSortAux(lista, 0, lista->size() - 1);
}

void quickSortAux(ListaDoble * lista, int low, int high){
    cout << "Recursion from: " << low << " to " << high << "\n";
    if (low < high){
        int mid = lista->getPosition((low+high)/2)->dato;
        int l = low;
        int h = high;
        while (l < h){
            while(l < high && lista->getPosition(l)->dato < mid)
                l++;
            while(h > low && lista->getPosition(h)->dato > mid)
                h--;
            if (l <= h){
                int temp = lista->getPosition(l)->dato;
                lista->getPosition(l)->dato = lista->getPosition(h)->dato;
                lista->getPosition(h)->dato = temp;
                l++;
                h--;
                cout << "Swap:";
                lista->print();
            }
        }
        if (low<h)
            quickSortAux(lista,low,h);
        if (l<high)
            quickSortAux(lista,l,high);
    }
}

void bucketSort(ListaDoble * lista, int bucketAmount) {
    if (!lista->isEmpty() && bucketAmount != 0) {
        SimpleList<ListaDoble*> *buckets = new SimpleList<ListaDoble *>();
        for (int i = 0; i < bucketAmount; i++)
            buckets->insert(new ListaDoble());
        ListaDoble * listaPositivos = new ListaDoble();
        ListaDoble * listaNegativos = new ListaDoble();
        for (int i = 0; i < lista->size(); i++){
            if (lista->getPosition(i)->dato >= 0)
                listaPositivos->insertar(lista->getPosition(i)->dato);
            else
                listaNegativos->insertar(lista->getPosition(i)->dato);
        }
        if (listaNegativos->isEmpty())
            bucketSortAux(buckets, listaPositivos, bucketAmount, 0);
        else if (listaPositivos->isEmpty())
            bucketSortAux(buckets, listaNegativos, bucketAmount, 0);
        else {
            int smallHalfBucket = (bucketAmount/2);
            int bigHalfBucket = (bucketAmount/2) + (bucketAmount%2);
            bucketSortAux(buckets, listaNegativos, smallHalfBucket, 0);
            bucketSortAux(buckets, listaPositivos, bigHalfBucket, smallHalfBucket);
        }
        for (int i = 0; i < buckets->size(); i++) {
            insertSortNoPrint(buckets->getPosition(i)->data);
            cout << "Bucket #" << i;
            buckets->getPosition(i)->data->print();
        }
        int index = 0;
        for (int i = 0; i < buckets->size(); i++) {
            for (int j = 0; j < buckets->getPosition(i)->data->size(); j++) {
                lista->getPosition(index)->dato = buckets->getPosition(i)->data->getPosition(j)->dato;
                index++;
            }
        }
    }
}

void bucketSortAux(SimpleList<ListaDoble*> *buckets, ListaDoble * lista, int bucketAmount, int offset){
    int max = mayor(lista);
    int divisor = ceil((max + 1) / float(bucketAmount));
    for (int i = 0; i < lista->size(); i++) {
        int bucketPos = floor(abs(lista->getPosition(i)->dato) / float(divisor)) + offset;
        if (lista->getPosition(i)->dato < 0)
            bucketPos = ((bucketAmount-1)-bucketPos);
        buckets->getPosition(bucketPos)->data->insertar(lista->getPosition(i)->dato);
    }
}

void insertSortNoPrint(ListaDoble * lista){
    for (int i = 1; i < lista->size(); i++){
        int aux = lista->getPosition(i)->dato;
        int j = i - 1;
        for (j; j >= 0 && lista->getPosition(j)->dato > aux; j--) {
            lista->getPosition(j + 1)->dato = lista->getPosition(j)->dato;
        }
        lista->getPosition(j+1)->dato = aux;
    }
}

int mayor(ListaDoble * lista){
    int max = abs(lista->getPosition(0)->dato);
    for (int i = 1; i < lista->size(); i++) {
        if (abs(lista->getPosition(i)->dato) > max)
            max = abs(lista->getPosition(i)->dato);
    }
    return max;
}

int cuentaDigitos(int num){
    if (num < 10)
        return 1;
    else
        return 1 + cuentaDigitos(num/10);
}

int getDigito(int num, int index){
    if (index >= cuentaDigitos(num))
        return 0;
    else if (index == 0)
        return num%10;
    else
        return getDigito(num/10, index-1);
}

void radixSort(ListaDoble * lista){
    if (!lista->isEmpty()){
        ListaDoble * listaPositivos = new ListaDoble();
        ListaDoble * listaNegativos = new ListaDoble();
        for (int i = 0; i < lista->size(); i++){
            if (lista->getPosition(i)->dato >= 0)
                listaPositivos->insertar(lista->getPosition(i)->dato);
            else
                listaNegativos->insertar(lista->getPosition(i)->dato);
        }
        radixSortAux(listaNegativos, true);
        radixSortAux(listaPositivos, false);
        int index = 0;
        for (int i = 0; i < listaNegativos->size(); i++) {
            lista->getPosition(index)->dato = listaNegativos->getPosition(i)->dato;
            index++;
        }
        for (int i = 0; i < listaPositivos->size(); i++) {
            lista->getPosition(index)->dato = listaPositivos->getPosition(i)->dato;
            index++;
        }
    }
}

void radixSortAux(ListaDoble * lista, bool negativo){
    if (!lista->isEmpty()){
        int maxDigitos = cuentaDigitos(mayor(lista));
        SimpleList<Queue<int>*> * colas = new SimpleList<Queue<int>*>();
        for (int i = 0; i < 10; i++)
            colas->insert(new Queue<int>());
        for (int i = 0; i < maxDigitos; i++){
            cout << "\nRecorrido #:" << i + 1 << "\n";
            for (int j = 0; j < lista->size(); j++) {
                int colaNum = getDigito(abs(lista->getPosition(j)->dato), i);
                if (lista->getPosition(j)->dato < 0)
                    colaNum = (9 - colaNum);
                colas->getPosition(colaNum)->data->queue(lista->getPosition(j)->dato);
            }
            int index = 0;
            for (int i = 0; i < colas->size(); i++) {
                if (negativo)
                    cout << "Bucket #" << -(9 - i);
                else
                    cout << "Bucket #" << i;
                colas->getPosition(i)->data->print();
                Node<int> * temp = colas->getPosition(i)->data->first;
                while(temp != nullptr){
                    lista->getPosition(index)->dato = temp->data;
                    temp = temp->next;
                    colas->getPosition(i)->data->dequeue();
                    index++;
                }
            }
            cout << "\n";
        }
    }
}