#include <iostream>
#include <string>
#include "stack_interface.h"
#include "postfix.h"

using namespace std;

int main(){
  string input;
  PostfixCalc calculator;
  
  cout << "Welcome to postfix calculator!" << endl;
  cout << "Enter Q|q to exit." << endl << endl;

  do {
    cout << "Enter RPN expression: ";
    getline(cin, input);
    
    if(input == "Q" || input == "q"){
      break;
    }

    try {
      int result = calculator.evaluate(input);
      cout << "Result: " << result << endl;
      cout << "----------------------------------------------" << endl << endl;
    } catch(std::invalid_argument e){
      cout << e.what() << endl << endl;
      calculator.reset();
    }
  } while(1);

  return 0;
}
