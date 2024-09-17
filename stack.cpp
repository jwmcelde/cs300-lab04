#include "stack.h"
#include <iostream>
// Here we include all of the Definitions for all of the member functions of
// Stack. The prototype is included in stack.h

// Syntax explanation: we are defining the constructor of the Node struct which
// is a part of the Stack class
// Stack(class)::Node(struct)::Node(Constructor)(int cVal, Node *cNode)
Stack::Node::Node(int cVal, Node *cNode) {
  val = cVal;
  nextNode = cNode;
}

Stack::Stack() {
  // ALWAYS INITIALIZE POINTERS WITH SOME VALUE!!!
  topOfStack = nullptr;
}

// Stack::Node = (return type)
Stack::Node *Stack::getTopOfStack() { return topOfStack; }

void Stack::setTopOfStack(Node *n) { topOfStack = n; }

// Creates a new Node and puts it on the top of the stack
void Stack::push(int i) {
  Node *newNode = new Node(i, topOfStack);
  setTopOfStack(newNode);
}

int Stack::pop() {
  // check if the stack is empty
  if (topOfStack != nullptr) {
    // Catch the info from the top Node before deleting it
    int val = topOfStack->val;
    Node *ptrNewTop = topOfStack->nextNode;

    // Delete the old top Node, and set the next Node as the new top
    delete topOfStack;
    setTopOfStack(ptrNewTop);
    return val;
  }
  std::cout << "Error: Tried popping an empty stack\n";
  return 0; // Is this the best way to handle errors?
}

// return the value at the top of the stack
int Stack::peak() {
  if (topOfStack != nullptr) {
    return topOfStack->val;
  }
  std::cout << "Error: tried peaking an empty stack\n";
  return 0;
}

// Frees all data we allocated on the heap
// This is super important since we are allocating memory on the heap
void Stack::removeAll() {
  // This is a Super cheesy solution, Can you think of a better one?
  while (getTopOfStack() != nullptr) {
    int temp = pop();
  }
}

// Since we already have a function that cleans up memory, we can just call it
// for the deconstructor
Stack::~Stack() { removeAll(); }
