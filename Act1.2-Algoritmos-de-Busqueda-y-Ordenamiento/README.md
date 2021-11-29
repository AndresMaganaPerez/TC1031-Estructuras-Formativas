# Actividad 1.2 - Algoritmos de Búsqueda y Ordenamiento
## Complejidades:
### Selection Sort
El algoritmo de Selection Sort cuenta con dos ciclos for anidados, que dependen de las variables que tengan 
en sus condiciones. Cada for tiene una complejidad de **O(n)**. Entonces el algoritmo en total tiene una complejidad de 
**O(n^2)**.

### Bubble Sort
El algoritmo de Bubble Sort al igual que el Selection Sort, cuenta con dos ciclos for. Por la misma explicación que se 
hizo en Selection Sort, Bubble Sort tiene una complejidad de **O(n^2)**.

### Merge Sort
Merge Sort es un algoritmo más complejo que los demás, ya que cuenta con funciones auxiliares. 

#### Ordena Merge 
El algoritmo tiene una complejidad **O(1)**, ya que solamente es un código lineal.

#### Copy Array
Copy Array incluye un ciclo for, el cual sus iteraciones dependen de las variables que tiene en su condición. Como solamente
es un for, tiene una complejdiad de **O(n)**.

#### Merge Array
Merge Array cuenta con un ciclo while, y dos ciclos for, ninguno de estos anidados. Por lo que tiene una complejidad de **O(n)**.

#### Merge Split
Merge split solamente cuenta con un condicional, el resto son llamadas a otras funciones. Tiene una complejidad de **O(1)**.

### Búsqueda Binaria
Búsqueda Binaria cuenta con un ciclo while, la cual sus ciclos depende del caso base que tenga. El algoritmo tiene una complejidad
de **O(n)**.

### Búsqueda Secuencial
Búsqueda Secuencial cuenta con un ciclo for, por lo que su complejidad es de **O(n)**.

### Swap
Swap es un algoritmo lineal, por lo que tiene una complejidad de **O(1)**.

---
# Correcciones

* Se corrigió la sintáxis del código. Primero su definición dentro de la clase, afuera su implementación.
* Se implementaron las búsquedas.
* En selection sort se utilizó un recorrido de 0 a n, en vez de n a 0.
* Se agregó análisis de complejidad. 