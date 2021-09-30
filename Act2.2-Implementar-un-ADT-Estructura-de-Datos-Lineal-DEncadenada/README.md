# Implementación de Listas Doblemente Ligadas
## Análisis de Complejidad

La función insertion tiene complejidad de O(1), debido a que el código es secuencial.
La función search tiene complejidad O(n), ya que tiene un ciclo while y depende de la variable en el caso base.
La función empty es secuencial por lo que es O(1).
La función deleteAt es secuencial por lo que tiene complejidad O(1).
La función update tiene un ciclo while que depende de la variable en caso base, por lo que es O(n).
La función clear tiene un ciclo while por lo que la complejidad es O(n).
La función tostringFoward y tostringBackward tiene un ciclo while, y dentro de el un if. El if tiene complejidad O(1), y while tiene complejidad O(n). Entonces la función tiene complejidad O(n).

# Nota del ejercicio
Por lo que alcancé a notar, en el main se pide eliminar el índice 0, y dentro de la lista el índice 0 es 13. Por lo que considero que el caso prueba está erróneo. 