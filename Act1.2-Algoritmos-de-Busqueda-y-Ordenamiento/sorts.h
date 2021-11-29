//
// Created by droid on 9/8/2021.
//

#ifndef ACT1_2_ALGORITMOS_DE_BUSQUEDA_Y_ORDENAMIENTO_SORTS_H
#define ACT1_2_ALGORITMOS_DE_BUSQUEDA_Y_ORDENAMIENTO_SORTS_H

#include <list>
#include <vector>
using namespace std;

template <class T>

class Sorts{
private:
    void swap(vector<T> &, int, int);
    void copyArray(vector<T> &, vector<T> &, int, int);
    void mergeArray(vector<T> &, vector<T> &, int, int, int);
    void mergeSplit(vector<T> &, vector<T> &, int, int);

public:
    vector<T> ordenaSeleccion(const vector<T> &);
    vector<T> ordenaBurbuja(const vector<T> &);
    vector<T> ordenaMerge(vector<T> &);
    int busqSecuencial(vector<T> &, int);
    int busqBinaria(vector<T> &, int);
};

// Privates
template <class T>
void Sorts<T>::swap(vector<T> &v, int a, int b) {
    int aux;    // Auxiliar para guardar el valor de la primera variable
    aux = v[a];
    v[a] = v[b];
    v[b] = aux;
}

template <class T>
void Sorts<T>::copyArray(vector<T> &A, vector<T> &B, int low, int high) {
    for (int i = low; i <= high; i++)
        A[i] = B[i];
}

template <class T>
void Sorts<T>::mergeArray(vector<T> &A, vector<T> &B, int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;    // Valor auxiliar. Rellena poco a poco el vector temporal.

    while (i <= mid && j <=
                       high) {   // Ciclo donde low avanza hasta mid, y mid + avanza hasta high. Mientras no se pasen los limites predichos, se seguirá con la comparación.
        if (A[i] <
            A[j]) {   // Se comparan los valores más chicos de ambos bloques, y se escriben en el vector temporal.
            B[k] = A[i];    // Si i es el menor lo ingresa en el vector temporal.
            i++;
        } else {
            B[k] = A[j];    // Si j es menor lo ingresa al vector temporal.
            j++;
        }
        k++;    // Aumenta la posición del valor auxiliar de k.
    }
    if (i > mid) {     // Se ingresan los valores restantes de j en el vector temporal, hasta topar con el high.
        for (; j <= high; j++) {
            B[k] = A[j];
            k++;
        }
    } else {
        for (; i <= mid; i++) {
            B[k++] = A[i];
        }
    }
}

template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int low, int high){
    int mid;

    if ((high-low) < 1){  // Se comprueba si High - Low es diferente de 0, ayuda a identificar cuando ya no se puede partir más. CASO BASE.
        return;
    }
    mid = (high + low)/2; // Obtenemos el valor mitad.
    mergeSplit(A, B, low, mid); // Se trabaja con la mitad, del valor mínimo a la mitad. Se trabaja primero esta parte.
    mergeSplit(A, B, mid + 1, high); // Trabaja con las mitades que fue dejando en las particiones.
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

// Publics
template <class T>
vector<T> Sorts<T>::ordenaSeleccion(const vector<T> &source){
    vector<T> v(source);    // Se genera una copia del arreglo con el que se va a trabajar.
    int pos, i, j;
    // for (i = v.size()-1; i > 0; i--){
    for (i = 0; i < v.size(); i++){     // Iteración del primer elemento al mayor.
        pos = i;        // Se inicializa la variable mínima con el valor del indice i.
        for (j = i + 1; j < v.size(); j++){     // Iteración va de un valor más arriba que el índice i, hasta el tamaño completo del arreglo.
            if (v[j] < v[pos]){     // Condición si el índice j (adelante) es menor al índice pos (posición actual)
                pos = j;    // Se cambia la variable mínima a que señale a j.
            }
        }
        if (pos != i) {
            swap(v, i, pos);
        }
    }
    return v;
}

template <class T>
vector<T> Sorts<T>::ordenaBurbuja(const vector<T> &source){
    vector<T> v(source);
    int i, j;
    for (i = 0; i < v.size()-1; i++) {
        for (j = 0; j < v.size()-1-i; j++)
        if (v[j] > v[j + 1])
            swap(v, j, j+1);
    }
    return v;
}

template <class T>
vector<T> Sorts<T>::ordenaMerge(vector<T> &source) {
    vector<T> v(source);
    vector<T> temp(v.size());  // Vector Temporal
    mergeSplit(v, temp, 0,v.size()-1);

    return v;
}

template <class T>
int Sorts<T>::busqBinaria(vector<T> &v, int val) {
    int mid;
    int low = 0;
    int high = v.size() - 1;

    while (low < high) {
        mid = (high + low)/2;
        if (v[mid] == val){
            return mid;
        } else if (val > v[mid]){
            low = mid + 1;
        } else if (val < v[mid]){
            high = mid - 1;
        }
    }
    if (low == val){
        return low;
    } else {
        return -1;
    }
}

template <class T>
int Sorts<T>::busqSecuencial(vector<T> &v, int val) {
    int i;
    for (i = 0; i < v.size(); i++){
        if (val == v[i]){
            return i;
        }
    }
    return -1;
}

#endif //ACT1_2_ALGORITMOS_DE_BUSQUEDA_Y_ORDENAMIENTO_SORTS_H