//
// Created by droid on 11/24/2021.
// Andrés Magaña Pérez - A01067963
//

#ifndef ACT3_3_ARBOL_DESPLEGADO_IMPLEMENTANDO_UN_SPLAY_TREE_SPLAY_H
#define ACT3_3_ARBOL_DESPLEGADO_IMPLEMENTANDO_UN_SPLAY_TREE_SPLAY_H


#include <string>
#include <sstream>
#include <iostream>

template <class T> class SplayTree;

template <class T>
class Node {
private:
    T value;
    Node *left, *right, *parent;    // Agregar un apuntador para el padre facilita las cosas para el abuelo.

    Node<T>* succesor();
    Node<T>* rot_right(Node<T>*);
    Node<T>* rot_left(Node<T>*);

public:
    Node(T);
    Node(T, Node<T>*, Node<T>* ,Node<T>*);
    Node<T>* add(T);
    Node<T>* find(T);
    Node<T>* remove(T);
    void removeChilds();
    void inorder(std::stringstream&) const;
    void print_tree(std::stringstream&) const;
    void preorder(std::stringstream&) const;
    Node<T>* splay(Node<T>*, Node<T>*);

    friend class SplayTree<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), left(0), right(0), parent(0) {}

template <class T>
Node<T>::Node(T val, Node<T> *le, Node<T> *ri, Node<T> *p)
        : value(val), left(le), right(ri), parent(p) {}

template <class T>
Node<T>* Node<T>::add(T val) {
        if (val < value){       // Comparamos el valor agregado con el valor actual. El valor agregado tiene que ser menor al actual para continuar.
            if (left != 0){    // Comprobamos que left tenga algún valor.
                return left->add(val);  // Si tiene un valor en left, llamamos a la función sobre left.
            } else {    // Si no tiene un valor en left.
                left = new Node<T>(val);   // Se crea un nuevo nodo en left.
                left->parent = this;   // This es un apuntador implícito por el compilador, que hace referencia al nodo actual. Entonces se asigna el parent al nodo de donde se llamó left.
                return left;    // Regresamos el nuevo nodo.
            }
        } else {                    // Para el lado right, aplicamos lo mismo.
            if (right != 0){    // Comprobamos que no esté vacío right.
                return right->add(val);     // Se hace la llamada recursiva sobre right.
            } else {    // Si está vacío...
                right = new Node<T>(val);   // Se crea un nuevo nodo en right.
                right->parent = this;   // Se declara el padre.
                return right;   // Se regresa el nuevo nodo.
            }
        }
    }

template <class T>
Node<T>* Node<T>::find(T val) {
    if (val == value){      // Si el valor buscado es donde estamos actualmente...
        return this;    // Regresamos el valor actual.
    } else if (val < value) {   // Si el valor buscado es menor al valor actual, nos vamos por el lado izq.
        if (left != 0){     // Si el valor del nodo izq no es null...
            return left -> find(val);   // Hacemos llamada recursiva sobre el nodo izq.
        } else {    // Si está vacío.
            return this;    // regresamos el valor actual.
        }
    } else  {   // Si el valor buscado es mayor al valor actual, nos vamos por la derecha.
        if (right != 0) {   // Si el nodo derecho no está vacío...
            return right -> find(val);      // Hacemos llamada recursiva sobre el nodo derecho.
        } else {    // Sí está vacío...
            return this;    // Regresamos el valor actual.
        }
    }
}

template <class T>
Node<T>* Node<T>::succesor() {
    Node<T> *le, *ri;

    le = left;
    ri = right;

    if (right->left == 0) {
        right = right->right;
        ri->right = 0;
        return ri;
    }

    Node<T> *parent, *child;
    parent = right;
    child = right->left;
    while (child->left != 0) {
        parent = child;
        child = child->left;
    }
    parent->left = child->right;
    child->right = 0;
    return child;
}

template <class T>
Node<T>* Node<T>::remove(T val) {
    Node<T> *succ, *old;
    if (val < value){
        if(left != 0){
            if(left->value == val){
                old = left;
                if (old->left != 0 && old->right != 0){
                    succ = left->succesor();
                    if (succ != 0){
                        succ->left = old->left;
                        succ->right = old->right;
                        succ->parent = old->parent;
                        if(succ->left){
                            succ->left->parent = succ;
                        }
                        if(succ->right){
                            succ->right->parent = succ;
                        }
                    }
                    left = succ;
                } else if (old->right != 0){
                    old->right->parent = left->parent;
                    left = old->left;
                } else if (old->left != 0) {
                    old->left->parent = left->parent;
                    left = old->left;
                } else {
                    left = 0;
                }
                delete old;
                return this;
            } else {
                return left->remove(val);
            }
        }
    } else if (val > value) {
        if (right != 0) {
            if (right->value == val) {
                old = right;
                if (old->left != 0 && old->right != 0){
                    succ = right->succesor();
                }
            }
        }
    } return this; // To avoid warning
}

template <class T>
void Node<T>::removeChilds() {
    if (left != 0) {
        left->removeChilds();
        delete left;
        left = 0;
    }
    if (right != 0) {
        right->removeChilds();
        delete right;
        right = 0;
    }
}

template <class T>
Node<T>* Node<T>::rot_right(Node<T>* x){    // Funciones obtenidas de los AVL, pero incluyendo el apuntador de los padres.
    Node<T> *y = x->left;
    x->left = y->right;
    if(y->right)
        y->right->parent = x;
    y->right = x;
    // enlace de y con el padre de x
    y->parent = x->parent;
    x->parent = y;
    // hace enlace del padre de x a y
    if(y->parent){
        if(y->parent->left && y->parent->left->value == x->value)
            y->parent->left = y;
        else
            y->parent->right = y;
    }
    return y;
}

