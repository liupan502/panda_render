#pragma once

namespace panda_render
{
    class Vector3 {

        public:

            float x;

            float y;

            float z;

            // (0.0, 0.0, 0.0)
            Vector3();

            Vector3(float x, float y, float z);

            Vector3(const Vector3& copy);

            ~Vector3();

            static const Vector3& zero();

            static const Vector3& one();

            static float angle(const Vector3& v1, const Vector3& v2);

            void add(const Vector3& v);

            static void add(const Vector3& v1, const Vector3& v2, Vector3* dst);

            void cross(const Vector3& v);

            static void cross(const Vector3& v1, const Vector3& v2, Vector3* dst);

            float dot(const Vector3& v) const;

            float length() const;

            void negate();

            Vector3& normalize();

            void normalize(Vector3* dst) const;

            void scale(float scalar);

            void set(float x, float y, float z);

            void set(const Vector3& copy);

            void subtract(const Vector3& v);

            static void subtract(const Vector3& v1, const Vector3& v2, Vector3* dst);

            const Vector3 operator+(const Vector3& v) const;

            Vector3& operator+=(const Vector3& v);

            const Vector3 operator-(const Vector3& v) const;

            Vector3& operator-=(const Vector3& v);

            const Vector3 operator-() const;

            static float angle(const Vector3& v1, const Vector3& v2);


    };
}