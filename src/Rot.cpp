#include "Matrix3.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include<iostream>
using namespace std;
//Vector3 rot(Vector3 v_rot,Vector3 v_norm);
/*
int main()
{
    double a[3]={0.707107,0.707107,0};
    double b[3]={0,0,M_PI/4};
    Vector3 v_rot=Vector3(a);
    Vector3 v_norm=Vector3(b);
    try
    {
        Vector3 rotated=rot(v_rot,v_norm);
        rotated.show();
        system("Pause");
    }catch(const char* msg)
    {
        cerr << msg << endl;
        system("Pause");
    }
}
*/
/*
input:original vector Vector3 v_rot, vector of rotation axis and angle Vector3 v_norm
output:rotated vector Vector3.
*/
/*
Vector3 rot(Vector3 v_rot,Vector3 v_norm) 
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
*/