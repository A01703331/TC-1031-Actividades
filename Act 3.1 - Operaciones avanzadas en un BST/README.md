#find (Branch)

**Análisis de complejidad temporal**

Esta función determina si el valor deseado existe dentro del arbol para evitar que haya entradas duplicadas. Su complejidad de tiempo es de O(n) para el peor de los casos.

#add (Branch)

**Análisis de complejidad temporal**

Esta función hace recursión consigo misma hasta encontrar un lugar vacio donde el valor deseado a agregar sea apropiado dentro del contexto de un arbol de busqueda binaria. Su complejidad de tiempo es de O(n) para el peor de los casos.

#add

**Análisis de complejidad temporal**

Este algoritmo genera un nodo si el arbol esta vacio, en caso de que no lo esté, manda a llamar la función find de Branch para evitar que haya duplicados, y en caso de que no encuentre el valor, manda a llamar a la función add de Branch para agregar el nuevo nodo. Su complejidad de tiempo es de O(n log n) para el peor de los casos.

#preorder (Branch)

**Análisis de complejidad temporal**

Esta función hace recursión para recorrer todo el arbol e imprime sus valores en el orden en que los encuentra; primero recorre desde la raiz hacia los valores que haya a la izquierda, y después hacia la derecha. Su complejidad de tiempo es de O(n) para el peor de los casos.

#inorder (Branch)

**Análisis de complejidad temporal**

Esta función hace recursión para recorrer todo el arbol e imprime sus valores en orden numérico. Su complejidad de tiempo es de O(n) para el peor de los casos.

#postorder (Branch)

**Análisis de complejidad temporal**

Esta función hace recursión para recorrer todo el arbol e imprime sus valores desde la parte más alejada de la raíz en ambos lados hasta regresar a la raíz. Su complejidad de tiempo es de O(n) para el peor de los casos.

#print Level

**Análisis de complejidad temporal**

Esta función recibe un número entero que representa el nivel que se desea imprimir, después hace recursión hasta que ese número sea cero, donde se imprimiran todos los valores de los nodos donde haya llegado a 0. Su complejidad de tiempo es de O(n) para el peor de los casos.

#levelorder (Branch)

**Análisis de complejidad temporal**

Este algoritmo recibe un número entero que representa la altura del arbol, el cual se utilizará en un ciclo for para llamar a la función print Level y de esta forma imprimir los niveles desde el nivel de la raíz del arbol hasta el nivel más alto, aunque deja un espacio al final que queda de más. Su complejidad de tiempo es de O(n) para el peor de los casos.

#max Height (Branch)

**Análisis de complejidad temporal**

Esta función recorre las ramas del arbol para obtener las alturas más altas mediante recursión y las compara entre si, regresando el valor más alto que representa la altura del arbol en sí. Su complejidad de tiempo es de O(n) para el peor de los casos.

#visit

**Análisis de complejidad temporal**

Este algoritmo manda a llamar las funciones preorder, inorder, postorder, y levelorder de Branch (en ese orden) para imprimir el arbol de las maneras que se establecieron en el caso de prueba. Debido a la forma en que level order funciona, al final le quita el espacio que sobra mediante la función seekp dentro de las librerias de c++ antes de cerrar el último corchete. Su complejidad de tiempo es de O(n log n) para el peor de los casos.

#height

**Análisis de complejidad temporal**

Este algoritmo manda a llamar la función maxHeight de Branch para recuperar la altura del arbol. Su complejidad de tiempo es de O(n) para el peor de los casos.

#ancestors (Branch)

**Análisis de complejidad temporal**

Este algoritmo recorre el arbol de la misma manera que la funcion find, solo que este imprime los valores hasta que llega al valor deseado, esto representa la descendencia de la hoja. Su complejidad de tiempo es de O(n) para el peor de los casos.

#ancestors

**Análisis de complejidad temporal**

Este algoritmo primero busca si el valor deseado esta en el arbol mediante la función find de Branch para evitar complicaciones, luego manda a llamar la función ancestors de Branch para imprimir los ancestros del valor deseado. Su complejidad de tiempo es de O(n log n) para el peor de los casos.

#get Level (Branch)

**Análisis de complejidad temporal**

Esta función hace recursión de tal forma que explora los nodos hasta encontrar el valor deseado, donde cada retorno a la primera llamada incrementa el valor por uno. Su complejidad de tiempo es de O(n) para el peor de los casos.

#what Level Am I

**Análisis de complejidad temporal**

Este algoritmo primero busca si el valor deseado esta en el arbol mediante la función find de Branch para evitar complicaciones, luego llama a la función get Level de Branch para obtener el nivel del valor deseado. Su complejidad de tiempo es de O(n log n) para el peor de los casos.
