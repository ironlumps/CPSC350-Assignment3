#include "Genstack.h"
#include <iostream>

using namespace std;

class SyntaxChecker
{
public:
  /*
  Make 2 stacks, one that contains all of the '{', '(', and '[' characters and then another stack that keeps track of the line numbers of each of those characters
  Pop off the top element of each stack for each time the other character '}', ')', or ']' is hit

  This may be a problem beacuse the line number that will be returned is that of the start element, not where it should be
  */
  SyntaxChecker();
  ~SyntaxChecker();

  string getLine(string fileName);
  char reverse(char c);
  void check(string fileName);

private:
  GenStack<char>* charStack;
  GenStack<int>* lineStack;

};
