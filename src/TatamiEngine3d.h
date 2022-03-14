#include <windows.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "TatamiTriangle.h"
#include <iostream>

class TatamiEngine3d
{
private:
    float fDeltaTime;
    GLFWwindow* window;
    GLuint vao;
    GLuint vbo;
    GLuint shaderProgram;
    float fNear;
    float fFar;
    float fFov;
    float fAspectRatio;
    float fFovRad;
    Matrix matProjection=Matrix(4);
    TatamiTriangle tri;
public:
    TatamiEngine3d(int iWidth, int iHeight);
    void Start();
    virtual bool Update(float fDeltaTime);
    virtual void ProcessInput();
    virtual void Display();
    virtual void PreparationToDraw();
    ~TatamiEngine3d();
};