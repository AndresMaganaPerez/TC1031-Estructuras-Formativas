//
// Created by droid on 10/13/2021.
//
// Andrés Magaña Pérez - A01067963
//

#ifndef ACT3_1_OPERACIONES_AVANZADAS_EN_UN_BST_BST_H
#define ACT3_1_OPERACIONES_AVANZADAS_EN_UN_BST_BST_H

#include <iostream>
#include <sstream>
#include <cstring>
#include <string>

using namespace std;

template <class T> class BST;

template <class T>
class TreeNode {
private:
    T value;
    TreeNode *left, *right;
    //TreeNode<T>* succesor();

public:
    TreeNode(T val) : value(val), left(0), right(0) {}
    TreeNode(T val, TreeNode<T>* le, TreeNode<T>* ri) : value(val), left(le), right(ri){}
    void insert(const T &val){
        if (val > value){       // Comparamos el valor agregado con el valor actual. El valor agregado tiene que ser mayor al actual para continuar.
            if (right != 0){    // Comprobamos que right tenga algún valor, para continuar con la recursión de la función.
                right->insert(val);
            } else {
                right = new TreeNode<T>(val);   // Si es nulo el valor de right, se crea un nuevo nodo.
            }
        } else {                    // Para el lado left, aplicamos lo mismo.
            if (left != 0){
                left->insert(val);
            } else {
                left = new TreeNode<T>(val);
            }
        }
    }
    bool find(T val){
        if (val == value){
            return true;
        } else if (val > value) {
            return (left != 0 && left->find(val));
        } else if (val < value) {
            return (right != 0 && right->find(val));
        }
    }
    int height() {
        int i = 1;
        int j  = 1;
        if (left != 0){
            i = left->height() + 1;
        }
        if (right!=0){
            j = right->height() + 1;
        }
        if (i > j){
            return i;
        }
        else {
            return j;
        }
    }

    void preorder(stringstream &aux) const{     // Root, Left, Right
        aux << value;
        if (left != 0){
            aux << " ";
            left->preorder(aux);
        }
        if (right!=0){
            aux<< " ";
            right->preorder(aux);
        }

    }
    void inorder(stringstream &aux) const{      // Left, Root, Right
        if (left != 0){
            left -> inorder(aux);
        }
        if (aux.tellp() != 1){      // Valida que si está en la posición 1 del arreglo, no imprima el espacio. .tellp - tell position.
            aux << " ";
        }
        aux << value;
        if (right != 0){
            right -> inorder(aux);
        }
    }

    void postorder(stringstream &aux) const{      // Left, Right, Root
        if (left != 0){
            left->postorder(aux);
        }
        if (right!=0){
            right->postorder(aux);
        }
        if (aux.tellp() != 1){      // Valida que si está en la posición 1 del arreglo, no imprima el espacio. .tellp - tell position.
            aux << " ";
        }
        aux << value;
    }

    void levelbylevel(stringstream &aux) const{
        aux << value;
        if (left != 0){
            aux << " ";
            left->levelbylevel(aux);
        }
        if (right!=0){
            aux << " ";
            right->levelbylevel(aux);
        }
    }
    bool ancestor(const T val, stringstream &aux){
        if (val < value) {
            if (aux.tellp() != 1){      // Valida que si está en la posición 1 del arreglo, no imprima el espacio. .tellp - tell position.
                aux << " ";
            }
            aux << value;
            return (left != 0 && left ->ancestor(val, aux));
        } else if (val > value) {
            if (aux.tellp() != 1){      // Valida que si está en la posición 1 del arreglo, no imprima el espacio. .tellp - tell position.
                aux << " ";
            }
            aux << value;
            return (right != 0 && right ->ancestor(val, aux));
        }
        else if (val == value) {
            if (aux.tellp() !=
                1) {      // Valida que si está en la posición 1 del arreglo, no imprima el espacio. .tellp - tell position.
                aux << " ";
            }
            aux << value;
            return true;
        } else {
            return false;
        }
    }
    int whatlevelamI(T val){
        int i = 1;
        if (val == value){
            return i;
        } else if (val > value) {
            i = right->whatlevelamI(val) + 1;
        } else if (val < value) {
            i = left->whatlevelamI(val) + 1;
        }
        return i;
    };
    friend class BST<T>;
};

template <class T>
class BST {
private:
    TreeNode<T> *root;

public:
    BST() : root(0) {}
   // ~BST() : removeAll() {}

    void add(const T &val){
        if (root == 0){
            root = new TreeNode<T>(val);
            } else {
                if (!root->find(val)) {
                root->insert(val);
            }
        }
    }
    string visit(){
        stringstream aux;

        aux << "[";
        root->preorder(aux);
        aux << "]";
        aux<<"\n";
        aux << "[";
        root->inorder(aux);
        aux << "]";
        aux <<"\n";
        aux << "[";
        root->postorder(aux);
        aux << "]";
        aux << "\n";
        aux << "[";
        root->levelbylevel(aux);
        aux << "]";

        return aux.str();
    }
    int height(){
        return root -> height();
    }
    string ancestors(const T &val){
        stringstream aux;
        aux<<"[";
        if (!root->ancestor(val, aux)){     // TODO: Regresa cadena en vez de booleano.
            return "[]";
        }
        aux<<"]";

        return aux.str();
    }
    int whatlevelamI(const T &val){
        return root->whatlevelamI(val);
    }
};

#endif //ACT3_1_OPERACIONES_AVANZADAS_EN_UN_BST_BST_H
