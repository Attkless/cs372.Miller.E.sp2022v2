
//
// File:   bag.h
// Author: Your Glorious Instructor
// Purpose:
// Implement the Bag ADT.
//
#pragma once
#include <iostream>
#include "vector.h"

template <typename Thing>
class Bag {
public:
  Bag() {
    bagContents = new vector<Thing *>;
    bagContents[0] = nullptr;
  }
  ~Bag() {
    delete [] bagContents;
    bagContents = nullptr;
  }
  void insert(Thing aThing) {
    bagContents.push_back(&aThing);
  }
  Thing &pop() {
    Thing * ptrToAThing;
    int i = bagContents.size();
    bool thingIsNull = true;
    while (thingIsNull && (i > 0)) {
      if (bagContents[i] != nullptr) {
        ptrToAThing = bagContents[i];
        thingIsNull = false;
      }
    }
    return ptrToAThing;
  }
  int size() {
    return bagContents.capacity();
  }
  int count() {
    return bagContents.size();
  }
private:
  vector<Thing *> bagContents;
}
