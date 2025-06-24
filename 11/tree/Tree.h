#pragma once
#include<iostream>
using namespace std;
//-----------------------------------
//  class Tree (Binary Trees)
// process nodes in Pre/In/Post  order
//-----------------------------------
template <class T> class Tree
{
protected:
	//--------------------------------------------------------
	//  inner class Node
	//      a single Node from a binary tree
	//--------------------------------------------------------
	class Node
	{
	public:
		Node* left;
		Node* right;
		T value;
		Node(T val)
			: value(val), left(nullptr), right(nullptr) {}
		Node(T val, Node* l, Node* r)
			: value(val), left(l), right(r) {}
	};		//end of Node class

	Node* root;

public:
	Tree() { root = nullptr; }	 // initialize tree
	~Tree();
	bool isEmpty() const;
	void clear() { clear(root); root = nullptr; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }

	int leaves() const { return leaves(root); }
	int height() const { return height(root); }
	void reflect() const { reflect(root); }
	int onlyLeftSon() const { return onlyLeftSon(root); }

	virtual void process(T val) { cout << val << " "; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;

private:
	void  clear(Node* current);
	void  preOrder(Node* current);
	void  inOrder(Node* current);
	void  postOrder(Node* current);

	int leaves(Node*) const;
	int height(Node*) const;
	void reflect(Node*) const;
	int onlyLeftSon(Node*) const;
};
//----------------------------------------------------------
//  class Tree implementation
//----------------------------------------------------------
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != nullptr)
		clear(root);
}

template <class T>
int Tree<T>::leaves(Node* current) const
{
	if (!current->right && !current->left) return 1;
	return (current->right ? leaves(current ->right) : 0) + (current->left ? leaves(current->left) : 0);
}

template <class T>
int Tree<T>::height(Node* current) const
{
	if (current == nullptr) return -1;
	return 1 + max(height(current->left), height(current->right));
}

template <class T>
void Tree<T>::reflect() const
{

}

template <class T>
int Tree<T>::onlyLeftSon() const
{

}

template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{    // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
		current = nullptr;
	}
}

template <class T>
bool Tree<T>::isEmpty() const
{
	return  root == nullptr;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(Node* current)
{    // visit Node, left child, right child
	if (current)
	{   // process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(Node* current)
{    // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}

template<class T>
// postOrder processing of tree rooted at current
inline void Tree<T>::postOrder(Node* current)
{   // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}

}
