#pragma once

namespace panda_render{
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
            ������Ϊ����ʼ������ 
        */
        Matrix(const float* m);

        Matrix(const Matrix& copy);

        ~Matrix();


        static const Matrix& identity();

        static const Matrix& zero();
    protected:
     
  };
}
