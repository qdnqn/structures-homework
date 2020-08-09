#include <iostream>
#include "ComplexNumber.h"
#include "Vector3.h"
#include "Container.h"

using namespace std;

int main(){
  Container<Vector3> vec3{10};
  Container<ComplexNumber> vecComplex{10};

  Vector3 temp{1,2,3};
  Vector3 temp2{4,5,6};
  Vector3 temp3{7,8,9};

  vec3.push(temp);
  vec3.push(temp2);
  vec3.push(temp3);

  cout << vec3.max().magnitude() << endl;
  cout << vec3.back().magnitude() << endl;

  ComplexNumber cTemp{1, 2};
  ComplexNumber cTemp1{3, 4};
  ComplexNumber cTemp2{5, 6};

  vecComplex.push(cTemp);
  vecComplex.push(cTemp1);
  vecComplex.push(cTemp2);

  cout << vecComplex.max().magnitude() << endl;
  cout << vecComplex.back().magnitude() << endl;

  return 0;
}
