#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include <iostream>
#include <cmath>

class ComplexNumber {
  public: 
    ComplexNumber(){}
    ComplexNumber(double r, double i) : r_{r}, i_{i} {}
    
    ComplexNumber(const ComplexNumber& cn) : r_{cn.real()}, i_{cn.imag()} {}
    ComplexNumber& operator=(const ComplexNumber& cn){
      r_ = cn.real();
      i_ = cn.imag();

      return *this;
    }
    
    ComplexNumber(ComplexNumber&& cn) : r_{cn.real()}, i_{cn.imag()} {}
    ComplexNumber& operator=(const ComplexNumber&& cn) {
      r_ = cn.real();
      i_ = cn.imag();

      return *this;
    }
  
    ComplexNumber& operator*(double constant){ r_ *= constant; i_ *= constant; }
    ComplexNumber& operator*(const ComplexNumber& cn) { r_ *= cn.real(); i_ *= cn.imag();  } 
    const double real() const { return r_; }
    const double imag() const { return i_; }
    const double magnitude() const { return std::sqrt(r_*r_+i_*i_); }
  private:
    double r_;
    double i_;
};

std::ostream& operator<<(std::ostream&, const ComplexNumber&);


#endif
