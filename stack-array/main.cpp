#include <iostream>
#include "stack_interface.h"

using namespace std;

int main(){
  Stack<int> test;

  test.push(1);
  test.push(2);
  test.push(3);
  test.push(4);
  test.push(5);
  test.push(1);
  test.push(2);
  test.push(3);
  test.push(4);
  test.push(15);

  Stack<int> test2 = std::move(test);

  cout << test << endl;
  cout << test2 << endl;

  return 0;
}
