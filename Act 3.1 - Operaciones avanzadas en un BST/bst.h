/*
 * bst.h
 *
 *  Created on: 02/11/2021
 *      Author: Jose Sebastian Pedrero Jimenez
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include <iostream>

template <class T> class BST;

template <class T>
class Branch {
private:
	T value;
	Branch *left, *right;

	Branch<T>* succesor();

public:
	Branch(T);
	Branch(T, Branch<T>*, Branch<T>*);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;
	void postorder(std::stringstream&) const;
	void levelorder(std::stringstream&, Branch<T>*, int) const;
	void printLevel(std::stringstream &,Branch<T>*, int);
	int getLevel(T);
	int maxHeight(Branch<T>*);
	void ancestors(std::stringstream&, T) const;

	friend class BST<T>;
};

template <class T>
Branch<T>::Branch(T val) : value(val), left(0), right(0) {}

template <class T>
Branch<T>::Branch(T val, Branch<T> *le, Branch<T> *ri)
	: value(val), left(le), right(ri) {}

template <class T>
void Branch<T>::add(T val) {
	if (val < value) {
		if (left != NULL) {
			left->add(val);
		} else {
			left = new Branch<T>(val);
		}
	} else {
		if (right != NULL) {
			right->add(val);
		} else {
			right = new Branch<T>(val);
		}
	}
}

template <class T>
bool Branch<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		return (left != NULL && left->find(val));
	} else if (val > value) {
		return (right != NULL && right->find(val));
	} return false;
}

template <class T>
Branch<T>* Branch<T>::succesor() {
	Branch<T> *le, *ri;

	le = left;
	ri = right;

	if (left == NULL) {
		if (right != NULL) {
			right = NULL;
		}
		return ri;
	}

	if (left->right == NULL) {
		left = left->left;
		le->left = NULL;
		return le;
	}

	Branch<T> *parent, *child;
	parent = left;
	child = left->right;
	while (child->right != NULL) {
		parent = child;
		child = child->right;
	}
	parent->right = child->left;
	child->left = NULL;
	return child;
}

template <class T>
void Branch<T>::remove(T val) {
	Branch<T> * succ, *old;

	if (val < value) {
		if (left != NULL) {
			if (left->value == val) {
				old = left;
				succ = left->succesor();
				if (succ != NULL) {
					succ->left = old->left;
					succ->right = old->right;
				}
				left = succ;
				delete old;
			} else {
				left->remove(val);
			}
		}
	} else if (val > value) {
		if (right != NULL) {
			if (right->value == val) {
				old = right;
				succ = right->succesor();
				if (succ != NULL) {
					succ->left = old->left;
					succ->right = old->right;
				}
				right = succ;
				delete old;
			} else {
				right->remove(val);
			}
		}
	}
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
void Branch<T>::postorder(std::stringstream &aux) const {
	if (left != NULL) {
		left->postorder(aux);
		aux << " ";
	}
	if (right != NULL) {
		right->postorder(aux);
		aux << " ";
	}
	aux << value;
}

template <class T>
void Branch<T>::levelorder(std::stringstream &aux, Branch<T> *segment, int h) const {
	for (int i=0;i<h;i++){
		segment->printLevel(aux, segment, i);
	}
}

template <class T>
void Branch<T>::printLevel(std::stringstream &aux, Branch<T> *segment, int level){
    if (segment != NULL){
		if (level == 0) {
       		aux << segment->value;
			aux << " ";
   		} else if (level > 0) {
        	segment->printLevel(aux, segment->left, level - 1);
        	segment->printLevel(aux, segment->right, level - 1);
    	}	
	}
}

template <class T>
int Branch<T>::getLevel(T val) {
	if (val == value) {
		return 1;
	} else if (val < value) {
		return (left->getLevel(val)+1);
	} else if (val > value){
		return (right->getLevel(val)+1);
	} else {
		return -1;
	}
}

template <class T>
int Branch<T>::maxHeight(Branch<T> *segment){
	if (segment!=NULL){
		int L = maxHeight(segment->left);
		int R = maxHeight(segment->right);
		if (L>R) {
			return (L+1);
		} else{
			return (R+1);
		}
	} else {
		return 0;
	}
}

template <class T>
void Branch<T>::ancestors(std::stringstream &aux, T val) const{
	if (val<value){
		aux << value;
		if (left!=NULL){
			aux << " ";
			left->ancestors(aux, val);
		}
	} else if (val>value){
		aux << value;
		if (right!=NULL){
			aux << " ";
			right->ancestors(aux, val);
		}
	}
}

template <class T>
class BST {
private:
	Branch<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	void removeAll();
	std::string visit() const;
	int height();
	int whatlevelamI(T);
	std::string ancestors(T) const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == NULL);
}

template<class T>
void BST<T>::add(T val) {
	if (root != NULL) {
		if (!root->find(val)) {
			root->add(val);
		}
	} else {
		root = new Branch<T>(val);
	}
}

template <class T>
void BST<T>::remove(T val) {
	if (root != NULL) {
		if (val == root->value) {
			Branch<T> *succ = root->succesor();
			if (succ != NULL) {
				succ->left = root->left;
				succ->right = root->right;
			}
			delete root;
			root = succ;
		} else {
			root->remove(val);
		}
	}
}

template <class T>
void BST<T>::removeAll() {
	if (root != NULL) {
		root->removeChilds();
	}
	delete root;
	root = NULL;
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != NULL) {
		return root->find(val);
	} else {
		return false;
	}
}

template <class T>
std::string BST<T>::visit() const {
	std::stringstream aux;

	if (!empty()) {
		aux << "[";
		root->preorder(aux);
		aux << "]" << "\n" << "[";
		root->inorder(aux);
		aux << "]" << "\n" << "[";
		root->postorder(aux);
		aux << "]" << "\n" << "[";
		root->levelorder(aux, root, root->maxHeight(root));
		aux.seekp(-1, std::ios_base::end);
		aux << "]";
	}
	return aux.str();
}

template <class T>
int BST<T>::height() {
	if (!empty()){
		return root->maxHeight(root);
	} else {
		return 0;
	}
}

template <class T>
int BST<T>::whatlevelamI(T val){
	if (root->find(val)){
		return root->getLevel(val);
	}
	return -1;
}

template <class T>
std::string BST<T>::ancestors(T val) const {
	std::stringstream aux;
	
	if (!empty()) {
		aux << "[";
		if (root->find(val)){
			root->ancestors(aux, val);
			aux.seekp(-1, std::ios_base::end);
		}	
		aux << "]";
	}
	return aux.str();
}

#endif
