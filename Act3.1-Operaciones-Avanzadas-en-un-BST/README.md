# Análisis de Complejidad

El algoritmo en general tiene una complejidad de O(log n).

## Función Visit

La función visit cuenta con 4 llamadas a la clase de TreeNode, para poder imprimir de 4 maneras diferentes el árbol. 
La función visit que está en la clase BST tiene una complejidad de **O(1)**, ya que siempre sigue las mismas líneas de 
código y no depende de ninguna variable. Las otras cuatro funciones cuentan nada más con condicionales, por lo que no 
hay iteraciones; pero tienen recursión, por lo que estas tienen una complejidad de **O(n)**, ya que dependen del caso base
para detener la recursión.

## Función Height

La función height de la clase BST tiene una complejidad de **O(1)**, debido a que siempre va a hacer la misma línea de código.
La función height dentro de la clase TreeNode tiene una complejidad de **O(n)**, ya que en dos condicionales hay recursión. 

## Función Ancestors

Ancestors en BST tiene una complejidad de **O(1)**, ya que el código es lineal, solamente tiene un condicional y no tiene ciclos
ni recursión. Dentro de la clase TreeNode, tiene una complejidad de **O(n)** debido a que tiene recursión. Depende del caso base
cuántas recursiones hace la función. 

## Función What Level Am I

La función whatlevelamI en BST tiene una complejidad **O(1)**, ya que solamente tiene una línea de código que siempre se va a hacer
igual. Dentro de la clase TreeNode tiene una complejidad de **O(n)**, debido a que al igual que las otras funciones dentro de TreeNode
realiza recursión. La cual depende del caso base. 

---
# Correcciones hechas

El código no contaba con los recorridos implementados ya que no comprendía como funcionaban. Se implementaron los recorridos 
y la función de ancestors, la cual todavía cuenta con un error que no comprendo y que no logro solucionar. 

Además, completé el análisis de complejidad de las funciones. 