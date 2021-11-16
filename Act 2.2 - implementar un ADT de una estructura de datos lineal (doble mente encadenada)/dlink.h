#ifndef DLINK_H
#define DLINK_H

#include <string>
#include <sstream>

template <class T> class DList;

template <class T>
class DLink {
private:
	DLink(T);
	DLink(T, DLink<T>*, DLink<T>*);
	DLink(const DLink<T>&);
	T	    value;
	DLink<T> *next;
	DLink<T> *previous;
	friend class DList<T>;
};

template <class T>
DLink<T>::DLink(T val) : value(val), next(NULL), previous(NULL){
}

template <class T>
DLink<T>::DLink(T val, DLink *nxt, DLink *prv) : value(val), next(nxt), previous(prv){
}

#endif