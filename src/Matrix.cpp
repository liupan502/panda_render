#include "Matrix.h"
#include "Vector3.h"
#include <assert.h>
#include "panda_render_const.h"
#include <math.h>
#include <string.h>
#include "Vector.h"

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

    void Matrix::createPerspective(float fov, float ratio, float near, float far, Matrix* dst)
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

    void Matrix::transformVector4(const Matrix& mat, const Vector4& vec, Vector4* dst)
    {
        assert(dst);
        const float* m = mat.m;
        dst->x = m[0] * vec.x + m[4] * vec.y + m[8] * vec.z + m[12] * vec.w;
        dst->y = m[1] * vec.x + m[5] * vec.y + m[9] * vec.z + m[13] * vec.w;
        dst->z = m[2] * vec.x + m[6] * vec.y + m[10] * vec.z + m[14] * vec.w;
        dst->w = m[3] * vec.x + m[7] * vec.y + m[11] * vec.z + m[15] * vec.w;
    }

    void Matrix::transformPoint(Vector3* point) const
    {
        assert(point);
        Vector4 src_vec, dst_vec;
        src_vec.x = point->x;
        src_vec.y = point->y;
        src_vec.z = point->z;
        Matrix::transformVector4(*this, src_vec, &dst_vec);
        point->x = dst_vec.x;
        point->y = dst_vec.y;
        point->z = dst_vec.z;
    }

    void Matrix::createTranslation(float x, float y, float z, Matrix* dst)
    {
        assert(dst);
        Matrix id = Matrix::identity();
        memcpy(dst->m,id.m, MATRIX_SIZE);
        dst->m[12] = x;
        dst->m[13] = y;
        dst->m[14] = z;
    }

    void Matrix::createScale(float sx, float sy, float sz, Matrix* dst)
    {
        assert(dst);
        Matrix id = Matrix::identity();
        memcpy(dst->m, id.m, MATRIX_SIZE);
        dst->m[0] = sx;
        dst->m[5] = sy;
        dst->m[10] = sz;
    }

    void Matrix::createRotation(const Vector3& axis, float angle, Matrix* dst)
    {
    }

    void Matrix::invert(const Matrix& mat, Matrix* dst)
    {
    }

    void Matrix::multiply(const Matrix& left, const Matrix& right, Matrix* dst)
    {
        assert(dst);
        const float * m1 = left.m;
        const float * m2 = right.m;
        dst->m[0] = m1[0] * m2[0] + m1[4] * m2[1] + m1[8] * m2[3] + m1[12] * m2[4];
        dst->m[4] = m1[0] * m2[4] + m1[4] * m2[5] + m1[8] * m2[6] + m1[12] * m2[7];
        dst->m[8] = m1[0] * m2[8] + m1[4] * m2[9] + m1[8] * m2[10] + m1[12] * m2[14];
        dst->m[12] = m1[0] * m2[12] + m1[4] * m2[13] + m1[8] * m2[14] + m1[12] * m2[15];

        dst->m[1] = m1[1] * m2[0] + m1[5] * m2[1] + m1[9] * m2[3] + m1[13] * m2[4];
        dst->m[5] = m1[1] * m2[4] + m1[5] * m2[5] + m1[9] * m2[6] + m1[13] * m2[7];
        dst->m[9] = m1[1] * m2[8] + m1[5] * m2[9] + m1[9] * m2[10] + m1[13] * m2[14];
        dst->m[13] = m1[1] * m2[12] + m1[5] * m2[13] + m1[9] * m2[14] + m1[13] * m2[15];

        dst->m[2] = m1[2] * m2[0] + m1[6] * m2[1] + m1[10] * m2[3] + m1[14] * m2[4];
        dst->m[6] = m1[2] * m2[4] + m1[6] * m2[5] + m1[10] * m2[6] + m1[14] * m2[7];
        dst->m[10] = m1[2] * m2[8] + m1[6] * m2[9] + m1[10] * m2[10] + m1[14] * m2[14];
        dst->m[14] = m1[2] * m2[12] + m1[6] * m2[13] + m1[10] * m2[14] + m1[14] * m2[15];

        dst->m[3] = m1[3] * m2[0] + m1[7] * m2[1] + m1[11] * m2[3] + m1[15] * m2[4];
        dst->m[7] = m1[3] * m2[4] + m1[7] * m2[5] + m1[11] * m2[6] + m1[15] * m2[7];
        dst->m[11] = m1[3] * m2[8] + m1[7] * m2[9] + m1[11] * m2[10] + m1[15] * m2[14];
        dst->m[15] = m1[3] * m2[12] + m1[7] * m2[13] + m1[11] * m2[14] + m1[15] * m2[15];
        
    } 
}