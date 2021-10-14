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

template <class T> class Bst;

template <class T>
class TreeNode {
private:
    T value;
    TreeNode *left, *right;
    TreeNode<T>* succesor();

public:
    TreeNode(T val) : value(val), left(0), right(0) {}
    TreeNode(T val, TreeNode<T>* le, TreeNode<T>* ri) : value(val), left(le), right(ri){}
    void add(T val){
        if (val > value){       // Comparamos el valor agregado con el valor actual. El valor agregado tiene que ser mayor al actual para continuar.
            if (right != 0){    // Comprobamos que right tenga algún valor, para continuar con la recursión de la función.
                right->add(val);
            } else {
                right = new TreeNode<T>(val);   // Si es nulo el valor de right, se crea un nuevo nodo.
            }
        } else {                    // Para el lado left, aplicamos lo mismo.
            if (left != 0){
                left->add(val);
            } else {
                left = new TreeNode<T>(val);
            }
        }
    }
    void visit(){

    }
    bool find(T val){
        if (val == value){
            return True;
        } else if (val > value) {
            return (left != 0 && left->find(val));
        } else if (val < value) {
            return (right != 0 && right->find(val));
        }
    }
    int height() {
        i = 0;
        if (value != 0){
            i = 1
        }
        while (left != 0 or right != 0){
            i++;
        }
        return i;
    }
    void remove(T);
    void removeChilds(T);
    void inorder(std::stringstream&) const;
    void preorder(std::stringstream&) const;

    friend class Bst<T>;
};

template <class T>
class BST {
private:
    TreeNode<T> *root;

public:
    BST() : root(0) {}
   // ~BST() : removeAll() {}

    void add(T val){
        if (root != 0){
            if (!root -> find(val)){
                root ->add(val);
            }
        } else {
            root = new TreeNode<T> val;
        }
    }
    visit();
    void height(){
        root -> height();
    }
    ancestors();
    whatlevelamI();

};

#endif //ACT3_1_OPERACIONES_AVANZADAS_EN_UN_BST_BST_H
