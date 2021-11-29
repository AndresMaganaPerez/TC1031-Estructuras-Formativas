//
// Created by droid on 11/29/2021.
//

#ifndef ACT5_1_IMPLEMENTACION_INDIVIDUAL_DE_OPERACIONES_SOBRE_CONJUNTOS_QUADRATIC_H
#define ACT5_1_IMPLEMENTACION_INDIVIDUAL_DE_OPERACIONES_SOBRE_CONJUNTOS_QUADRATIC_H

#include <string>
#include <sstream>

using namespace std;

template <class Key, class Value>
class Quadratic {
private:
    unsigned int (*func) (const Key);       // Func(Key): Función que recibe una llave. Devuelve un número al que le aplicamos un %, el cual nos da el índice.
    unsigned int size;  // El tamaño de las tablas
    unsigned int count;     // La cantidad de elementos guardados en la tabla.

    Key *keys;      // Arreglo donde se guardan las llaves de tipo Keys.
    Key initialValue;   // Valor por default que tiene cada casilla en el arreglo Keys cuando esté vacío.
    Value *values;      // Arreglo de tipo value del valor que va a corresponder a cada llave.

    long indexOf(const Key) const;

public:
    Quadratic(unsigned int, Key, unsigned int (*f) (const Key));    // Constructor: Recibe tamaño, tipo de dato de las llaves, y la función de Hash.
    // ~Quadratic();
    bool put(Key, Value);       // Inserción: Recibe la llave y el valor que quieres insertar.
    Value get(const Key);     // Search: Busca la llave y si lo encuentra regresa un valor Value.
    string toString() const;
};

// Constructor
template <class Key, class Value>
Quadratic<Key, Value>::Quadratic(unsigned int sze, Key init, unsigned int (*f)(const Key)) {
    size = sze;
    initialValue = init;
    count = 0;

    keys = new Key(size);   // Al apuntador keys le asignamos un arreglo de keys con el tamaño size, que se va a crear en el Heap.
    if (keys == 0){     // Validación: Se checa que no salga del tamaño de la memoria Heap.
        cout<<"Out of Memory";
    }
    for(int i = 0; i < size; i++){      // Recorremos el arreglo de keys asignándole el valor de default.
        keys[i]=init;
    }

    values = new Value(size);       // Al apuntador de values se le asigna un nuevo arreglo de value con tamaño size.
    if (values == 0){       // Validación: Se checa que no salga del tamaño de la memoria Heap.
        cout<<"Out of Memory";
    }
    for(int i = 0; i < size; i++){      // Se recorre el arreglo agregando los valores de default.
        values[i]=0;
    }

    func = f;   // Se asigna la función Hash a la variable local.
    count = 0;   // Se inicializa el contador de elementos de las tablas en 0.
}

// Search Index.
template <class Key, class Value>
long Quadratic<Key, Value>::indexOf(const Key k) const{
    unsigned int i, start;

    start = i = func(k) % size;     // A la función de Hash se le aplica el módulo con size. Se inicializa la variable start (que es donde empieza a buscar la casilla), e i.
    do {
        if (keys[i] == k){      // Si el índice donde estamos es el que se busca, entonces se regresa el índice.
            return i;
        }
        i = (i + 1) % size;     // Si no lo es, se va incrementando el índice y obteniendo su módulo.
    }   while (start != i);
    return -1;
}

// Insert
template <class Key, class Value>
bool Quadratic<Key, Value>::put(Key k, Value v){
    unsigned int start = func(k) % size, i = func(k) % size;
    long pos = indexOf(k);

    if (count >= size){
        cout<<"Overflow";
    }

    if (pos != -1){
        values[pos] = v;
        return true;
    }

    do {
        if (keys[i] == initialValue){
            keys[i] = k;
            values[i] = v;
            count ++;
            return true;
        }
        i = (i+1) % size;
    } while (start != i);
    return false;
}

// Obtener valor
template <class Key, class Value>
Value Quadratic<Key, Value>::get(const Key k){
    long pos = indexOf(k);

    return (pos != 1) ? values[pos] : -1;
}

// impresion clase quadratic
template <class Key, class Value>
string Quadratic<Key, Value>::toString() const {
	std::stringstream aux;
	for (int i = 0; i < size; i++){
			if (keys[i] != initialValue){
				aux << "(" << i << " ";
			  aux << keys[i] << " : " << values[i] << ") ";
			}
	}
	return aux.str();
}

#endif //ACT5_1_IMPLEMENTACION_INDIVIDUAL_DE_OPERACIONES_SOBRE_CONJUNTOS_QUADRATIC_H
