//
// Created by droid on 8/25/2021.
// Andrés Magaña Pérez - A01067963

#ifndef ACT1_1_FUNCIONES_ITERATIVAS_RECURSIVAS_Y_ANALISIS_DE_COMPLEJIDAD_FUNCIONES_ITERATIVAS_RECURSIVAS_H
#define ACT1_1_FUNCIONES_ITERATIVAS_RECURSIVAS_Y_ANALISIS_DE_COMPLEJIDAD_FUNCIONES_ITERATIVAS_RECURSIVAS_H

#endif //ACT1_1_FUNCIONES_ITERATIVAS_RECURSIVAS_Y_ANALISIS_DE_COMPLEJIDAD_FUNCIONES_ITERATIVAS_RECURSIVAS_H

class Funciones{
public:
    int sumaIterativa(int);
    int sumaRecursiva(int);
    int sumaDirecta(int);
};

int Funciones::sumaIterativa(int n) { //Análisis Asintótico: O(n), Lineal.
    int acum=0;
    int i=1;
    for (i;i<=n;i++){
        acum=acum+i;
    }
    return acum;
}

int Funciones::sumaRecursiva(int n) { //Análisis Asintótico: O(n), Lineal.

    if (n<=1){
        return 0;
    }
    else
        return n + sumaRecursiva(n-1);
}

int Funciones::sumaDirecta(int n) { //Análisis Asintótico: O(1), Constante.
    int k;
    k=(n*(n+1))/2;
    return k;
}