/** 
 * Jose Sebastian Pedrero Jimenez
 * A01703331
 * 25/Agosto/2021
*/


#ifndef SORTS_H_
#define SORTS_H_

#include <iostream>
#include <vector>
#include <list>

template <class T>
class Sorts {
    private:
        void switcheroo(std::vector<T>&, int, int);
        void copiarArr(std::vector<T>&, std::vector<T>&, int, int);
    	void mergeArr(std::vector<T>&, std::vector<T>&, int, int, int);
	    void mergeSplit(std::vector<T>&, std::vector<T>&, int, int);
    public:
        int busqSecuencial(std::vector<int>, int val);
        int busqBinaria(std::vector<int>, int val);
        std::vector<T> ordenaSeleccion(const std::vector<T>&);
        std::vector<T> ordenaBurbuja(const std::vector<T>&);
        std::vector<T> ordenaMerge(const std::vector<T>&);
};

template <class T>
void Sorts<T>::switcheroo(std::vector<T> &sarr, int i, int j) {
	T aux = sarr[i];
	sarr[i] = sarr[j];
	sarr[j] = aux;
};

template <class T>
std::vector<T> Sorts<T>::ordenaBurbuja(const std::vector<T> &arr){
    std::vector<T> sarr(arr);

    for (int i = sarr.size() - 1; i > 0; i--){
        for (int j = 0; j < i; j++){
            if (sarr[j] > sarr[j+1]){
                switcheroo(sarr, j, j+1);
            };
        };
    };
    return sarr;
};

template <class T>
std::vector<T> Sorts<T>::ordenaSeleccion(const std::vector<T> &arr){
    std::vector<T> sarr(arr);
    int pos;

    for (int i = sarr.size()-1; i>0; i--){
        pos = 0;
        for (int j = 1; j <= i; j++){
            if (sarr[j] > sarr[pos]){
                pos = j;
            };
        };

        if (pos != i){
            switcheroo(sarr, i ,pos);
        };
    };
    return sarr;
};

template <class T>
void Sorts<T>::copiarArr(std::vector<T> &A, std::vector<T> &B, int L, int H) {
	for (int i = L; i <= H; i++) {
		A[i] = B[i];
	};
};

template <class T>
void Sorts<T>::mergeArr(std::vector<T> &A, std::vector<T> &B, int L, int hal, int H) {
	int i, j, k;

	i = L;
	j = hal + 1;
	k = L;

	while (i <= hal && j<=H) {
		if (A[i] < A[j]) {
			B[k] = A[i];
			i++;
		} else {
			B[k] = A[j];
			j++;
		}
		k++;
	}
	if (i > hal) {
		for (; j <= H; j++) {
			B[k++] = A[j];
		};
	} else {
		for (; i <= hal; i++) {
			B[k++] = A[i];
		};
	};
};

template <class T>
void Sorts<T>::mergeSplit(std::vector<T> &A, std::vector<T> &B, int L, int H) {
	int hal;

	if ((H - L) < 1) {
		return; // Verifica si ya no se puede separar en mitades
	}
	hal = (H + L) / 2;
	mergeSplit(A, B, L, hal); // Agarra la primera mitad del array A para ordenarlo en B
	mergeSplit(A, B, hal + 1, H); // Agarra la segunda mitad del array A para ordenarlo en B
	mergeArr(A, B, L, hal, H); // Combina los arrays 
	copiarArr(A, B, L, H); // Copia los valores de B hacia A
};

template <class T>
std::vector<T> Sorts<T>::ordenaMerge(const std::vector<T> &arr){
    std::vector<T> sarr(arr);
    std::vector<T> tarr(sarr.size());
    mergeSplit(sarr,tarr, 0, sarr.size() - 1);
    return sarr;
};

template <class T>
int Sorts<T>::busqSecuencial(std::vector<int> arr, int val) {
    for (int i=0;i<arr.size()-1;i++){
        if (val == arr[i]){
            return i;
        };
    };
    return -1;
};

template <class T>
int Sorts<T>::busqBinaria(std::vector<int> arr, int val) {
    int hal;
    int L = 0;
    int H = arr.size() - 1;

    while (L<H){
        hal = (L+H)/2; // Verifica el indice de en medio
        if (val == arr[hal]){
            return hal; // Regresa el valor del indice
        }   else if (val < arr[hal]){
            H = hal - 1; // Si el valor a buscar es menor al del medio, solo agarra la primera mitad para buscar otra vez
        }   else if (val > arr[hal]){
            L = hal  + 1; // Si el valor a buscar es mayor  al del medio, solo agarra la segunda mitad para buscar otra vez
        };
    };
    return -1; // Si el valor no esta en el array, solo regresa -1
};

#endif
