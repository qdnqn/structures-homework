#include <iostream>
#include <cmath>
#include "ComplexNumber.h"

std::ostream& operator<<(std::ostream& stream, const ComplexNumber& cn){
  stream << "Realni dio: " << cn.real() << " " << "Imaginarni dio: " << cn.imag();
  stream << " ";
  stream << "Modul kompleksnog broja: " << " " << cn.magnitude();  
  return stream;
}
