#include <iostream>
#include "queue_interface.h"

using namespace std;

int main(){
  Queue<int> test;

  test.push(1);
  test.push(2);
  
  cout << test << endl;
  test.pop();
  cout << test << endl;
  test.pop();
  
  test.push(5);
  cout << test << endl;

  return 0;
}
