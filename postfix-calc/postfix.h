#ifndef POSTFIX_H
#define POSTFIX_H

#include <iostream>
#include <string>
#include <stdexcept>
#include "stack_interface.h"

class PostfixCalc {
  public:
    int evaluate(std::string input){
      for(int i=0; i<input.size(); ++i){
        if(isDelimiter(input.at(i))){
          continue;
        } else if(isDigit(input.at(i))){
          std::string digit = "";
          
          while(i < input.size() && isDigit(input.at(i))){
            digit += input.at(i);
            ++i;
          }
          
          table_.push(std::stoi(digit));
        } else {
          if(validOperand(input.at(i))){
            if(!table_.empty()){
              int operand2 = table_.top();
              table_.pop();
              
              if(!table_.empty()){
                int operand1 = table_.top();
                table_.pop();
                
                table_.push(operation(operand1, operand2, input.at(i)));
                continue;
              }
            }

            throw std::invalid_argument("Number of operands doesn't match numbear of operators.");
          } else {
            throw std::invalid_argument("You have passed invalid operand.");
          }
        }
      }
      
      if(table_.size() == 1){
        while(!table_.empty()){
          int result = table_.top(); 
          table_.pop();

          return result;
        }
      } else {
        throw std::invalid_argument("Number of operands doesn't match number of operators.");
      }
    }

    bool isDigit(char character){
      return character >= '0' && character <= '9';
    }

    bool validOperand(char character){
      if(character == '+' || character == '-' || character == '/' || character == '*'){
        return true;
      } else {
        return false;
      }
    }

    bool isDelimiter(char character, char delimiter = ' '){
      return character == delimiter;
    }

    int operation(int a, int b, char op){
      if(op == '+'){
        return a+b;
      } else if (op == '-'){
        return a-b;
      } else if (op == '*'){
        return a*b;
      } else {
        if(b == 0){
          throw std::invalid_argument("Division by zero.");
        }

        return a/b;
      }
    }

    void reset(){
      while(!table_.empty()){
        table_.pop();
      }
    }
  private:
    Stack<int> table_;
};

#endif
