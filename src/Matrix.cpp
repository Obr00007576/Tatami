#include "Matrix.h"
/*
Show the vector in the command line.
*/
void Vector::show() const
{
    printf("\nVector:");
    for(int i=0;i<d;i++)
    {
        printf("\n%lf",this->vec[i]);
    }
}
Vector::Vector(int d)
{
    double *a=new double[d];
    this->d=d;
    for(int i=0;i<d;i++)
    {
        a[i]=0;
    }
    this->vec=a;
}
Vector::Vector(const double* other, int d)
{
    this->d=d;
    double *a=new double[d];
    for(int i=0;i<d;i++)
    {
        a[i]=other[i];
    }
    this->vec=a;
}
Vector::Vector(const Vector &other)
{
    this->d=other.d;
    double *a=new double[d];
    for(int i=0;i<d;i++)
    {
        a[i]=other.vec[i];
    }
    this->vec=a;
}
Vector::~Vector()
{
    delete[]this->vec;
}
/*
input: another Vector variable.
output: boolean result of comparison of these 2 vectors.
*/
Vector &Vector::operator=(const Vector& other)
{
    int n= this->d>=other.d? other.d:this->d;
    for(int i=0;i<n;i++)
    {
        this->vec[i]=other.vec[i];
    }
    return *this;
}
/*
input: another vector Vector.
output: value of addition and subtraction operation result Vector.
*/
Vector Vector::operator+(const Vector& other) const
{
    if(this->d!=other.d)
    {
        throw("Dimension not matched!\n");
    }
    Vector a=Vector(d);
    for(int i=0;i<d;i++)
    {
        a.vec[i]=this->vec[i]+other.vec[i];
    }
    return a;
}
Vector Vector::operator-(const Vector& other) const
{
    if(this->d!=other.d)
    {
        throw("Dimension not matched!\n");
    }
    Vector a=Vector(d);
    for(int i=0;i<d;i++)
    {
        a.vec[i]=this->vec[i]-other.vec[i];
    }
    return a;
}
/*
input: another vector Vector.
output: value of cartesian inner product operation result double.
*/
double Vector::operator*(const Vector& other) const
{
    if(this->d!=other.d)
    {
        throw("Dimension not matched!\n");
    }
    double a=0;
    for(int i=0;i<d;i++)
    {
        a+=this->vec[i]*other.vec[i];
    }
    return a;
}
/*
input: scaling value const couble scaler.
output: vector of scaling operation result Vector.
*/
Vector Vector::operator*(const double scaler) const
{
    Vector a=Vector(d);
    for(int i=0;i<d;i++)
    {
        a.vec[i]=scaler*this->vec[i];
    }
    return a;
}
double &Vector::operator[](int index)
{
    if(index>=d)
    {
        throw("Index is out of range!\n");
    }
    return this->vec[index];
}
/*
output: the modulo of the vector.
*/
double Vector::length() const
{
    double sum=0;
    for(int i=0;i<d;i++)
    {
        sum+=vec[i]*vec[i];
    }
    return pow(sum,0.5);
}
double* Vector::get_vec() const
{
    return vec;
}

Matrix::Matrix(double **a, int d)
{
    this->d=d;
    double **product=new double*[d];
    for(int i=0;i<d;i++)
    {
        product[i]=new double[d];
    }
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            product[i][j]=a[i][j];
        }
    }
    this->mat=product;
}
Matrix::Matrix(double *a, int d)
{
    this->d=d;
    double **product=new double*[d];
    for(int i=0;i<d;i++)
    {
        product[i]=new double[d];
    }
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            product[i][j]=a[i*d+j];
        }
    }
    this->mat=product;
}
Matrix::Matrix(int d)
{
    this->d=d;
    double **product=new double*[d];
    for(int i=0;i<d;i++)
    {
        product[i]=new double[d];
    }
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            product[i][j]=0;
        }
    }
    this->mat=product;
}
Matrix::Matrix(const Matrix &other)
{
    this->d=other.d;
    double **product=new double*[d];
    for(int i=0;i<d;i++)
    {
        product[i]=new double[d];
    }
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            product[i][j]=other.mat[i][j];
        }
    }
    this->mat=product;
}
Matrix::~Matrix()
{
    for(int i=0;i<d;i++)
    {
        delete[] this->mat[i];
    }
    delete this->mat;
}
/*
input: scaling value double.
output: value of scaling operation with matrix result Matrix.
*/
Matrix Matrix::operator*(const double scaler) const
{
    Matrix product=Matrix(d);
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            product.mat[i][j]=scaler*this->mat[i][j];
        }
    }
    return product;
}
/*
input: another matrix Matrix.
output: value of matrix multiplication with matrix result Matrix.
*/
Matrix Matrix::operator*(const Matrix &other) const
{
    if(this->d!=other.d)
    {
        throw("Dimension not matched!\n");
    }
    Matrix product=Matrix(d);
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            double temp_sum=0;
            for(int n=0;n<d;n++)
            {
                temp_sum+=this->mat[n][j]*other.mat[i][n];
            }
            product.mat[i][j]=temp_sum;
        }
    }
    return product;
}
/*
input: another vector Vector.
output: value of matrix multiplication with vector result Vector.
*/
Vector Matrix::operator*(const Vector &vec) const
{
    if(this->d!=vec.d)
    {
        throw("Dimension not matched!\n");
    }
    Vector product=Vector(d);
    for(int i=0;i<d;i++)
    {
        double temp_sum=0;
        for(int n=0;n<d;n++)
        {
            temp_sum+=this->mat[n][i]*vec.vec[n];
        }
        product.vec[i]=temp_sum;
    }
    return product;
}
/*
input: another matrix Matrix.
output: value of addition and subtraction operation result Matrix.
*/
Matrix Matrix::operator+(const Matrix &other) const
{
    if(this->d!=other.d)
    {
        throw("Dimension not matched!\n");
    }
    Matrix sum=Matrix(d);
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            sum.mat[i][j]=this->mat[i][j]+other.mat[i][j];
        }
    }
    return sum;
}
Matrix Matrix::operator-(const Matrix &other) const
{
    if(this->d!=other.d)
    {
        throw("Dimension not matched!\n");
    }
    Matrix sum=Matrix(d);
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            sum.mat[i][j]=this->mat[i][j]-other.mat[i][j];
        }
    }
    return sum;
}
/*
input: identity matrix's scaler num.
output: value of addition and subtraction operation with an identity matrix by scaler result Matrix.
*/
Matrix Matrix::operator+(const double num) const
{
    Matrix sum=Matrix(*this);
    for(int i=0;i<d;i++)
    {
        sum.mat[i][i]=sum.mat[i][i]+num;
    }
    return sum;
}
Matrix Matrix::operator-(const double num) const
{
    Matrix sum=Matrix(*this);
    for(int i=0;i<d;i++)
    {
        sum.mat[i][i]=this->mat[i][i]-num;
    }
    return sum;
}
double* Matrix::operator[](int index)
{
    if(index>=d)
    {
        throw("Index out of range!\n");
    }
    return mat[index];
}
/*
Show the matrix in the command line.
*/
void Matrix::show() const
{
    printf("Matrix:\n");
    for(int i=0;i<d;i++)
    {
        for(int j=0;j<d;j++)
        {
            printf("%lf ",this->mat[j][i]);
        }
        printf("\n");
    }
}
Matrix &Matrix::operator=(const Matrix& other)
{
    int n= this->d>=other.d? other.d:this->d;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            this->mat[i][j]=other.mat[i][j];
        }
    }
    return *this;
}
double** Matrix::get_mat() const
{
    return mat;
}