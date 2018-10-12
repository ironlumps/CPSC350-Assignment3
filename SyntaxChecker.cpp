#include "SyntaxChecker.h"
#include <iostream>
#include <fstream>

using namespace std;

SyntaxChecker::SyntaxChecker() // Default constuctor
{

}

SyntaxChecker::~SyntaxChecker() // Default Destructor
{
  delete charStack;
  delete lineStack;
}

void SyntaxChecker::check(string fileName) // The method that actually checks the syntax
{
  // Initializes a stack that holds the delimiters and a stack that holds the line numbers
  charStack = new GenStack<char>();
  lineStack = new GenStack<int>();
  // Opens the file to read from it
  ifstream readFile(fileName);
  // Other variable initializations
  string line;
  int lineNumber = 1;
  char reverseDelimiter;
  // Checks to see if file exists
  if(readFile.good())
  {
    // Reads each line of file
    while(getline(readFile, line))
    {
      // Reads each character of each line
      for(int i = 0; i < line.length(); i++)
      {
        // Checks to see if character is opening delimter
        if(line[i] == '{' || line[i] == '[' || line[i] == '(')
        {
          // Reverses delimiter and adds to stack
          reverseDelimiter = reverse(line[i]);
          // Adds that character and line number to stack
          charStack->push(reverseDelimiter);
          lineStack->push(lineNumber);
        }
        // Checks to see if character is closing delimiter
        if(line[i] == '}' || line[i] == ']' || line[i] == ')')
        {
          // If the reverse character is on top of stack, pop the character and line number
          if(line[i] == charStack->peek())
           {
            charStack->pop();
            lineStack->pop();
          }
        }
        // If line starts with comment, move to next line
        if(line[i] == '/' &&  line[i+1] == '/')
        {
          continue;
        }
      }

      lineNumber++;
    }
  }
  // If file doesn't exist, then returns error message
  else
  {
    cout << "Invalid File Name" << endl;
  }

  // Prints error messgaes for everything left on the stacks
  while(!charStack->isEmpty() && !lineStack->isEmpty())
  {
    cout << "Line " << lineStack->pop() << ": Missing " << charStack->pop() << " character" << endl;
  }
}
// Method that reverses each delimiter
char SyntaxChecker::reverse(char c)
{
  if(c == '{')
  {
    return '}';
  }
  else if(c == '}')
  {
    return '{';
  }
  else if(c == '[')
  {
    return ']';
  }
  else if(c == ']')
  {
    return '[';
  }
  else if(c == '(')
  {
    return ')';
  }
  else if(c == ')')
  {
    return '(';
  }
}
