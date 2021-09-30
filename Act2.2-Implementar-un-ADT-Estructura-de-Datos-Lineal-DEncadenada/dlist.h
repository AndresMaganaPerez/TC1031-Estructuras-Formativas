//
// Created by droid on 9/29/2021.
//
// Andrés Magaña Pérez - A01067963
//
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

#ifndef ACT2_2_IMPLEMENTAR_UN_ADT_DE_UNA_ESTRUCTURA_DE_DATOS_LINEAL_DOBLEMENTE_ENCADENADA_DLIST_H
#define ACT2_2_IMPLEMENTAR_UN_ADT_DE_UNA_ESTRUCTURA_DE_DATOS_LINEAL_DOBLEMENTE_ENCADENADA_DLIST_H

using namespace std;
template <class T> class DList;

template <class T>
class DLink{     // Representa a un nodo
private:
    DLink(T val) : value(val), next(0) {} // Primer constructor, recibe objeto apunta a nulo.
    DLink(T val, DLink* nxt) : value(val), next(nxt) {}
    DLink(const DLink<T> &source) {}

    T value;
    DLink<T> *next;
    DLink<T> *previous;

    friend class DList<T>;
};

template <class T>
class DList {     // Representa una lista
public:
    DList() : head(0), size(0) {}     // Primer Constructor.
    ~DList() {    // Deconstructor
        clear();
    }
    /*void insertionFirst(T val){
        DLink<T> *newDLink;

        newDLink = new DLink<T>(val);
        if (newDLink == 0) {
            std::cout<<"Out of Memory";
        }
        if (empty()){
            head = newDLink;
            tail = newDLink;
        } else{
            newDLink->next = head;
            head->previous = newDLink;
            head = newDLink;
        }
        size++;
    }*/

    void insertion(T val){
        DLink<T> *newDLink;

        newDLink = new DLink<T>(val);
        if (newDLink == 0) {
            std::cout<<"Out of Memory";
        }
        if (empty()) {
            head = newDLink;
            tail = newDLink;
        } else {
            tail->next = newDLink;
            newDLink->previous = tail;
            tail = newDLink;
        }
        size ++;
    }
    int search(T val) const{
        DLink<T> *p;     // Variable temporal para recorrer arreglo.
        int i = 0;

        p = head;   // Se inicializa la variable al principio de la lista.
        while (p != 0){
            if (p->value == val){   // Value es un atributo de la clase Link.
                return i;
            }
            p = p->next;
            i++;
        }
        return -1;
    }
    bool empty() const{
        return (head == 0);
    }
    /*T deleteFirst(){
        T val;
        DLink<T> *p;

        if (empty()){
            std::cout<<"No such element.";
        }
        p = head;

        head = p->next;
        val = p->value;

        delete p;
        size--;
    }*/
    T   deleteAt(int index){
        DLink<T> *p, *q;
        int i = 0;
        p = head;

        if (index == 0){
            //deleteFirst();
        }
        while (i != index){
            q = p;
            p = p->next;
            ++i;
        }

        delete p;
        size--;
    }
    void update(int index, T val){
        DLink<T> *p;
        int i = 0;
        p = head;

        while(i != index){
            p = p->next;
            i++;
        }
        p->value = val;
    }

    void clear(){
        DLink<T> *p, *q;

        p = head;
        while (p != 0) {
            q = p->next;
            delete p;
            p = q;
        }
        head = 0;
        size = 0;
    }

    /*std::string toString() const{
        std::stringstream aux;
        DLink<T> *p;

        p = head;
        aux << "[";
        while (p != 0) {
            aux << p->value;
            if (p->next != 0) {
                aux << ", ";
            }
            p = p->next;
        }
        aux << "]";
        return aux.str();
    }*/

    std::string toStringForward() const {
        std::stringstream aux;
        DLink<T> *p;

        p = head;
        aux << "[";
        while (p != 0) {
            aux << p->value;
            if (p->next != 0) {
                aux << ", ";
            }
            p = p->next;
        }
        aux << "]";
        return aux.str();
    }

    std::string toStringBackward() const {
        std::stringstream aux;
        DLink<T> *p;

        p = tail;
        aux << "[";
        while (p != 0) {
            aux << p->value;
            if (p->previous != 0) {
                aux << ", ";
            }
            p = p->previous;
        }
        aux << "]";
        return aux.str();
    }

private:
    DLink<T> *head, *tail;  // Variable instancia. Apuntador al primer elemento. Apuntador a último elemento.
    int 	size;   // Variable instancia. Total de elementos en la estructura.
};

#endif //ACT2_2_IMPLEMENTAR_UN_ADT_DE_UNA_ESTRUCTURA_DE_DATOS_LINEAL_DOBLEMENTE_ENCADENADA_DLIST_H