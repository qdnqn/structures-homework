#include <iostream>
#include "queue_interface.h"

using namespace std;

int main(){
  Queue<int> test;

  test.push(1);
  test.push(2);
  test.push(3);
  test.push(4);
  test.push(5);
  test.push(6);
  test.push(7);
  
  test.pop();
  test.pop();
  test.pop();
  
  test.push(0);
  test.push(0);
  test.push(8);
  test.push(9);
  test.push(5);
  
  cout << test << endl;

  return 0;
}
