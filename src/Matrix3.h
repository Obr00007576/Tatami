#include <stdio.h>
#include <windows.h>
#include <math.h>
#include "Matrix.h"

class Matrix3;
class Vector3;
class Vector3:public Vector
{
    friend class Matrix3;
    public:
        double length() const;
        void show() const override;
        Matrix3 antisym();
        double &operator[](int index);
        Vector3 &operator=(const Vector3& other);
        Vector3 operator-(const Vector3& other) const;
        Vector3 operator+(const Vector3& other) const;
        Vector3 operator*(const double scaler) const;
        double operator*(const Vector3& other) const;
        Vector3(const double other[3]);
        Vector3(double x, double y, double z);
        Vector3();
        Vector3(const Vector3 &other);
        ~Vector3();
};

class Matrix3: public Matrix
{
    friend class Vector3;
    public:
        Matrix3 operator*(const double scaler) const;
        Matrix3 operator*(const Matrix3 &other) const;
        Vector3 operator*(const Vector3 &vec) const;
        Matrix3 operator+(const Matrix3 &other) const;
        Matrix3 operator+(const double num) const;
        Matrix3 operator-(const Matrix3 &other) const;
        Matrix3 operator-(const double num) const;
        Matrix3 &operator=(const Matrix3& other);
        void show() const override;
        Matrix3(double a[3][3]);
        Matrix3();
        Matrix3(const Matrix3 &other);
        ~Matrix3();
};
