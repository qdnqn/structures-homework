#include <cmath>
#include "Vector3.h"

double Vector3::dotProduct(const Vector3& vec2) const {
  return (vec2.x())*x_ + (vec2.y())*y_ + (vec2.z())*z_;
}

double Vector3::angle(const Vector3& vec2) const {
  return acos(dotProduct(vec2)/(magnitude()*vec2.magnitude()));
}


