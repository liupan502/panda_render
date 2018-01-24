#include "Vector3.h"
#include <math.h>
#include <assert.h>
#include "panda_render_const.h"

namespace panda_render{

panda_render::Vector3::Vector3()
{
}

panda_render::Vector3::Vector3(float x, float y, float z)
{
    set(x, y, z);
}

panda_render::Vector3::Vector3(const Vector3 & copy)
{   
    set(copy);
}

panda_render::Vector3::~Vector3()
{
}

const Vector3 & Vector3::zero()
{
    // TODO: 在此处插入 return 语句
    static Vector3 zero(0.0, 0.0, 0.0);
    return zero;
}

const Vector3 & Vector3::one()
{
    // TODO: 在此处插入 return 语句
    static Vector3 one(1.0, 1.0, 1.0);
    return one;
}

float panda_render::Vector3::angle(const Vector3 & v1, const Vector3 & v2)
{
    Vector3 cross_vec;
    Vector3::cross(v1, v2, &cross_vec);
    return atan2f(cross_vec.length() + MATH_FLOAT_SMALL , v1.dot(v2));
}

void panda_render::Vector3::add(const Vector3 & v)
{
    add(*this, v, this);
}

void panda_render::Vector3::add(const Vector3 & v1, const Vector3 & v2, Vector3 * dst)
{
    assert(dst);
    dst->x = v1.x + v2.x;
    dst->y = v1.y + v2.y;
    dst->z = v1.z + v2.z;
}

void panda_render::Vector3::cross(const Vector3 & v)
{
    Vector3 tmp(*this);
    cross(tmp, v, this);
}

void panda_render::Vector3::cross(const Vector3 & v1, const Vector3 & v2, Vector3 * dst)
{
    assert(dst);
    dst->x = v1.y * v2.z - v1.z * v2.y;
    dst->y = -v1.x * v2.z + v1.z * v2.x;
    dst->z = v1.x * v2.y - v1.y * v2.x;
}

float panda_render::Vector3::dot(const Vector3 & v) const
{
    return x * v.x + y * v.y + z * v.z;
}

float panda_render::Vector3::length() const
{
    return sqrt(x * x + y * y + z * z);
}

void panda_render::Vector3::negate()
{
    scale(-1.0);
}

Vector3& Vector3::normalize()
{
    normalize(this);
    return *this;
}

void Vector3::normalize(Vector3 * dst) const
{
    assert(dst);
    dst->set(x, y, z);
    float length = dst->length();
    if (length < MATH_TOLERLANCE)
    {
        return;
    }

    dst->scale(1.0 / length);
}

void panda_render::Vector3::scale(float scalar)
{
    x *= scalar;
    y *= scalar;
    z *= scalar;
}

void panda_render::Vector3::set(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void panda_render::Vector3::set(const Vector3 & copy)
{
    x = copy.x;
    y = copy.y;
    z = copy.z;
}

void panda_render::Vector3::subtract(const Vector3 & v)
{
    subtract(*this, v, this);
}

void panda_render::Vector3::subtract(const Vector3 & v1, const Vector3 & v2, Vector3 * dst)
{
    assert(dst);
    dst->x = v1.x - v2.x;
    dst->y = v1.y - v2.y;
    dst->z = v1.z - v2.z;
}

const Vector3 panda_render::Vector3::operator+(const Vector3 & v) const
{
    Vector3 result(*this);
    result.add(v);
    return result;
}

Vector3 & Vector3::operator+=(const Vector3 & v)
{
    add(v);
    return *this;
}

const Vector3 Vector3::operator-(const Vector3 & v) const
{
    Vector3 result(*this);
    result.subtract(v);
    return result;
}

Vector3 & Vector3::operator-=(const Vector3 & v)
{
    subtract(v);
    return *this;
}

const Vector3 Vector3::operator-() const
{
    Vector3 result(*this);
    result.negate();
    return result;
}

}