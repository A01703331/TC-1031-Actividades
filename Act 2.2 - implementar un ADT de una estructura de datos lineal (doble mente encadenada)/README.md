#insertion

**Análisis de complejidad temporal**

Este algoritmo crea un nuevo nodo al final de la lista, si esta está vacia entonces la cabeza y la cola seran igualadas el primer nodo creado. Si la lista ya contiene nodos, entonces agregara un nuevo nodo al final de la lista y la cola pasara a ser el nuevo nodo. Esto tambien vincula la nueva cola con su espacio anterior para que no haya errores al recorrer la lista en ambas direcciones. Su complejidad temporal es de O(1) para el peor caso.

#to String Forward

**Análisis de complejidad temporal**

Este algoritmo recorre todos los nodos de la lista desde la cabeza hasta la cola e imprime sus valores, así que su complejidad temporal es de O(n) para el peor caso.

#to String Backward

**Análisis de complejidad temporal**

Este algoritmo recorre todos los nodos de la lista desde la cola hasta la cabeza e imprime sus valores, así que su complejidad temporal es de O(n) para el peor caso.

#search

**Análisis de complejidad temporal**

Este algoritmo manda a llamar la funcion contains para determinar si el valor deseado esta en la lista. Una vez que lo encuentra, recorre la lista una vez más desde la cabeza para encontrar el indice en el que esta el valor. Debido a que recorre la lista dos veces, su complejidad temporal sería de O(n log n) para el peor de los casos.

#contains

**Análisis de complejidad temporal**

Esta funcion recorre la lista desde la cabeza hasta encontrar el valor deseado, si lo encuentra, regresa un True, y si no, un False. Su complejidad temporal es de O(n) para el peor caso.

#update

**Análisis de complejidad temporal**

Esta función recibe un indice y un valor, recorre el algoritmo hasta llegar al indice deseado, una vez que llega, reemplaza el valor que tenia. Su complejidad temporal es de O(n) para el peor caso.

#delete At 

**Análisis de complejidad temporal**

Esta función recibe un indice, y borra el nodo que esta en ese indice, vinculando el indice anterior con el siguiente para que no haya errores al recorrer la lista, considerando los casos en que se borre el último indice, uno intermedio, o el primero. Su complejidad temporal es de O(n) para el peor caso.
