#pragma once
namespace panda_render
{
    class Vector2
    {
        public:
            float x;

            float y;

            Vector2(){};

            Vector2(float x, float y);

            Vector2(const Vector2& copy);

            void set(float x, float y);

            void set(const Vector2& copy);

            float dot(const Vector2& v) const;

            static float dot(const Vector2& v1, const Vector2& v2);

            void add(const Vector2& v);

            static void add(const Vector2& v1, const Vector2& v2, Vector2* dst);

            void subtract(const Vector2& v);

            static void subtract(const Vector2& v1, const Vector2& v2, Vector2* dst);

            const Vector2 operator+(const Vector2& v) const;

            Vector2& operator+=(const Vector2& v) ;

            const Vector2 operator-(const Vector2& v) const;

            Vector2& operator-=(const Vector2& v);
    };
}