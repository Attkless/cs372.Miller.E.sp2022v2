// Contents of BinaryTree.h using templated types
#pragma once

#include<iostream>
using namespace std;

// BinaryTree template
template <class T>
class BinaryTree{
	private:
		struct TreeNode {
			T value;
			TreeNode *left;
			TreeNode *right;
		};
		
		TreeNode *root; // Pointer to the root node.
		
		// Private member functions
		void insert(TreeNode *&, TreeNode *&);
		void destroySubTree(TreeNode *);
		void deleteNode(T, TreeNode *&);
		void makeDeletion(TreeNode *&);
		void displayInOrder(TreeNode *) const;
		void displayPreOrder(TreeNode *) const;
		void displayPostOrder(TreeNode *) const;
		
	public:
		// Constructor
		BinaryTree() {
			root = nullptr;
		}
		
		// Destructor
		~BinaryTree() {
			destroySubTree(root);
		}
		
		// Binary tree operations
		void insertNode(T);
		bool searchNode(T);
		void search(T);
		void remove(T);
		
		void displayInOrder() const {
			displayInOrder(root);
		}
		
		void displayPostOrder() const {
			displayPostOrder(root);
		}
		
		void displayPreOrder() const {
			displayPreOrder(root);
		}
};

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode) {
	if(nodePtr == nullptr)
		nodePtr = newNode;
	else if (newNode->value < nodePtr->value)
		insert(nodePtr->left, newNode); // search the left branch
	else
		insert(nodePtr->right, newNode); // search the right branch
}

template <class T>
void BinaryTree<T>::insertNode(T item) {
	TreeNode *newNode = nullptr; // Pointer to a new node.
	
	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = item;
	newNode->left = newNode->right = nullptr;
	
	// insert the node.
	insert(root, newNode);
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr) {
	if(nodePtr) {
		if(nodePtr->left) 
			destroySubTree(nodePtr->left);
		if(nodePtr->right)
			destroySubTree(nodePtr->right);
		delete nodePtr;
	}
}

template <class T>
bool BinaryTree<T>::searchNode(T item) {
	TreeNode *nodePtr = root;
	
	while(nodePtr) {
		if(nodePtr->value == item)
			return true;
		else if(item < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

template <class T>
void BinaryTree<T>::search(T value) {
	int depth = 0;
	TreeNode *temp = root; 
	while(temp != NULL) {
		depth++;
		if(temp->value == value) {
			cout << "\nItem found at depth: " << depth;
			return;
		}
		else if(temp->value > value)
			temp = temp->left;
		else
			temp = temp->right;
	}
	cout << "\n Item not found";
	return;
}

template <class T>
void BinaryTree<T>::remove(T item) {
	deleteNode(item, root);
}

template <class T>
void BinaryTree<T>::deleteNode(T item, TreeNode *&nodePtr) {
	if(item < nodePtr->value)
		deleteNode(item, nodePtr->left);
	else if(item > nodePtr->value)
		deleteNode(item, nodePtr->right);
	else
		makeDeletion(nodePtr);
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr) {
	// Define a temporary pointer to use in reattaching the left subtree
	TreeNode *tempNodePtr = nullptr;
	
	if(nodePtr == nullptr)
		cout << "Cannot delete empty node.\n";
	else if (nodePtr->right == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left; // Reattach the left child
		delete tempNodePtr;
	}
	else if (nodePtr->left == nullptr) {
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right; // Reattach the right child
		delete tempNodePtr;
	}
	// If the node has two children.
	else
	{
		// Move one node to the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree 
		tempNodePtr->right = nodePtr->right;
		delete tempNodePtr;
	}
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const {
	if(nodePtr) {
		displayInOrder(nodePtr->left);
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const {
	if(nodePtr) {
		cout << nodePtr->value << endl;
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const {
	if(nodePtr) {
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}
