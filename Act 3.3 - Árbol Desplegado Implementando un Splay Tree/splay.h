/*
 *  splay.h
 *
 *  Created on: 15/11/2021
 *      Author: Jose Sebastian Pedrero Jimenez
 */

#ifndef SPLAY_H_
#define SPLAY_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T> class SplayTree;

template <class T>
class Branch {
private:
	T value;
	Branch *left, *right, *parent;

	Branch<T>* succesor();
	Branch<T>* rot_right(Branch<T>*);
	Branch<T>* rot_left(Branch<T>*);

public:
	Branch(int);
	Branch(int, Branch<T>*, Branch<T>* ,Branch<T>*);
	Branch<T>* add(int);
	Branch<T>* find(int);
	Branch<T>* remove(int);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void print_tree(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	Branch<T>* splay(Branch<T>*, Branch<T>*);

	friend class SplayTree<T>;
};

template <class T>
Branch<T>::Branch(int val) : value(val), left(0), right(0), parent(0) {}

template <class T>
Branch<T>::Branch(int val, Branch<T> *le, Branch<T> *ri, Branch<T> *p)
	: value(val), left(le), right(ri), parent(p) {}

template <class T>
Branch<T>* Branch<T>::add(int val) {
	if (val < value) {
		if (left != NULL) {
			return left->add(val);
		} else {
			left = new Branch<T>(val);
			left->parent = this;
			return left;
		}
	} else {
		if (right != NULL) {
			return right->add(val);
		} else {
			right = new Branch<T>(val);
			right->parent = this;
			return right;
		}
	}
}

template <class T>
Branch<T>* Branch<T>::find(int val) {
	if (val == value) {
		return this;
	} else if (val < value) {
		if (left != NULL)
		 	return left->find(val);
		else
			return this;
	} else {
		if (right != NULL)
		 	return right->find(val);
		else
			return this;
	}
}

template <class T>
Branch<T>* Branch<T>::succesor() {
	Branch<T> *le, *ri;

	le = left;
	ri = right;

	if (right->left == NULL) {
		right = right->right;
		ri->right = NULL;
		return ri;
	}

	Branch<T> *parent, *child;
	parent = right;
	child = right->left;
	while (child->left != NULL) {
		parent = child;
		child = child->left;
	}
	parent->left = child->right;
	child->right = NULL;
	return child;
}

template <class T>
Branch<T>* Branch<T>::remove(int val) {
	Branch<T> *succ, *old;
	if (val < value) {
		if (left != NULL) {
			if (left->value == val) {
				old = left;
				if(old->left != NULL && old->right != NULL){ // dos hijos sucesor
					succ = left->succesor();
					if (succ != NULL) {
						succ->left = old->left;
						succ->right = old->right;
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					left = succ;
				} else if (old->right != NULL){ // solo hijo der
					old->right->parent = left->parent;
					left = old->right;

				} else if (old->left != NULL){ // solo hijo izq
					old->left->parent = left->parent;
					left = old->left;
				} else {  // hoja
					left = NULL;
				}
				delete old;
				return this;
			} else {
				return left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != NULL) {
			if (right->value == val) {
				old = right;
				if(old->left != NULL && old->right != NULL){ // dos hijos sucesor
					succ = right->succesor();
					if (succ != NULL) {
						succ->left = old->left;
						succ->right = old->right;
						succ->parent = old->parent;
						if(succ->left)
							succ->left->parent = succ;
						if(succ->right)
							succ->right->parent = succ;
					}
					right = succ;
				} else if (old->right != NULL){ // solo hijo der
					old->right->parent = right->parent;
					right = old->right;

				} else if (old->left != NULL){ // solo hijo izq
					old->left->parent = right->parent;
					right = old->left;
				} else {  // hoja
					right = NULL;
				}
				delete old;
				return this;
			} else {
				return right->remove(val);
			}
		}
	}
	return this; // to avoid warning
}

template <class T>
void Branch<T>::removeChilds() {
	if (left != NULL) {
		left->removeChilds();
		delete left;
		left = NULL;
	}
	if (right != NULL) {
		right->removeChilds();
		delete right;
		right = NULL;
	}
}

template <class T>
Branch<T>* Branch<T>::rot_right(Branch<T>* x){
	Branch<T> *y = x->left;
	x->left = y->right;
	if(y->right)
		y->right->parent = x;
	y->right = x;
	// enlace de y con el padre de x
	y->parent = x->parent;
	x->parent = y;
	// hace enlace del padre de x a y
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template <class T>
Branch<T>* Branch<T>::rot_left(Branch<T>* x){
	Branch<T> *y = x->right;
	x->right = y->left;
	if(y->left)
		y->left->parent = x;
	y->left = x;
	// enlace de y con el padre de x
	y->parent = x->parent;
	x->parent = y;
	// hace enlace del padre de x a y
	if(y->parent){
		if(y->parent->left && y->parent->left->value == x->value)
			y->parent->left = y;
		else
			y->parent->right = y;
	}
	return y;
}

template <class T>
Branch<T>* Branch<T>::splay(Branch<T>* root, Branch<T>* x){
	while(x->parent != NULL){

		if(x->parent->value == root->value){
			if(x->parent->left && x->parent->left->value == x->value){
				rot_right(x->parent);
			}else{
				rot_left(x->parent);
			}
		}else{
			Branch<T>*p = x->parent; // parent
			Branch<T>*g = p->parent; // granparent
			if(p->left && g->left &&
				x->value == p->left->value && p->value == g->left->value){
				rot_right(g);
				rot_right(p);
			}else if(p->right && g->right &&
				x->value == p->right->value && p->value == g->right->value){
				rot_left(g);
				rot_left(p);
			}else	if(p->left && g->right &&
				x->value == p->left->value && p->value == g->right->value){
				rot_right(p);
				rot_left(g);
			}else{
				rot_left(p);
				rot_right(g);
			}
		}
	}
	return x;
}

template <class T>
void Branch<T>::inorder(std::stringstream &aux) const {
	if (left != NULL) {
		left->inorder(aux);
		aux << " ";
	}
	aux << value;
	if (right != NULL) {
        aux << " ";
		right->inorder(aux);
	}
}

template <class T>
void Branch<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != NULL) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != NULL) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
void Branch<T>::print_tree(std::stringstream &aux) const {
	if (parent != NULL){
		aux << "\n node " << value;
		aux << " parent " << parent->value;
	}else
		aux << "\n root " << value;
	if (left != NULL)
		aux << " left " << left->value;
	if (right != NULL)
		aux << " right " << right->value;
	aux << "\n";

	if (left != NULL) {
		left->print_tree(aux);
	}
	if (right != NULL) {
		right->print_tree(aux);
	}
}

template <class T>
class SplayTree {
private:
	Branch<T> *root;
    unsigned int tamanio = 0;

public:
	SplayTree();
	~SplayTree();
	bool empty() const;
	void add(int);
	bool find(int);
	void remove(int);
	void removeAll();
	std::string inorder() const;
	std::string print_tree() const;
	std::string preorder() const;
    int size() const;
};

template <class T>
SplayTree<T>::SplayTree() : root(0) {}

template <class T>
SplayTree<T>::~SplayTree() {
	removeAll();
}

template <class T>
bool SplayTree<T>::empty() const {
	return (root == NULL);
}

template<class T>
void SplayTree<T>::add(int val) {

	if (root != NULL) {
			Branch<T>* addition = root->add(val);
			root = root->splay(root,addition);
            tamanio++;
	} else {
		root = new Branch<T>(val);
        tamanio++;
	}
}

template <class T>
void SplayTree<T>::remove(int val) {
	if (root != NULL) {
		if (val == root->value) {
			Branch<T> *succ = root->succesor();
			if (succ != NULL) {
					succ->left = root->left;
					succ->right = root->right;
					succ->parent = NULL;
					if(succ->left)
						succ->left->parent = succ;
					if(succ->right)
						succ->right->parent = succ;
			}
			delete root;
			root = succ;
            tamanio--;
		} else {
			Branch<T>* p = root->remove(val);
			root = root->splay(root,p);
            tamanio--;
		}
	}
}

template <class T>
void SplayTree<T>::removeAll() {
	if (root != NULL) {
		root->removeChilds();
	}
	delete root;
    tamanio = 0;
	root = NULL;
}

template <class T>
bool SplayTree<T>::find(int val){
	if (root != NULL) {
		Branch<T>* found = root->find(val);
		root = root->splay(root,found);
		return (root->value == val);
	} else {
		return false;
	}
}

template <class T>
std::string SplayTree<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string SplayTree<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string SplayTree<T>::print_tree() const {
	std::stringstream aux;

	aux << "\n ================================ ";
	if (!empty()) {
		root->print_tree(aux);
	}
	aux << " ================================ \n";
	return aux.str();
}

template <class T>
int SplayTree<T>::size() const{
    return tamanio;
}

#endif