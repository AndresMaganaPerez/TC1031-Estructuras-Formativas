# Act. 3.3 Árbol Desplegado Implementando un Splay Tree
## Análisis de Complejidad:
### Función Add
La función add no hace un recorrido total del árbol, solamente va analizando los nodos izquierdos y derechos y en base a eso
inserta el nuevo nodo. Por lo que tiene una complejidad de **O(log n)**.

### Función remove
En remove también hace recorridos analizando los nodos izquierdos y derechos. Por lo que tiene una complejidad de **O(log n)**.

### Función find
Al igual que las funciones anteriores, find realiza recorridos en base a los nodos izquierdos y derechos. No va recorriendo 
todo el árbol a ciegas. Entonces tiene una complejidad de **O(log n)**.

### Función Size
La función size solamente regresa la variable de size, entonces es **O(1)**

---
# Correcciones
Al igual que el árbol Heap, quise esperar a comprender los árboles BST y los Heaps para realizar esta formativa.
Se implementaron las 4 funciones. 
