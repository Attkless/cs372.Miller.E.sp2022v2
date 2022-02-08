// Sample code provided by Dr Lewis
#pragma once
#include <iostream>
#include "list.h"
template <typename T>

class CircularList : public List<int> {
protected:
	class Node {
	public:
		T data;
		T key;
		Node* next;
	};

	Node* start = nullptr;

	struct Node* insertEmpty(struct Node* last, int newData) {
		
		if (last != nullptr) {
			return last;
		}

		Node* temp = new Node;

		//Assignment
		temp->data = newData;
		last = temp;

		// Make the link
		last->next = last;
	}
public:


	// adjusted methods for the circular list
	struct Node* insertBegining(struct Node* last, int newData) {
//		struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
		if (last == nullptr) {
			return insertEmpty(last, newData);
		}
		else {
			struct Node* temp = new Node;
		}
		// set data to node
		temp->newData = newData;
		temp->next = last->next;
		last->next = temp;
		last = temp;

		return last;
	}

	struct Node* insertAtEnd(struct Node* last, int newData) {
	
		if (last == nullptr) {
			return insertEmpty(last, newData);
		}
		else {
			Node* temp = new Node;
		}

		// assign data
		temp->data = newData;
		temp->next = last->next;
		last->next = temp;
		last = temp;

		return last;
	}

	struct Node* insertAfter(struct Node* last, int newData, int afterItem) {
		
		if (last == nullptr) {
			return NULL;
		}
		else {
			struct Node* temp, * p;
			p = last->next;
			do {
				if (p->data == afterItem) {
					temp = new Node;
					temp->data = newData;
					temp->next = p->next;
					p->next = temp;

					if (p == last) {
						last = temp;
						return last;
					}
					p = p->next;
				}
			} while (p != last->next);

			cout << "The data (" << afterItem << ") is not present in the list." << endl;
			return last;
		}
	}

	// method circle for traversing the list
	void circle(T s) {
		Node* current = start;
		while (current != start) {
			cout << current->data << endl;
			current = current->next;
		}
	}
};