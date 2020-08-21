#include <iostream>
#include "Structs.h"
using namespace std;

int main() {
    ListaDoble * lista = new ListaDoble();
    lista->insertar(30);
    lista->insertar(3);
    lista->insertar(1);
    lista->insertar(10);
    lista->insertar(500);
    lista->insertar(33);
    lista->insertar(413);
    lista->insertar(2);
    lista->insertar(5);
    lista->insertar(6);
    lista->insertar(54);
    lista->insertar(57);
    lista->insertar(165);
    lista->insertar(32);
    lista->insertar(39);
    lista->insertar(92);
    lista->insertar(65);
    lista->insertar(705);
    lista->insertar(23);
    lista->insertar(1234);
    lista->insertar(43);
    lista->insertar(55);
    lista->insertar(98);
    lista->print();
    cout << "\n";

    //insertSort(lista);
    //bubbleSort(lista);
    //selectSort(lista);
    //quickSort(lista);
    //bucketSort(lista,10);
    //radixSort(lista);

    cout << "\n";
    lista->print();

    return 0;
}