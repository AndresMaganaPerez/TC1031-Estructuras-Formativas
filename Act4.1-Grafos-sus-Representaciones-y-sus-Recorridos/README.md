# Análisis de Complejidad
---
## Función Graph
La función Graph solamente inicializa los edgeslist y edgesmat en 0. Siempre hace única linea de código y no depende de variables.
Tiene una complejidad de **O(1)**.

## Función loadGraphList
La función loadGraphList abre el archivo de texto que recibió, y por cada coordenada que tenga se va agregar un edgeAdjList.
Esta función depende de cuantos nodos se manejan en el grafo, por lo que tiene una complejidad de **O(n)**.

## Función loadGraphMat
La función loadGraphMat al igual que loadGraphList depende de los nodos que utiliza el grafo. Tiene una complejidad de **O(n)**.

## Función addEdgeAdjMatrix
addEdgeAdjMatrix solamente añade nuevas conexiones con nodos a la matriz, tiene tres lineas de código secuenciales. Tiene
una complejidad de **O(1)**.

## Función addEdgeAdjList
De la misma manera que addEdgeAdjMatrix agrega nuevos nodos a la lista, el algoritmo es secuencial y tiene una complejidad de
**O(1)**.

## Función printAdjMat_clean
Esta función depende de los nodos que tenga el grafo en general para poder imprimir una matriz con los nodos que tiene el grafo.
Tiene una complejidad de **O(n)** por su dependencia a los nodos.

## Función DFS
La función de recorrido DFS tiene una complejidad de **O(log n)**. Hace recorridos dependiendo de los nodos que ya ha visitado,
y los nodos de start y goal.

## Función BFS
La función de recorrido BFS tiene la misma complejidad que DFS de **O(log n)** por las mismas razones. 

---

# Correcciones
Mi IDE no leía los archivos de texto que estaban en el directorio, debido a que tienen que estar en la carpeta de 
*cmake-build-debug*. Hice dos copias de los archivos de g y star dentro de dicho directorio para que pudiera correr bien 
el programa. 