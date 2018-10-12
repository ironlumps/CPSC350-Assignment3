#include <iostream>

using namespace std;

template<class stack>
class GenStack
{
  public:
    GenStack<stack>();
    ~GenStack<stack>();
    GenStack<stack>(stack maxSize);

    stack push(stack d);
    stack pop();
    stack peek();

    stack isFull();
    stack isEmpty();

    int size;
    int top;

    char* myArray;
    char* copyArray;
};

template<class stack>
GenStack<stack>::GenStack() // Default constructor
{
  // initialize variables to default value
  myArray = new char[100];
  size = 100;
  top = -1;
}

template<class stack>
GenStack<stack>::GenStack(stack maxSize) // Overload constructor
{
  myArray = new char[maxSize];
  size = maxSize;
  top = -1;
}
template<class stack>
GenStack<stack>::~GenStack() // Destructor
{
  delete myArray;
  delete copyArray;
}
template<class stack>
stack GenStack<stack>::push(stack d)
{
  // Check if not full
  if(isFull() == true)
  {
    // If the stack is full, copies the old array over to new array with twice the size
    size = size * 2;
    copyArray = new char[size];
    for(int i = 0; i < (sizeof(myArray)/sizeof(myArray[0])); i++)
    {
      copyArray[i] = myArray[i];
    }
    myArray = new char[size];
    for(int i = 0; i < (sizeof(copyArray)/sizeof(copyArray[0])); i++)
    {
      myArray[i] = copyArray[i];
    }

    push(d);
  }
  if(isFull() == false)
  {
    // If not ful adds item to stack
      myArray[++top] = d;
  }
}

template<class stack>
stack GenStack<stack>::pop()
{
  // Check if empty
  if(isEmpty() == false)
  {
    return myArray[top--];
  }
  else
  {
    // If stack is empty return error message
    cout << "Invalid Operation: Stack is Empty and Cannot Return any Elements" << endl;
  }
}

template<class stack>
stack GenStack<stack>::peek() // Shows the top item in the stack
{
  // Check if stack is empty
  if(isEmpty() == false)
  {
      return myArray[top];
  }
  else
  {
    // If stack is empty, return error message
    cout << "Invalid Operation: Stack is Empty" << endl;
  }
}

template<class stack>
stack GenStack<stack>::isFull() // Checks if the stack is full
{
  return(top == size - 1);
}

template<class stack>
stack GenStack<stack>::isEmpty() // Checks if the stack if empty
{
  return(top == -1);
}
