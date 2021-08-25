/** 
 * Jose Sebastian Pedrero Jimenez
 * A01703331
 * 25/Agosto/2021
*/

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

//Declaracion de clase Funciones
class Funciones {
    //Variables de instancia
    private:
        int a;
    public:
        int sumaIterativa(int);
        int sumaRecursiva(int);
        int sumaDirecta(int);
};

int Funciones::sumaIterativa(int a){
    int tsum = 0;
    if (a == 0) {
        return 0;
    };
    for (int i=1; i<=a; i++)
        tsum = tsum + i;
    return tsum;
};

int Funciones::sumaRecursiva(int a){
    if (a <= 0) {
        return 0;
    }
    else {
        return a + sumaRecursiva(a-1);
    };
};

int Funciones::sumaDirecta(int a){
    if (a==0){
        return 0;
    }
    else{
        return (a*(a+1))/2;
    };
};

#endif