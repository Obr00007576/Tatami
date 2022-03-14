#include "TatamiTriangle.h"
Vector3 rot(Vector3 &v_rot, Vector3 &v_norm) 
{
    if(v_norm[0]==0&&v_norm[1]==0&&v_norm[2]==0)
    {
        throw("Cannot use zero vector as rotation vector!");
    }
    if(v_rot[0]==0&&v_rot[1]==0&&v_rot[2]==0)
    {
        return Vector3(v_rot);
    }
    double k1=v_norm[0]/v_rot[0],k2=v_norm[1]/v_rot[1],k3=v_norm[2]/v_rot[2];
    if(k1==k2&&k2==k3)
    {
        return v_rot;
    }
    double theta=v_norm.length();
    Vector3 v_k=v_norm*(1./theta);
    Matrix3 mat_K=v_k.antisym();
    Matrix3 R=mat_K*mat_K*(1-cos(theta))+mat_K*sin(theta)+1;
    return R*v_rot;
}
TatamiTriangle::TatamiTriangle(const Vector3 &a, const Vector3 &b, const Vector3 &c)
{
    tri[0]=a;
    tri[1]=b;
    tri[2]=c;
}
TatamiTriangle::TatamiTriangle(double a[3], double b[3], double c[3])
{
    tri[0]=Vector3(a);
    tri[1]=Vector3(b);
    tri[2]=Vector3(c);
}
TatamiTriangle::TatamiTriangle(double* a)
{
    for(int i=0;i<3;i++)
    {
        tri[i][0]=*(a+3*i);
        tri[i][1]=*(a+3*i+1);
        tri[i][2]=*(a+3*i+2);
    }
}
TatamiTriangle::TatamiTriangle()
{
    tri[0]=Vector3();
    tri[1]=Vector3();
    tri[2]=Vector3();
}
Vector3 &TatamiTriangle::operator[](int index)
{
    if(index>=3)
    {
        throw("Index out of range!\n");
    }
    return tri[index];
}
void TatamiTriangle::render_vbo(Matrix &matProjection)
{
    Vector a=Vector(4),b=Vector(4),c=Vector(4);
    a=tri[0];b=tri[1];c=tri[2];
    a[3]=1.f;b[3]=1.f;c[3]=1.f;
    a=matProjection*a;b=matProjection*b;c=matProjection*c;
    float transformed_tri[6]={(float)a[0],(float)a[1],(float)b[0],(float)b[1],(float)c[0],(float)c[1]};
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), transformed_tri, GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
TatamiTriangle &TatamiTriangle::operator=(const TatamiTriangle &other)
{
    this->tri[0]=other.tri[0];
    this->tri[1]=other.tri[1];
    this->tri[2]=other.tri[2];
    return *this;
}
void TatamiTriangle::draw()
{
    glBindVertexBuffer(0, vbo, 0, 2*sizeof(float));
    glDrawArrays(GL_LINE_LOOP, 0, 3);
}
void TatamiTriangle::rotate(Vector3 vec_norm)
{
    this->tri[0]=rot(this->tri[0], vec_norm);
    this->tri[1]=rot(this->tri[1], vec_norm);
    this->tri[2]=rot(this->tri[2], vec_norm);
}