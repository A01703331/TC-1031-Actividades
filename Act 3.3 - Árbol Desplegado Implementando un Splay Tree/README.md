#turnLeft (Branch)

**Análisis de complejidad temporal**

Este algoritmo gira el nodo de tal forma que el nodo que se le da queda en la posición izquierda del mismo, reemplazando su ubicacion con el nodo que tenia a la derecha. Su complejidad temporal es de O(1) para el peor de los casos.

#turnRight (Branch)

**Análisis de complejidad temporal**

Este algoritmo gira el nodo de tal forma que el nodo que se le da queda en la posición derecha del mismo, reemplazando su ubicacion con el nodo que tenia a la izquierda. Su complejidad temporal es de O(1) para el peor de los casos.

#splay (Branch)

**Análisis de complejidad temporal**

Este algoritmo considera los diferentes casos que pueden ocurrir, mediante un ciclo while hará los giros necesarios para que el nodo deseado quede en la cima del árbol, esto se cumple cuando el nodo ya no tiene parentezco. Su complejidad temporal es de O(log n) para el peor de los casos.

#add (Branch)

**Análisis de complejidad temporal**

Esta función recorre el árbol como si fuera un simple árbol BST para poder encontrar el lugar apropiado para hacer la inserción del valor que se le da. Su complejidad temporal es de O(n) para el peor de los casos.

#add 

**Análisis de complejidad temporal**

Este algoritmo primero se asegura de que la raíz no esté vacia, e incrementa el tamaño (en este contexto solo es un conteo de nodos válidos), después, manda a llamar la función add de Branch para poder obtener un nuevo nodo y su posición, la cual luego inserta junto con la raíz en la función splay para llevar este nodo a la cabeza. Su complejidad temporal es de O(n log n) para el peor de los casos.

#inorder (Branch)

**Análisis de complejidad temporal**

Esta función simplemente imprime los valores del arbol en orden numérico de menor a mayor. Su complejidad temporal es de O(n) para el peor de los casos.

#preorder (Branch)

**Análisis de complejidad temporal**

Esta función simplemente imprime los valores del arbol en el orden que los consulta, iniciando con consultas a la izquierda y luego a la derecha. Su complejidad temporal es de O(n) para el peor de los casos.

#inorder

**Análisis de complejidad temporal**

Esta función simplemente llama a la función inorder de Branch para imprimir los valores del arbol en orden numérico de menor a mayor. Su complejidad temporal es de O(n) para el peor de los casos.

#preorder

**Análisis de complejidad temporal**

Esta función simplemente llama a la función preorder de Branch para imprimir los valores del arbol en orden numérico de menor a mayor. Su complejidad temporal es de O(n) para el peor de los casos.

#findVal (Branch)

**Análisis de complejidad temporal**

Esta función busca si el valor que se le da existe dentro del árbol, regresando un booleano para evitar complicaciones a futuro. Su complejidad temporal es de O(n) para el peor de los casos.

#find (Branch)

**Análisis de complejidad temporal**

Esta función regresa la posición del valor deseado, está diseñada de tal forma que se use después de confirmar la existencia o absencia del valor que se le da en el árbol. Su complejidad temporal es de O(n) para el peor de los casos.

#find

**Análisis de complejidad temporal**

Este algoritmo primero se asegura de que la raíz no sea nula, luego confirma si el nodo está en el árbol mediante la función findVal. Si no existe el valor, o la raíz es nula, solo regresa un falso. Si el valor existe, obtiene la posición del valor, y luego la usa en el splay junto con la raíz para llevar el nodo con el valor deseado a la cima. Su complejidad temporal es de O(n log n) para el peor de los casos.

#succesor (Branch)

**Análisis de complejidad temporal**

Este algoritmo busca cuál es el valor que sigue en el árbol de la posición actual, para regresar la posición de este mismo. Su complejidad temporal es de O(log n) para el peor de los casos.

#remove (Branch)

**Análisis de complejidad temporal**

Este algoritmo recorre el arbol para buscar el valor a borrar. Dependiendo de la situación, revinculara los nodos de tal forma que respeten las reglas de un splay tree(vinculando padres, izquierdas, y derechas). Al finalizar habrá borrado el nodo con el valor que se le dio y regresara la ubicación del sucesor. Su complejidad temporal es de O(n log n) para el peor de los casos.

#remove

**Análisis de complejidad temporal**

Este algoritmo primero se asegura de que haya una raíz valida, luego manda a llamar la función remove de Branch para borrar el nodo con el valor que se le da, y con la dirección del sucesor que recupera de la misma, manda a llamar splay junto con la raíz para llevar al sucesor a la cabeza. Si el valor a borrar es la raíz, manda a buscar un sucesor para definir a este como la nueva raíz, si este no es nulo, reemplaza sus vinculos existentes de parentezco y descendecia con los de la raíz. Después borra el nodo de raíz y posteriormente define al sucesor como la nueva raíz.  Su complejidad temporal es de O(n log n) para el peor de los casos.   