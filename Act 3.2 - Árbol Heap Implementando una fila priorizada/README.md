#full

**Análisis de complejidad temporal**

Esta función determina si el heap esta lleno o no al comparar su tamaño con su cuenta, si las tienen el mismo valor entero, regresa true. Su complejidad temporal es de O(1) para el peor de los casos.

#parent

**Análisis de complejidad temporal**

Esta función regresa el indice del padre de la posicion que se le da. Su complejidad temporal es de O(1) para el peor de los casos.

#push

**Análisis de complejidad temporal**

Este algoritmo primero determina si el heap esta lleno o no, si no esta lleno, elevara el conteo que se tiene, si el heap esta vacio solo le da un valor a la posición inicial. Si no esta vacio, comparará el valor a insertar con el valor de su padre para determinar cual es menor, de tal forma que el menor esté más elevado. Su complejidad temporal es de O(log n) para el peor de los casos.

#to String

**Análisis de complejidad temporal**

Esta función recorre todo espacio del heap que esté contado e imprime los valores que tiene. Su complejidad temporal es de O(n) para el peor de los casos.

#left

**Análisis de complejidad temporal**

Esta función define cual es el indice del hijo izquierdo de la posicion que recibe. Su complejidad temporal es de O(1) para el peor de los casos.

#right

**Análisis de complejidad temporal**

Esta función define cual es el indice del hijo derecho de la posicion que recibe. Su complejidad temporal es de O(1) para el peor de los casos.

#swap

**Análisis de complejidad temporal**

Esta función intercambia los datos de los dos indices que recibe con la ayuda de un auxiliar. Su complejidad temporal es de O(1) para el peor de los casos.

#heapify

**Análisis de complejidad temporal**

Este algoritmo realiza recursión para intercambiar la posición que se le dé con sus hijos, cambiando con swap de tal forma que el valor minimo quede hasta arriba. Su complejidad temporal es de O(log n) para el peor de los casos.

#pop

**Análisis de complejidad temporal**

Este algoritmo reemplaza el valor de la cima del heap por el valor que tenga en la cola, disminuye la cuenta para que no se tome en cuenta el indice que antes ocupaba, y luego manda a llamar heapify para que se ordenen los valores dejando los valores más pequeños arriba y los mayores hasta abajo. Su complejidad temporal es de O(n) para el peor de los casos.

#size

**Análisis de complejidad temporal**

Esta función, en el contexto que se da en el main, regresa el tamaño del heap que se está usando, no el tamaño que puede llegar a usar el heap. Su complejidad temporal es de O(1) para el peor de los casos.


#top

**Análisis de complejidad temporal**

Esta función regresa el valor que está a la cima del heap. Su complejidad temporal es de O(1) para el peor de los casos.

#empty

**Análisis de complejidad temporal**

Esta función regresa un booleano indicando si el heap esta vacio de tal forma que si la cuenta es 0, está vacio.  Su complejidad temporal es de O(1) para el peor de los casos.