template <class T>
Node<T>* Node<T>::rot_left(Node<T>* x){
    Node<T> *y = x->right;
    x->right = y->left;
    if(y->left)
        y->left->parent = x;
    y->left = x;
    // enlace de y con el padre de x
    y->parent = x->parent;
    x->parent = y;
    // hace enlace del padre de x a y
    if(y->parent){
        if(y->parent->left && y->parent->left->value == x->value)
            y->parent->left = y;
        else
            y->parent->right = y;
    }
    return y;
}

template <class T>
Node<T>* Node<T>::splay(Node<T>* root, Node<T>* x){
    while(x->parent != 0){  // Condición: Mientras no llegue a la raíz.

        if(x->parent->value == root->value){    // Si el papá es la raíz...
            if(x->parent->left && x->parent->left->value == x->value){  // Si el papá tiene un hijo por el lado izq y ese hijo es donde estoy.
                rot_right(x->parent);   // Se aplica rotación der.
            }else{
                rot_left(x->parent);    // Si no se aplica rotación izq.
            }
        }else{  // Si el papá no es la raíz.
            Node<T>*p = x->parent; // parent
            Node<T>*g = p->parent; // granparent
            if(p->left && g->left &&
               x->value == p->left->value && p->value == g->left->value){   // Caso
                rot_right(g);
                rot_right(p);
            }else if(p->right && g->right &&
                     x->value == p->right->value && p->value == g->right->value){   // Caso
                rot_left(g);
                rot_left(p);
            }else	if(p->left && g->right &&
                        x->value == p->left->value && p->value == g->right->value){     // Caso
                rot_right(p);
                rot_left(g);
            }else{
                rot_left(p);
                rot_right(g);
            }
        }
    }
    return x;
}

template <class T>
void Node<T>::inorder(std::stringstream &aux) const {
    if (left != 0) {
        left->inorder(aux);
    }
    if (aux.tellp() != 1) {
        aux << " ";
    }
    aux << value;
    if (right != 0) {
        right->inorder(aux);
    }
}

template <class T>
void Node<T>::print_tree(std::stringstream &aux) const {
    if (parent != 0){
        aux << "\n node " << value;
        aux << " parent " << parent->value;
    }else
        aux << "\n root " << value;
    if (left != 0)
        aux << " left " << left->value;
    if (right != 0)
        aux << " right " << right->value;
    aux << "\n";

    if (left != 0) {
        left->print_tree(aux);
    }
    if (right != 0) {
        right->print_tree(aux);
    }
}

template <class T>
void Node<T>::preorder(std::stringstream &aux) const {
    aux << value;
    if (left != 0) {
        aux << " ";
        left->preorder(aux);
    }
    if (right != 0) {
        aux << " ";
        right->preorder(aux);
    }
}

template <class T>
class SplayTree {
private:
    Node<T> *root;
    int sze;

public:
    SplayTree();
    ~SplayTree();
    bool empty() const;
    void add(T);
    bool find(T);
    int size();
    void remove(T);
    void removeAll();
    std::string inorder() const;
    std::string print_tree() const;
    std::string preorder() const;
};

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template <class T>
SplayTree<T>::~SplayTree() {
    removeAll();
}

template <class T>
bool SplayTree<T>::empty() const {
    return (root == 0);
}

template<class T>
void SplayTree<T>::add(T val) {

    if (root != 0) {    // El nuevo valor agregado no sea la raíz.
        Node<T>* added = root->add(val);    // Se utiliza la función de inserción de un BST.
        root = root->splay(root,added);     // Se aplica la función Splay.
    } else {
        root = new Node<T>(val);    // Si es la raíz solamente se agrega un nodo nuevo.
    }
    sze ++;
}

template <class T>
void SplayTree<T>::remove(T val) {
    if (root != 0) {
        if (val == root->value) {
            Node<T> *succ = root->succesor();
            if (succ != 0) {
                succ->left = root->left;
                succ->right = root->right;
                succ->parent = 0;
                if(succ->left)
                    succ->left->parent = succ;
                if(succ->right)
                    succ->right->parent = succ;
            }
            delete root;
            root = succ;
        } else {
            Node<T>* p = root->remove(val);
            root = root->splay(root,p);
        }
    }
}

template <class T>
void SplayTree<T>::removeAll() {
    if (root != 0) {
        root->removeChilds();
    }
    delete root;
    root = 0;
}

template <class T>
bool SplayTree<T>::find(T val){
    if (root != 0) {
        Node<T>* found = root->find(val);
        root = root->splay(root,found);
        return (root->value == val);
    } else {
        return false;
    }
}

template <class T>
std::string SplayTree<T>::inorder() const {
    std::stringstream aux;

    aux << "[";
    if (!empty()) {
        root->inorder(aux);
    }
    aux << "]";
    return aux.str();
}

template <class T>
std::string SplayTree<T>::print_tree() const {
    std::stringstream aux;

    aux << "\n ================================ ";
    if (!empty()) {
        root->print_tree(aux);
    }
    aux << " ================================ \n";
    return aux.str();
}



template <class T>
std::string SplayTree<T>::preorder() const {
    std::stringstream aux;

    aux << "[";
    if (!empty()) {
        root->preorder(aux);
    }
    aux << "]";
    return aux.str();
}

template <class T>
int SplayTree<T>::size(){
    return sze;
}
#endif //ACT3_3_ARBOL_DESPLEGADO_IMPLEMENTANDO_UN_SPLAY_TREE_SPLAY_H
