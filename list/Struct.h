#ifndef STRUKTURA_H_
#define STRUKTURA_H_

#include <string>

struct ToDoTask {
  int id;
  std::string title;
  std::string description;
  int priority;

  bool operator<(const ToDoTask& other){
    return  priority < other.priority;
  }

  bool operator>=(const ToDoTask& other){
    return priority >= other.priority;
  }

  bool operator==(const ToDoTask& other){
    if(other.id == id && other.title == title && other.description == description && other.priority == priority){
      return true;
    } else {
      return false;
    }
  }
};

int generateId(){
  static int counter = 0;
  return ++counter;
}



#endif
