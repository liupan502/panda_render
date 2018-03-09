#pragma once



namespace panda_render{

    class Vector3;
    class Vector4;

  /*
    matrix 4*4
  */
  class Matrix
  {
    public:

        float m[16];

        /*
            1  0  0  0
            0  1  0  0
            0  0  1  0
            0  0  0  1
        */
        Matrix();

        Matrix(float m11, float m12, float m13, float m14,
                float m21, float m22, float m23, float m24,
                float m31, float m32, float m33, float m34,
                float m41, float m42, float m43, float m44);
        /*
            按照列为主初始化数组 
        */
        Matrix(const float* m);

        Matrix(const Matrix& copy);

        ~Matrix();


        static const Matrix& identity();

        static const Matrix& zero();

        static void createLookAt(const Vector3& eyePosition, const Vector3& targetPosition, const Vector3& up, Matrix* dst);
    
        static void createPerspective(float fov, float ratio, float near, float far, Matrix* dst);

        static void createTranslation(float x, float y, float z, Matrix* dst);

        static void createScale(float sx, float sy, float sz, Matrix* dst);

        // angle is in degree
        static void createRotation(const Vector3& axis, float angle, Matrix* dst);

        // dst = left * right
        static void multiply(const Matrix& left, const Matrix& right, Matrix* dst);

        static void invert(const Matrix& mat, Matrix* dst);

        static void transformVector4(const Matrix& mat, const Vector4& vec, Vector4* dst);

        

        void transformPoint(Vector3* point) const;
    protected:
     
  };
}
