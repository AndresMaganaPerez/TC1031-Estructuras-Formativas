//
// Created by droid on 9/8/2021.
//

#ifndef ACT1_2_ALGORITMOS_DE_BUSQUEDA_Y_ORDENAMIENTO_SORTS_H
#define ACT1_2_ALGORITMOS_DE_BUSQUEDA_Y_ORDENAMIENTO_SORTS_H

#endif //ACT1_2_ALGORITMOS_DE_BUSQUEDA_Y_ORDENAMIENTO_SORTS_H

#include <list>

template <class T>
class Sorts{
private:
    void swap(vector<T> &v, int, int);
    void copyArray(vector<T> &A, vector<T> &B, int, int);
    void mergeArray(vector<T> &A, vector<T> &B, int, int, int);
    void mergeSplit(vector<T> &A, vector<T> &B, int, int);


public:
    void ordenaSeleccion(vector<T> &v);
    void ordenaBurbuja(vector<T> &v);
    void ordenaMerge(vector<T> &v);

    int busqSecuencial(vector<T>, int, int);
    int busqBinaria(vector<T>, int);
};

//Swap
template <class T>
void Sorts<T>::swap(vector<T> &v, int i, int j){
    T aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

//Copy Array
template <class T>
void Sorts<T>::copyArray(int &A, int &B, int low, int high) {
    for (int i = low; i <= high; i++)
        A[i]=B[i];
}

//Merge Array
template <class T>
void Sorts<T>::mergeArray(int &A, int &B, int low, int mid, int high) {
    int i, j, k;

    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid &&j <= high){
        if (A[i] < A[j]){
            B[k] = A[i];
            i++;
        } else{
            B[k] = A[i];
            j++;
        }
        k++;
    }
    if (i > mid) {
        for (; j <= high; j++){
            B[k++] = A[j];
        }
    } else {
        for (; i <= mid; i++){
            B[k++] = A[i];
        }
    }
}

//Merge Split
template <class T>
void Sorts<T>::mergeSplit(vector<T> &A, vector<T> &B, int high, int low){
    int mid;
    if ((high-low)<1){
        return;
    }
    mid = (high + low)/2;
    mergeSplit(A, B, mid + 1, high);
    mergeSplit(A, B, low, mid);
    mergeArray(A, B, low, mid, high);
    copyArray(A, B, low, high);
}

//SeLection Sort
template <class T>
void Sorts<T>::ordenaSeleccion(vector<T> &v, ) {
    std::vector<T> v(source);
    int pos;

    for (int i = v.size() - 1; i > 0; i--){
        pos = 0;
        for (int j = 1; j <= i; j++){
            if (v[j]>v[lug]){
                lug = j;
            }
        }
        if (pos != i){
            swap(v, i, pos);
        }
    }
}

// Bubble Sort
template <class T>
void Sorts<T>::ordenaBurbuja(const std::vector<T> &source){
    std::vector<T> v(source);

    for (int i = v.size() - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (v[j] > v[j + 1]){
                swap(v,j,j+1);
            }
        }
    }
    return v;
}

// Merge Sort
template <class T>
void Sorts<T>::ordenaMerge(vector<T> &v){
    vector<T>auz(v.size());
    mergeSplit(v, aux, v.size()-1, 0);
}
