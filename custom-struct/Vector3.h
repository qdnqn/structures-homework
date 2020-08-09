#ifndef VECTOR3_H
#define VECTOR3_H

#include <cmath>

class Vector3 {
  public:
    Vector3(){}
    Vector3(int x, int y, int z) : x_{x}, y_{y}, z_{z} {}
   
    Vector3 operator+(const Vector3& vec2) const {
      int x = x_ + vec2.x();
      int y = y_ + vec2.y();
      int z = z_ + vec2.z();

      return Vector3(x, y, z);
    };

    Vector3 operator*(const Vector3& vec2) const {
      int x = x_ * vec2.x();
      int y = y_ * vec2.y();
      int z = z_ * vec2.z();

      return Vector3(x, y, z);
    };

    int x() const { return x_; }
    int y() const { return y_; }
    int z() const { return z_; }
    
    double magnitude() const { return sqrt(x_*x_+y_*y_+z_*z_); } 
    double dotProduct(const Vector3& vec2) const;
    double angle(const Vector3& vec2) const;  
  private:
    int x_;
    int y_;
    int z_;
};

#endif
