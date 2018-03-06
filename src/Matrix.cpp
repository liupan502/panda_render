#include "Matrix.h"
#include "Vector3.h"
#include <assert.h>
#include "panda_render_const.h"
#include <math.h>
#include <string.h>

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
    void Matrix::createLookAt(const Vector3 & eyePosition, const Vector3 & targetPosition, const Vector3 & up, Matrix * dst)
    {
        assert(dst);

        Vector3 up_use(up);
        up_use.normalize();

        Vector3 z_axis;
        Vector3::subtract(eyePosition, targetPosition, &z_axis);
        z_axis.normalize();

        Vector3 x_axis;
        Vector3::cross(up_use, z_axis, &x_axis);

        Vector3 y_axis;
        Vector3::cross(z_axis, x_axis, &y_axis);

        dst->m[0] = x_axis.x;
        dst->m[1] = y_axis.x;
        dst->m[2] = z_axis.x;
        dst->m[3] = 0.0;

        dst->m[4] = x_axis.y;
        dst->m[5] = y_axis.y;
        dst->m[6] = z_axis.y;
        dst->m[7]  = 0.0;

        dst->m[8] = x_axis.z;
        dst->m[9] = y_axis.z;
        dst->m[10] = z_axis.z;
        dst->m[11] = 0.0;

        dst->m[12] = x_axis.dot(eyePosition);
        dst->m[13] = y_axis.dot(eyePosition);
        dst->m[14] = z_axis.dot(eyePosition);
        dst->m[15] = 1.0;
    }

    void createPerspective(float fov, float ratio, float near, float far, Matrix* dst)
    {
        assert(dst);
        assert(near != far);

        float fn = 1.0 / (near - far);
        float theta = MATH_DEG_TO_RAD(fov / 2.0);
        float divsor = tan(theta);
        float factor = 1.0 / divsor;
        memset(dst, 0,MATRIX_SIZE);
        dst->m[0] = (1.0f / ratio) * factor;
        dst->m[5] = factor;
        dst->m[10] = (-(far + near)) * fn;
        dst->m[11] = -1.0f;
        dst->m[14] = -2.0f * far * near * fn;
    }
}