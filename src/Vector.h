#pragma once
namespace panda_render{
    class Vector4
    {
        public:
        float x;
        float y;
        float z;
        float w;
        Vector4();
        Vector4(float x, float y, float z, float w);
        Vector4(const Vector4& copy);
        virtual ~Vector4();
        static const Vector4& zero();
        
        static const Vector4& one();
        
        static float angle(const Vector4& v1, const Vector4& v2);
        
        // dst = v1 + v2
        static void add(const Vector4& v1, const Vector4& v2, Vector4* dst);
        
        // dst = v1 - v2
        static void subtract(const Vector4& v1, const Vector4& v2, Vector4* dst);

        bool is_zero() const;

        bool is_one() const;

        void add(const Vector4& v);

        float dot(const Vector4& v) const;

        float length() const;

        Vector4& normalize();

        void normalize(Vector4* dst) const;

        void scale(float scalar);

        void set(float x, float y, float z, float w);

        void set(const Vector4& v);

        void subtract(const Vector4& v);

        Vector4 operator+(const Vector4& v) const;

        Vector4& operator+=(const Vector4& v) ;

        const Vector4 operator-(const Vector4& v) const;

        const Vector4& operator-=(const Vector4& v) ;

        void negate();

        const Vector4 operator-()const;
        
    };
}