# Actividad 2.1 - Implementación de ADT de Estructura de Datos Lineales
## Complejidades:
### Insertion
La función insertion contiene dos condicionales, los cuales por ser secuenciales tienen una complejidad de **O(1)**.
Pero además tiene un ciclo while, el cual los ciclos que realice depende del caso base que tenga. Por lo que, el algoritmo
tiene una complejidad de **O(n)**.
### Insertion First
Cuenta únicamente con un condicional, por lo que su complejidad es de **O(1)**.
### Search
Search contiene un ciclo while, el cual el número de ciclos que realice depende de su caso base, por lo que su complejidad
es de **O(n)**.
### deleteAt
La función tiene un condicional y un ciclo while. El ciclo while por ser el de mayor complejidad el algoritmo tiene una 
complejidad de **O(n)**.
### deleteFirst
Esta función solamente cuenta con un condicional, por lo que el algoritmo es secuencial. Gracias a esto este algoritmo 
tiene una complejidad de **O(1)**.
### Clear
Clear tiene un ciclo while, el cual sus ciclos dependen de su caso base, por lo que el algoritmo tiene una complejidad de 
**O(n)**. 

El resto de las funciones son O(1), porque son lineales, siempre son el mismo número de pasos. 
---
# Correcciones
* Se escribió de manera más específica el análisis de complejidad. 