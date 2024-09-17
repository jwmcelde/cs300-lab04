#ifndef stack_h
#define stack_h
// Here is the PROTOTYPE for the Stack class, the definitions live on the
// stack.cpp file

// A heap allocated Stack data structure using a linked-list implementation
// If we created this class well, the person using this class
class Stack {
private:
  /*This is a private DEFINITION for a struct meaning that
  this Node struct is only useable in the Stack class, and
  no instance of it has been created yet. We will use these
  Nodes like a linked-list to create our stack, Where every
  Node will contain a value (the data we want to store in the
  stack) and a pointer to the next node in the stack.*/
  struct Node {

    // The value that is stored at this Node
    int val;
    // The pointer to the next Node in the stack (this will point to the Node
    // ~below~ this Node)
    Node *nextNode;

    // Constructor. putting "c" before the parameters in your constructor is a
    // nice convention
    Node(int cVal, Node *cNode);
  };

  // The only member variable of ~Stack~
  // This is necessary because we need to pop, push and peak fromt he top of the
  // stack
  Node *topOfStack;

public:
  // Standard OOP stuff
  Stack();
  Node *getTopOfStack();
  void setTopOfStack(Node *n);

  // The three member functions the user cares about

  // This should create a new Node (that lives on the heap) and push it to the
  // top of the stack
  void push(int i);
  // This should return the value at the top of the stack, delete all data
  // allocated by the top node, and update topOfStack
  int pop();
  // This just needs to return the value at the top of the stack
  int peak();

  // This should free all data allocated to the heap
  void removeAll();

  // This is a DECONSTRUCTER, and it will be called when an instance of this
  // object is destroyed (Usually this happens when an instance of this object
  // goes out of scope) Deconstructors are important to use when your object
  // allocates memory on the heap, as we want to clean up after ourselves. This
  // way the Caller of this class does not have to worry about how this class
  // manages memory If this doesn't make any sense, just think about it very
  // very hard!
  ~Stack();
};

#endif
