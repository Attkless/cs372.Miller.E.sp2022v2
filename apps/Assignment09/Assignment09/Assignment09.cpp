// Assignment09.cpp : Defines the entry point for the application.
/*  (30 points) Write two functions that accepts a reference to a binary search tree as 
	input and returns a reference to a list with the items sorted in (a) ascending order,
	and (b) descending order. (HINT: traversal of the tree)
	
	(30 points) In Assignment 04, your wrote a program to keep track of the tasks you 
	needed to complete to finish an assignment. Use the C++ STL heap and priority queue
	classes to keep the list sorted in priority data. You may modify the data file to 
	include an integer priority as the last value. Modify the menu to allow the user to 
	adjust the priority of task. 
*/

#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
	int value;
	TreeNode* left;
	TreeNode* right;
}*root;

class BST {
private:
	TreeNode *root;
	
public:
	BST() {
		root = nullptr;
	}
	void insert(TreeNode *&, TreeNode *&);
	void inOrder(TreeNode *) const;
	void postOrder(TreeNode *) const;
};

void insert(TreeNode* tree, TreeNode* newNode) {
	if (root == NULL) {
		root = new TreeNode;
		root->value = newNode->value;
		root->left = NULL;
		root->right = NULL;
		cout << "Root node is Added " << endl;
	}

	if (tree->value == newNode->value) {
		cout << "Element already in the tree " << endl;
		return;
	}

	if (tree->value > newNode->value) {
		if (tree->left != NULL) {
			insert(tree->left, newNode);
		}
		else {
			tree->left = newNode;
			(tree->left)->left = NULL;
			(tree->left)->right = NULL;
			cout << "Node added to teh left " << endl;
			return;
		}
	}

	else {
		if (tree->right != NULL) {
			insert(tree->right, newNode);
		}
		else {
			tree->right = newNode;
			(tree->right)->left = NULL;
			(tree->right)->right = NULL;
			cout << "Node added to the right " << endl;
		}
	}
}

void inOrder(TreeNode* ptr) {
	if (ptr != NULL) {
		inOrder(ptr->left);
		cout << ptr->value << endl;
		inOrder(ptr->right);
	}
}

void postOrder(TreeNode* ptr) {
	if (ptr != NULL) {
		postOrder(ptr->left);
		postOrder(ptr->right);
		cout << ptr->value << endl;
	}
}

int main()
{
	int choice, num;
	BST tree;
	TreeNode* temp;
	while (1) {
		cout << "Operations on Binary Search Tree: " << endl;
		cout << "1. Insert Element " << endl;
		cout << "2. In Order Traversal " << endl;
		cout << "3. Descending Traversal " << endl;
		cout << "4. Change the priority of a number " << endl;
		cout << "5. Exit " << endl;

		cin >> choice; 
		switch (choice) {
		case 1: 
			temp = new TreeNode;
			cout << "Enter the number to be inserted: " << endl;
			cin >> temp->value;
			tree.insert(root, temp);
			break;
		case 2:
			cout << "Elements in ascending order: " << endl;
			tree.inOrder(root);
			cout << endl;
			break;
		case 3: 
			cout << "Elements in descending order: " << endl;
			tree.postOrder(root);
			cout << endl;
			break;
		case 4: 
			break;
		case 5: 
			exit(1);
		default: 
			cout << "Wrong Choice " << endl;
		}

}
