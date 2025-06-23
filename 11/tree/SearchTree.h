#pragma once

#include "Tree.h"

template <typename T>
class SearchTree : public Tree
{
public:
	void insert(const Node& n);
	void remove(const *Node);
	T minimum() const;
	T maximum() const;
	Node* successor() const;
};