#include "Matrix3.h"

Matrix3::Matrix3(double a[3][3]):Matrix((double*)a, 3)
{
}
Matrix3::Matrix3():Matrix(3)
{
}
Matrix3::Matrix3(const Matrix3 &other):Matrix(other)
{
}
Matrix3::~Matrix3()
{
}
/*
input: scaling value double.
output: value of scaling operation with matrix result Matrix3.
*/
Matrix3 Matrix3::operator*(const double scaler) const
{
    Matrix3 product=Matrix3();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            product.get_mat()[i][j]=scaler*this->get_mat()[i][j];
        }
    }
    return product;
}
/*
input: another matrix Matrix3.
output: value of matrix multiplication with matrix result Matrix3.
*/
Matrix3 Matrix3::operator*(const Matrix3 &other) const
{
    Matrix3 product=Matrix3();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            double temp_sum=0;
            for(int n=0;n<3;n++)
            {
                temp_sum+=this->get_mat()[n][j]*other.get_mat()[i][n];
            }
            product.get_mat()[i][j]=temp_sum;
        }
    }
    return product;
}
/*
input: another vector Vector3.
output: value of matrix multiplication with vector result Vector3.
*/
Vector3 Matrix3::operator*(const Vector3 &vec) const
{
    Vector3 product=Vector3();
    for(int i=0;i<3;i++)
    {
        double temp_sum=0;
        for(int n=0;n<3;n++)
        {
            temp_sum+=this->get_mat()[n][i]*vec.get_vec()[n];
        }
        product.get_vec()[i]=temp_sum;
    }
    return product;
}
/*
input: another matrix Matrix3.
output: value of addition and subtraction operation result Matrix3.
*/
Matrix3 Matrix3::operator+(const Matrix3 &other) const
{
    Matrix3 sum=Matrix3();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum.get_mat()[i][j]=this->get_mat()[i][j]+other.get_mat()[i][j];
        }
    }
    return sum;
}
Matrix3 Matrix3::operator-(const Matrix3 &other) const
{
    Matrix3 sum=Matrix3();
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            sum.get_mat()[i][j]=this->get_mat()[i][j]-other.get_mat()[i][j];
        }
    }
    return sum;
}
/*
input: identity matrix's scaler num.
output: value of addition and subtraction operation with an identity matrix by scaler result Matrix3.
*/
Matrix3 Matrix3::operator+(const double num) const
{
    Matrix3 sum=Matrix3(*this);
    for(int i=0;i<3;i++)
    {
        sum.get_mat()[i][i]=sum.get_mat()[i][i]+num;
    }
    return sum;
}
Matrix3 Matrix3::operator-(const double num) const
{
    Matrix3 sum=Matrix3(*this);
    for(int i=0;i<3;i++)
    {
        sum.get_mat()[i][i]=this->get_mat()[i][i]-num;
    }
    return sum;
}
Matrix3 &Matrix3::operator=(const Matrix3& other)
{
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            this->get_mat()[i][j]=other.get_mat()[i][j];
        }
    }
    return *this;
}
/*
Show the matrix in the command line.
*/
void Matrix3::show() const
{
    printf("Matrix3:\n");
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            printf("%lf ",this->get_mat()[j][i]);
        }
        printf("\n");
    }
}

/*
Show the vector in the command line.
*/
void Vector3::show() const
{
    printf("\nVector3:");
    for(int i=0;i<3;i++)
    {
        printf("\n%lf",this->get_vec()[i]);
    }
}
Vector3::Vector3(double x, double y, double z):Vector(3)
{
    get_vec()[0]=x;
    get_vec()[1]=y;
    get_vec()[2]=z;
}
Vector3::Vector3():Vector(3)
{
}
Vector3::Vector3(const double other[3]):Vector(other, 3)
{
}
Vector3::Vector3(const Vector3 &other):Vector(other)
{
}
Vector3::~Vector3()
{
}
/*
input: another Vector3 variable.
output: boolean result of comparison of these 2 vectors.
*/
Vector3 &Vector3::operator=(const Vector3& other)
{
    for(int i=0;i<3;i++)
    {
        this->get_vec()[i]=other.get_vec()[i];
    }
    return *this;
}
/*
input: another vector Vector3.
output: value of addition and subtraction operation result Vector3.
*/
Vector3 Vector3::operator+(const Vector3& other) const
{
    Vector3 a=Vector3();
    for(int i=0;i<3;i++)
    {
        a.get_vec()[i]=this->get_vec()[i]+other.get_vec()[i];
    }
    return a;
}
Vector3 Vector3::operator-(const Vector3& other) const
{
    Vector3 a=Vector3();
    for(int i=0;i<3;i++)
    {
        a.get_vec()[i]=this->get_vec()[i]-other.get_vec()[i];
    }
    return a;
}
/*
input: another vector Vector3.
output: value of cartesian inner product operation result double.
*/
double Vector3::operator*(const Vector3& other) const
{
    double a=0;
    for(int i=0;i<3;i++)
    {
        a+=this->get_vec()[i]*other.get_vec()[i];
    }
    return a;
}
/*
input: scaling value const couble scaler.
output: vector of scaling operation result Vector3.
*/
Vector3 Vector3::operator*(const double scaler) const
{
    Vector3 a=Vector3();
    for(int i=0;i<3;i++)
    {
        a.get_vec()[i]=scaler*this->get_vec()[i];
    }
    return a;
}
double &Vector3::operator[](int index)
{
    return this->get_vec()[index];
}
/*
output: the modulo of the vector.
*/
double Vector3::length() const
{
    double a=this->get_vec()[0];
    double b=this->get_vec()[1];
    double c=this->get_vec()[2];
    return pow(a*a+b*b+c*c,0.5);
}
/*
output:Anti-symmetric matrix from the vector Vector3 self.
*/
Matrix3 Vector3::antisym()
{
    Matrix3 mat=Matrix3();
    double kx=this->get_vec()[0];
    double ky=this->get_vec()[1];
    double kz=this->get_vec()[2];
    mat[0][1]=kz;
    mat[1][0]=-kz;
    mat[0][2]=-ky;
    mat[2][0]=ky;
    mat[1][2]=kx;
    mat[2][1]=-kx;
    return mat;
}
