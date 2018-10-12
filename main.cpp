#include "SyntaxChecker.h"

int main(int argc, char** argv)
{
  // Checks to see if something other than program command is entered
  if(argc > 1)
  {
    // File Name is second argument
    string fileName = argv[1];

    // Class object initialization
    SyntaxChecker check;
    // Actually running SyntaxChecker
    check.check(fileName);
  }
  // If nothing else is entered, throw error message
  else
  {
    cout << "No File Entered" << endl;
  }
}
