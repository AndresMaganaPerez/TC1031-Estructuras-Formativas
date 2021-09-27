//
// Created by droid on 9/26/2021.
//
// Andrés Magaña Pérez - A01067963

#ifndef ACT2_1_IMPLEMENTACION_DE_ADT_DE_ESTRUCTURA_DE_DATOS_LINEALES_LIST_H
#define ACT2_1_IMPLEMENTACION_DE_ADT_DE_ESTRUCTURA_DE_DATOS_LINEALES_LIST_H

template <class T> class List;
template <class T> class ListIterator;

template <class T>
class Link{     // Representa a un nodo
private:
    Link(T val) : value(val), next(0) {} // Primer constructor, recibe objeto apunta a nulo.
    Link(T val, Link* nxt) : value(val), next(nxt) {}
    Link(const Link<T> &source) {}

    T value;
    Link<T> *next;

    friend class List<T>;
    friend class ListIterator<T>;
};

template <class T>
class List{     // Representa una lista
public:
    List() : head(0), size(0) {}     // Primer Constructor.
    ~List() {    // Deconstructor
    clear();
    }
    void insertionFirst(T val){
        Link<T> *newLink;

        newLink = new Link<T>(val);
        if (newLink == 0) {
            std::cout<<"Out of Memory";
        }
        newLink->next = head;
        head = newLink;
        size++;
    }

    void insertion(T val){
        Link<T> *newLink, *p;

        newLink = new Link<T>(val);
        if (newLink == 0) {
            std::cout<<"Out of Memory";
        }
        if (empty()) {
            insertionFirst(val);
            return;
        }

        p = head;
        while (p->next != 0) {
            p = p->next;
        }

        newLink->next = 0;
        p->next = newLink;
        size++;
    }
    int search(T val) const{
        Link<T> *p;     // Variable temporal para recorrer arreglo.
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
    T deleteFirst(){
        T val;
        Link<T> *p;

        if (empty()){
            std::cout<<"No such element.";
        }
        p = head;

        head = p->next;
        val = p->value;

        delete p;
        size--;
    }
    T   deleteAt(int index){
        Link<T> *p, *q;
        T val;
        int i = 0;
        p = head;

        if (index == 0){
            deleteFirst();
        }
        while (i != index){
            q = p;
            p = p->next;
            ++i;
        }
        val = p->value;
        q->next = p->next;

        delete p;
        return val;
        size--;
    }
    void update(int index, T val){
        Link<T> *p;
        int i = 0;
        p = head;

        while(i != index){
            p = p->next;
            i++;
        }
        p->value = val;
    }

    void clear(){
        Link<T> *p, *q;

        p = head;
        while (p != 0) {
            q = p->next;
            delete p;
            p = q;
        }
        head = 0;
        size = 0;
    }

    std::string toString() const{
        std::stringstream aux;
        Link<T> *p;

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

private:
    Link<T> *head;  // Variable instancia. Apuntador al primer elemento.
    int 	size;   // Variable instancia. Total de elementos en la estructura.
};

#endif //ACT2_1_IMPLEMENTACION_DE_ADT_DE_ESTRUCTURA_DE_DATOS_LINEALES_LIST_H