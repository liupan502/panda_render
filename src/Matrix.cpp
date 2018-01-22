#include "Matrix.h"

namespace panda_render{
    Matrix::Matrix()
    {
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                
            }
        }
    }
    Matrix::Matrix(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
    {
    }
    Matrix::Matrix(const float * m)
    {
    }
    Matrix::Matrix(const Matrix & copy)
    {
    }
    Matrix::~Matrix()
    {
    }
    const Matrix & Matrix::identity()
    {
        // TODO: 在此处插入 return 语句
    }
    const Matrix & Matrix::zero()
    {
        // TODO: 在此处插入 return 语句
    }
}