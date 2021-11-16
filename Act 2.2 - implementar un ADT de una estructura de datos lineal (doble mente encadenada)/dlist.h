/*
 *  dlist.h
 *
 *  Created on: 15/11/2021
 *  José Sebastián Pedrero Jiménez
 */

#ifndef DLIST_H_
#define DLIST_H_

#include <string>
#include <sstream>
#include <iostream>
#include "dlink.h"

template <class T>
class DList {
private:
	DLink<T> *head;
	DLink<T> *tail;
	int 	size;
public:
	DList();
	~DList();
	int  length() const;
	bool empty() const;
	bool contains(T) const;
	void clear();
	std::string toStringForward() const;
	std::string toStringBackward() const;
	T    front() const;
	T    last() const;
	void push_front(T);
	void insertion(T);
	void update(int, T);
	T    deleteAt(int);
	long int  search(T) const;
};


template <class T>
DList<T>::DList() :head(0), tail(0), size(0) {
}

template <class T>
DList<T>::~DList() {
	clear();
}

template <class T>
bool DList<T>::empty() const {
	return (head == NULL && tail == NULL);
}

template <class T>
int DList<T>::length() const {
	return size;
}

template <class T>
bool DList<T>::contains(T val) const {
	DLink<T> *p;

	p = head;
	while (p != NULL) {
		if(p->value == val) {
			return true;
		}
		p = p->next;
	}
	return false;
}

template <class T>
void DList<T>::clear() {
	DLink<T> *p, *q;

	p = head;
	while (p != NULL){
		q = p->next;
		delete p;
		p = q;
	}

	head = NULL;
	size = 0;
}

template <class T>
	std::string DList<T>::toStringForward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = head;
	aux << "[";
	while (p != NULL) {
		aux << p->value;
		if (p->next != NULL) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string DList<T>::toStringBackward() const {
	std::stringstream aux;
	DLink<T> *p;

	p = tail;
	aux << "[";
	while (p != NULL) {
		aux << p->value;
		if (p->previous != NULL) {
			aux << ", ";
		}
		p = p->previous;
	}
	aux << "]";
	return aux.str();
}

template <class T>
T DList<T>::front() const {
	return head->value;
}

template <class T>
T DList<T>::last() const {
	return tail->value;
}

template <class T>
void DList<T>::insertion(T val) {
	DLink<T> *addition;
	addition = new DLink<T>(val);
	if (empty()) {
		head = addition;
		tail = addition;
		return;
	}

	tail->next = addition;
	addition->previous = tail;
	tail = addition;
	size++;
}

template <class T>
void DList<T>::update(int index,T val) {
		DLink<T> *p, *q, *updation;
		p=head;
		for (int i = 1; i < index; i++){
			p = p->next;
		}
		q=p->next;
		q->value=val;
}

template <class T>
T DList<T>::deleteAt(int index) {
	T k;
	DLink<T> *p, *q, *deletion;
	p=head;
	deletion=p;	
	if (index == 0){
		head=p->next;
		head->previous=p->previous;
		delete deletion;
		return k;
	}
	for (int i = 1; i < index; i++){
		p = p->next;
	}
	q = p->next;
	deletion = q;
	if(q->next!=NULL){
		q = q->next;
		delete deletion;
		q->previous=p;
		p->next=q;
	}
	else{
		tail=p;
		delete deletion;
		p->next=NULL;
	}
	size--;
	return k;
}

template <class T>
long int DList<T>::search(T val) const {
	bool found;
	found=contains(val);
	if(found == true){
		DLink<T> *p;
		p=head;
		int i =0;
		while (p->value != val) {
			p = p->next;
			i++;
		}
		return i;
    }
		else{
			return -1;
    }
}

#endif