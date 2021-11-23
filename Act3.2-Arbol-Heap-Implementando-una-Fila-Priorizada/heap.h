//
// Created by droid on 11/11/2021.
//

//#ifndef ACT3_2_ARBOL_HEAP_IMPLEMENTANDO_UNA_FILA_PRIORIZADA_HEAP_H
#define ACT3_2_ARBOL_HEAP_IMPLEMENTANDO_UNA_FILA_PRIORIZADA_HEAP_H
#ifndef HEAP_H_
#define HEAP_H_

#include <string>
#include <sstream>
//#include "exception.h"
#include <iostream>

using namespace std;

template <class T>
class Heap {
private:
    T *data;
    int amount;
    int count;
    int parent(int) const;
    int left(int) const;
    int right(int) const;
    void heapify(int);
    void swap(int, int);

public:
    Heap(int);
    ~Heap();
    bool empty() const;
    bool full() const;
    void push(T);
    T pop();
    int size();
    int top();
    string toString() const;
};

template <class T>
Heap<T>::Heap(int sze){
    amount = sze;
    data = new T[amount];
    if (data == 0) {
        cout<<"Out Of Memory";
    }
    count = 0;
}

template <class T>
Heap<T>::~Heap() {
    delete [] data;
    data = 0;
    amount = 0;
    count = 0;
}


template <class T>
bool Heap<T>::empty() const {
    if (count == 0){
        return true;
    } else {
        return false;
    }
}
template <class T>
bool Heap<T>::full() const {
    if (count == amount){
        return true;
    } else {
        return false;
    }
}
template <class T>
int Heap<T>::parent(int pos) const {
    return (pos - 1) / 2;       // Manejado con índices. Desfasado con un -1 porque el root inicia en 0.
}

template <class T>
int Heap<T>::left(int pos) const {
    return ((2 * pos) + 1);     // Manejado con índices.
}

template <class T>
int Heap<T>::right(int pos) const {
    return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(int i, int j) {      // Cuando agregas un nodo.
    T aux = data[i];
    data[i] = data[j];
    data[j] = aux;
}
template <class T>
void Heap<T>::heapify(int pos) {        // Cuando eliminas un nodo.
    unsigned int le = left(pos);
    unsigned int ri = right(pos);
    unsigned int min = pos;
    if (le <= count && data[le] < data[min]) {      // Primero hacemos una comparación de left con la cuenta del arreglo para que no se salga de los límites. Después comparamos el izq con el min.
        min = le;
    }
    if (ri <= count && data[ri] < data[min]) {
        min = ri;
    }
    if (min != pos) {
        swap(pos, min);
        heapify(min);
    }
}

template <class T>
void Heap<T>::push(T val) {
    unsigned int pos;
    if (full()) {       // Condición que evalua si la memoria no se ha llenado.
        cout<<"Overflow";
    }

    pos = count;        // Cambia el valor de la variable count al nuevo valor de pos.
    count++;        // Se le agrega 1 al count.
    while (pos > 0 && val < data[parent(pos)]) {        // Condición: Mientras que el nuevo valor esté en posiciones positivas y que el nuevo valor sea menor al padre.
        data[pos] = data[parent(pos)];      // Se sobreescribe la posición.
        pos = parent(pos);
    }
    data[pos] = val;    // Se asigna el valor a la posición del arreglo.
}

template <class T>
T Heap<T>::pop() {
    if (empty()) {      // Condición para evaluar que el árbol no esté vacío.
        cout<<"No Such Element";
    }
    T aux = data[0];        // Se saca la raíz de la posición 0.

    data[0] = data[--count];    // El útlimo nodo se pasa a la raíz.
    heapify(0);     // Se reordena to.do el árbol con el heapify.
    return aux;     // Se regresa el nuevo árbol.
}
template <class T>
int Heap<T>::top() {
    return data[0];
}

template <class T>
int Heap<T>::size() {
    return count;
}

template <class T>
std::string Heap<T>::toString() const {
    std::stringstream aux;
    aux << "[";	for (unsigned int i = 0; i < count; i++) {
        if (i != 0) {
            aux << " ";
        } aux << data[i];
    } aux << "]";
    return aux.str();
}

#endif //ACT3_2_ARBOL_HEAP_IMPLEMENTANDO_UNA_FILA_PRIORIZADA_HEAP_H