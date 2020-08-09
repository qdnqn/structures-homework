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

  cout << test << endl;

  return 0;
}
