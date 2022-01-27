// File:   bag.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Bag ADT.
//
#pragma once
#include <iostream>
#include "vector.h"
#include <list>

template <typename T>
class List
{
private:
    class Node
    {
    public:
        T data;
        Node* prev;
        Node* next;
    };
    Node* head = nullptr;
    Node* tail = nullptr;
    void setupList()
    {
        Node* newNode = new Node();
        newNode->next = nullptr;
        newNode->prev = nullptr;
        head = newNode;
        tail = newNode;
    }
    void deleteListContents()
    {
        Node* temp = nullptr;
        Node* current = head;
        while (current != nullptr)
        {
            temp = current->next;
            delete current;
            current = temp;
        }
    }

public:
    List() : head(nullptr), tail(nullptr) {}

    List(T newData)
    {
        setupList();
        head->data = newData;
    }
    List(List& rhs)
    { // copy constructor
        deleteListContents();
        head = rhs.head;
        tail = rhs.tail;
    }
    ~List()
    { // And a destructor
        deleteListContents();
    }
    bool empty()
    {
        return (head == nullptr);
    }
    void push_front(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        newNode->prev = nullptr;
        if (empty())
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            head->prev = newNode;
            head = newNode;
        }
    }
    void push_back(T data)
    {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        newNode->prev = tail;
        if (empty())
        {
            tail = newNode;
            head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop_back()
    {
        Node* lastNode = tail;
        if (lastNode != nullptr)
        {
            tail = tail->prev;
            tail->next = nullptr;
            delete lastNode;
        }
    }
    T front()
    {
        if (!empty())
        {
            return head->data;
        }
        else
        {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: list is empty." << std::endl;
            exit(1);
        }
    }
    T back()
    {
        if (!empty())
        {
            return tail->data;
        }
        else
        {
            // This is drastic, and should be handled using an exception handler
            std::cout << "Exception: list is empty." << std::endl;
            exit(1);
        }
    }
    void traverse(void (*doIt)(T data))
    {
        Node* current = head;
        while (current != nullptr)
        {
            doIt(current->data);
            current = current->next;
        }
    }
};
class Bag {
public:
    Bag() {
        bagContents = new List<T*>;
        bagContents[0] = nullptr;
    }
    ~Bag() {
        delete[] bagContents;
        bagContents = nullptr;
    }
    void insert(T aT) {
        bagContents.push_back(&aT);
    }
    T& pop() {
        T* ptrToAT;
        int i = bagContents.size();
        bool TIsNull = true;
        while (TIsNull && (i > 0)) {
            if (bagContents[i] != nullptr) {
                ptrToAT = bagContents[i];
                TIsNull = false;
            }
        }
        return ptrToAT;
    }
    int size() {
        return bagContents.capacity();
    }
    int count() {
        return bagContents.size();
    }
private:
    List<T*> bagContents;
};