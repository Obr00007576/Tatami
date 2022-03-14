#include <stdio.h>
#include <windows.h>
#include <math.h>
class Matrix;
class Vector;
class Vector
{
    friend class Matrix;
    private:
        double* vec;
        int d;
    public:
        double length() const;
        virtual void show() const;
        double &operator[](int index);
        Vector &operator=(const Vector& other);
        Vector operator-(const Vector& other) const;
        Vector operator+(const Vector& other) const;
        Vector operator*(const double scaler) const;
        double operator*(const Vector& other) const;
        Vector(const double* other, int d);
        Vector(int d);
        Vector(const Vector &other);
        ~Vector();
    protected:
        double* get_vec() const;
};
class Matrix
{
    friend class Vector;
    private:
        double** mat;
        int d;
    public:
        virtual void show() const;
        Matrix operator*(const double scaler) const;
        Matrix operator*(const Matrix &other) const;
        Vector operator*(const Vector &vec) const;
        Matrix operator+(const Matrix &other) const;
        Matrix operator+(const double num) const;
        Matrix operator-(const Matrix &other) const;
        Matrix operator-(const double num) const;
        Matrix &operator=(const Matrix& other);
        double* operator[](int index);
        Matrix(double **a, int d);
        Matrix(double *a, int d);
        Matrix(int d);
        Matrix(const Matrix &other);
        ~Matrix();
    protected:
        double** get_mat() const;
};
