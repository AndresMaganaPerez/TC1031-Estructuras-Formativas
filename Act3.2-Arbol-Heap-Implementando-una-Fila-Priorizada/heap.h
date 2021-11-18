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
    return (pos - 1) / 2;
}

template <class T>
int Heap<T>::left(int pos) const {
    return ((2 * pos) + 1);
}

template <class T>
int Heap<T>::right(int pos) const {
    return ((2 * pos) + 2);
}

template <class T>
void Heap<T>::swap(int i, int j) {
    T aux = data[i];
    data[i] = data[j];
    data[j] = aux;
}
template <class T>
void Heap<T>::heapify(int pos) {
    unsigned int le = left(pos);
    unsigned int ri = right(pos);
    unsigned int min = pos;
    if (le <= count && data[le] < data[min]) {
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
    if (full()) {
        cout<<"Overflow";
    }

    pos = count;
    count++;
    while (pos > 0 && val < data[parent(pos)]) {
        data[pos] = data[parent(pos)];
        pos = parent(pos);
    }
    data[pos] = val;
}

template <class T>
T Heap<T>::pop() {
    if (empty()) {
        cout<<"No Such Element";
    }
    T aux = data[0];

    data[0] = data[--count];
    heapify(0);
    return aux;
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