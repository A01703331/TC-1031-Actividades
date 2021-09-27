#ifndef NODE_H
#define NODE_H

#include <string>
#include <sstream>

template <class T> class List;

template <class T>
class Node {
private:
	Node(T);
	Node(T, Node<T>*);
	T	    value;
	Node<T> *next;
	friend class List<T>;
};

template <class T>
Node<T>::Node(T val) : value(val), next(NULL) {
}

template <class T>
Node<T>::Node(T val, Node* nxt) : value(val), next(nxt) {
}

#endif