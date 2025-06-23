#pragma once


// Template class for a binary tree
template <typename T>
class Tree
{
protected:
	class Node
	{
	private:
		T key;
		Node* right;
		Node* left;
	
	public:
		// Default node ctor
		Node(cosnt T& k = T()) : right(nullptr), left(nullptr)

		// Getters
		T getKey() const { return this->key; }
		Node* getRight() const { return this->right; }
		Node* getLeft() const { return this->left; }

		// Setters
		void setKey(const T& k) { this->key = k; }
		void setRight(Node* n) { this->right = n; }
		void setLeft(Node* n) { this->left = n; }

		void clearNode();
	};

	Node* head;

public:
	Tree() : head(nullptr) {}
};


template <typename T>
void Tree<T>::Node::clearNode()
{
	delete this->right;
	this->right = nullptr;
	delete this->left; 
	this->left = nullptr;
}
