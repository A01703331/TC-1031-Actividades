#switcheroo

**Análisis de complejidad temporal**

Este algoritmo no tiene pasos ya que es una instrucción simple de igualamiento, por lo que su complejidad es de O(1) para el peor caso.

#copiar Arrangement (copiarArr)

**Análisis de complejidad temporal**

Este algoritmo recorre todos los espacios del arrangement para igualar los datos a otro arrangement, por lo que para el peor de los casos, su complejidad es de O(n) para el peor de los casos.

#merge Arrangement (mergeArr)

**Análisis de complejidad temporal**

Este algoritmo hace un recorrido verificando que las mitades del arrangement se copien en orden ascendente hasta que todos los datos de una mitad sean ordenados correctamente, posteriormente ordena la otra mitad, por lo que este algoritmo es de complejidad O(n) para el peor de los casos.

#merge Split

**Análisis de complejidad temporal**

Este algoritmo hace recursion "n" cantidad de veces hasta que ya no sea posible dividir los extremos entre más mitades, por lo que su complejidad sería de O(n) para el peor de los casos.

#busqueda Secuencial 

**Análisis de complejidad temporal**

Este alrgoritmo recorre al array "n" pasos para encontrar el valor deseado, por lo que su complejidad es de O(n) para el peor de los casos.

#busqueda Binaria

**Análisis de complejidad temporal**

Este algoritmo recorre el array ordenado de tal forma que divide el array en mitades dependiendo si el valor deseado es mayor o menor al punto medio de este mismo, por lo que su complejidad es de O(n) para el peor caso.

#ordena Seleccion

**Análisis de complejidad temporal**

Este algoritmo va recorriendo el array varias veces de forma descendente e intercambiando los valores de tal forma que los valores más altos se pasen al final y cambien posicion con valores menores, por lo que su complejidad es de O(n^2) para el peor de los casos.

#ordena Burbuja

**Análisis de complejidad temporal**

Este algoritmo recorre el array varias veces de tal forma que vaya elevando los valores mayores paso por paso intercambiando los valores en dos indices, esto la hace hasta que ya no haya casos que satisfagan la condicion que compara dos indicies entre si (a>b), por lo que su complejidad es de O(n^2).

#ordena Merge

**Análisis de complejidad temporal**

Este algoritmo hace llamar a las funciones mergeSplit, mergeArr, y copiarArr, haciendo un algoritmo que vaya tomando mitades de un mismo arrangement hasta que ya no pueda hacer mitades y las ordena por llamada, cada vez que se regresa el ordenamiento hay una mitad ordenada que se usa para luego ordenar una parte mayor hasta que todo queda ordenado, su comlpejidad es de O(nlogn) para el peor de los casos y es una razon por la que seria el mejor ordenamiento de esta actividad.