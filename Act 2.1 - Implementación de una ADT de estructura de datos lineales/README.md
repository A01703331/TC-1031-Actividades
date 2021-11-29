#insertion

**Análisis de complejidad temporal**

Este algoritmo crea un nuevo nodo en la lista si esta está vacia gracias a la ayuda de la funcion pushFront, si no esta vacia, recorre la lista desde la cabeza hasta que llega a un punto en el que encuentra un valor "siguiente" que sea nulo, entonces, crea un nuevo nodo. Por ello, para el peor caso su complejidad de tiempo es de O(n) para el peor caso. 

#push Front

**Análisis de complejidad temporal**

Esta funcion reemplaza la cabeza actual, empujando la anterior al siguiente espacio y cambiando la distincion de que el nuevo nodo que se crea es la cabeza mediante igualamientos. Su complejidad temporal es de O(1) para el peor caso.

#to String

**Análisis de complejidad temporal**

Este algoritmo recorre todos los nodos de la lista e imprime sus valores, no hay nada más, así que su complejidad temporal es de O(n) para el peor caso.

#search

**Análisis de complejidad temporal**

Este algoritmo manda a llamar la funcion contains para determinar si el valor deseado esta en la lista. Una vez que lo encuentra, recorre la lista una vez más para encontrar el indice en el que esta el valor. Debido a que recorre la lista dos veces, su complejidad temporal sería de O(n log n) para el peor de los casos.

#contains

**Análisis de complejidad temporal**

Esta funcion recorre la lista hasta encontrar el valor deseado, si lo encuentra, regresa un True, y si no, un False. Su complejidad temporal es de O(n) para el peor caso.

#update

**Análisis de complejidad temporal**

Esta función recibe un indice y un valor, recorre el algoritmo hasta llegar al indice deseado, una vez que llega, reemplaza el valor que tenia. Su complejidad temporal es de O(n) para el peor caso.

#delete At 

**Análisis de complejidad temporal**

Esta función recibe un indice, y borra el nodo que esta en ese indice, vinculando el indice anterior con el siguiente para que no haya errores al recorrer la lista. Su complejidad temporal es de O(n) para el peor caso.
