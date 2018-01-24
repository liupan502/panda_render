#include "Vector.h"
#include <assert.h>
#include <math.h>
#include "panda_render_const.h"

namespace panda_render
{
  Vector4::Vector4(): x(0.0), y(0.0), z(0.0), w(0.0)
  {
  }

  Vector4::Vector4(const Vector4& copy)
  {
    set(copy);
  }

  Vector4::Vector4(float x, float y, float z, float w)
  {
    set(x, y, z, w);
  }

  Vector4::~Vector4()
  {
    
  }

  void Vector4::set(float x, float y, float z, float w)
  {
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
  }

  void Vector4::set(const Vector4& v)
  {
    this->set(v.x, v.y, v.z, v.w);
  }

  const Vector4& Vector4::zero()
  {
    static Vector4 value(0.0, 0.0, 0.0, 0.0);
    return value;
  }

  const Vector4& Vector4::one()
  {
    static Vector4 value(1.0, 1.0, 1.0, 1.0);
    return value;
  }

  float Vector4::angle(const Vector4 & v1, const Vector4 & v2)
  {
      float dx = v1.y * v2.z - v1.z * v2.y;
      float dy = v1.z * v2.x - v1.x * v2.z;
      float dz = v1.x * v2.y - v1.y * v2.x;

      float val = sqrtf(dx * dx + dy * dy + dz * dz);
      float dot_val = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
      return atan2f(val + MATH_FLOAT_SMALL, dot_val);
  }

  bool Vector4::is_zero() const
  {
    return x == 0.0f && y == 0.0f && z == 0.0f && w == 0.0f;
  }

  bool Vector4::is_one() const
  {
    return x == 1.0f && y == 1.0f && z == 1.0f && w == 1.0f;
  }

  void Vector4::add(const Vector4& v1, const Vector4& v2, Vector4* dst)
  {
    assert(dst);

    dst->x = v1.x + v2.x;
    dst->y = v1.y + v2.y;
    dst->z = v1.z + v2.z;
    dst->w = v1.w + v2.w;
  }

  void Vector4::add(const Vector4& v)
  {
    Vector4::add(*this, v, this);
  }

  Vector4 Vector4::operator+(const Vector4& v) const
  {
    Vector4 result(*this);
    result.add(v);
    return result;
  }

  Vector4& Vector4::operator+=(const Vector4& v) 
  {
    this->add(v);
    return *this;
  }

  void Vector4::subtract(const Vector4& v1, const Vector4& v2, Vector4* dst)
  {
    assert(dst);
    dst->x = v1.x - v2.x;
    dst->y = v1.y - v2.y;
    dst->z = v1.z - v2.z;
    dst->w = v1.w - v2.w;
  }

  void Vector4::subtract(const Vector4& v)
  {
    Vector4::subtract(*this, v, this);
  }

  const Vector4 Vector4::operator-(const Vector4& v) const
  {
    Vector4 result(*this);
    result.subtract(v);
    return result;
  }

  const Vector4& Vector4::operator-=(const Vector4& v)
  {
    this->subtract(v);
    return *this;
  }

  void Vector4::scale(float scalar)
  {
    this->x *= scalar;
    this->y *= scalar;
    this->z *= scalar;
    this->w *= scalar;
  }

  void Vector4::negate()
  {
    scale(-1.0f);
  }

  const Vector4 Vector4::operator-()const
  {
    Vector4 result(*this);
    result.negate();
    return result;
  }

  float Vector4::length() const
  {
    return sqrt(pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f) + pow(w, 2.0f));
  }

  float Vector4::dot(const Vector4& v) const
  {
    return (x * v.x + y * v.y + z * v.z + w * v.w);
  }
  
  void Vector4::normalize(Vector4* dst) const
  {
    assert(dst);
    if (dst != this)
    {
        dst->x = this->x;
        dst->y = this->y;
        dst->z = this->z;
        dst->w = this->w;
    }

    float length = dst->length();
    if (length == 1.0f || length < MATH_TOLERLANCE)
    {
        return;
    }
    float scalar = 1.0f / length;
    dst->scale(scalar);
  }

  Vector4& Vector4::normalize()
  {
    normalize(this);
    return *this;
  }
  
}