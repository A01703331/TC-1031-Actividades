/*
 *  list.h
 *
 *  Created on: 08/11/2021
 *  José Sebastián Pedrero Jiménez
 */

#ifndef LIST_H
#define LIST_H

#include <string>
#include <sstream>
#include <iostream>
#include "node.h"

template <class T>
class List {
private:
	Node<T> *head;
	int 	size;
public:
	List();
	~List();
	int  length() const;
	bool empty() const;
	bool contains(T) const;
	void clear();
	std::string toString() const;
	T    front() const;
	T    last() const;
	void push_front(T);
	void insertion(T);
	void update(int, T);
	T    deleteAt(int);
	long int  search(T) const;
};

template <class T>
List<T>::List() :head(NULL), size(0) {
}

template <class T>
List<T>::~List() {
	clear();
}

template <class T>
bool List<T>::empty() const {
	return (head == NULL);
}

template <class T>
int List<T>::length() const {
	return size;
}

template <class T>
bool List<T>::contains(T val) const {
	Node<T> *p;

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
void List<T>::clear() {
	Node<T> *p, *q;

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
std::string List<T>::toString() const {
	std::stringstream aux;
	Node<T> *p;

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
T List<T>::front() const {
	return head->value;
}

template <class T>
T List<T>::last() const {
	Node<T> *p;
	p = head;
	while (p->next != NULL) {
		p = p->next;
	}
	return p->value;
}

template <class T>
void List<T>::push_front(T val) {
	Node<T> *q;

	q = new Node<T>(val);
	q->next = head;
	head = q;
	size++;
}

template <class T>
void List<T>::insertion(T val) {
	Node<T> *p, *q;

	if (empty()) {
		push_front(val);
		return;
	}

	p = head;
	while (p->next != NULL) {
		p = p->next;
	}

	q = new Node<T>(val);
	q->next = p->next;
	p->next = q;
	size++;
}

template <class T>
void List<T>::update(int index,T val) {
		deleteAt(index);
		Node<T> *p, *q;
		p=head;
		q=p->next;
		for (int i = 1; i < index; i++){
			p = p->next;
			q = q->next;
		}
		p->next=q;
		p->next = new Node<T>(val);
		p = p->next;
		p->next = q;
		size++;
}

template <class T>
T List<T>::deleteAt(int index) {
	T k;
	Node<T> *p, *q;
	p=head;
	q=p->next;	
	if (index == 0){
		head=q;
		delete p;
		return k;
	}
	for (int i = 1; i < index; i++){
		p = p->next;
		q = q->next;
	}
	p->next=q->next;
	delete q;
	size--;
	return k;
}

template <class T>
long int List<T>::search(T val) const {
	bool found;
	found=contains(val);
	if(found == true){
		Node<T> *p;
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