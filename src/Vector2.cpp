#include "Vector2.h"
#include <math.h>
#include "panda_render_const.h"
#include <assert.h>

panda_render::Vector2::Vector2(float x, float y)
{
    set(x, y);
}

panda_render::Vector2::Vector2(const Vector2 & copy)
{
    set(copy);
}

void panda_render::Vector2::set(float x, float y)
{
    this->x = x;
    this->y = y;
}

void panda_render::Vector2::set(const Vector2 & copy)
{   
    x = copy.x;
    y = copy.y;
}

float panda_render::Vector2::dot(const Vector2 & v) const
{
    return x * v.x + y * v.y;
}

float panda_render::Vector2::dot(const Vector2 & v1, const Vector2 & v2)
{
    return v1.x * v2.x + v1.y * v2.y;
}

void panda_render::Vector2::add(const Vector2 & v)
{
    x += v.x;
    y += v.y;
}

void panda_render::Vector2::add(const Vector2 & v1, const Vector2 & v2, Vector2* dst)
{
   assert(dst);
   dst->x = v1.x + v2.x;
   dst->y = v1.y + v2.y;

}

void panda_render::Vector2::subtract(const Vector2 & v)
{
    x -= v.x;
    y -= v.y;
}

void panda_render::Vector2::subtract(const Vector2 & v1, const Vector2 & v2, Vector2 * dst)
{
    assert(dst);

    dst->x = v1.x - v2.x;
    dst->y = v1.y - v2.y;
}

const panda_render::Vector2 panda_render::Vector2::operator+(const Vector2 & v) const
{
    Vector2 result(*this);
    result.add(v);
    return result;
}

panda_render::Vector2 & panda_render::Vector2::operator+=(const Vector2 & v) 
{
     
    // TODO: 在此处插入 return 语句
    this->add(v);
    return *this;
}

const panda_render::Vector2 panda_render::Vector2::operator-(const Vector2 & v) const
{
    Vector2 result(*this);
    result.subtract(v);
    return result;
}

panda_render::Vector2 & panda_render::Vector2::operator-=(const Vector2 & v)
{
    // TODO: 在此处插入 return 语句
    this->subtract(v);
    return *this;
}

namespace panda_render
{
    float Vector2::angle(const Vector2& v1, const Vector2& v2)
    {
        float dz = v1.x * v2.y - v1.y * v2.x;
        return atan2f(fabsf(dz) + MATH_FLOAT_SMALL, dot(v1, v2));
    }

    float Vector2::length() const
    {
        return sqrtf(x * x + y * y);
    }

    void Vector2::scale(float scalar)
    {
        x *= scalar;
        y *= scalar;
    }

    void Vector2::normalize(Vector2* dst) const
    {
        assert(dst);
        if (this != dst)
        {
            dst->x = x;
            dst->y = y;
        }

        float length = dst->length();
        if (length == 1.0)
        {
            return;
        }

        if (length < MATH_TOLERLANCE)
        {
            return;
        }

        dst->scale(1.0 / length);
    }
}
