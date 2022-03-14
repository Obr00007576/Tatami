#include "Matrix3.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class TatamiTriangle
{
private:
    Vector3 tri[3];
    GLuint vbo;
public:
    TatamiTriangle(const Vector3 &a, const Vector3 &b, const Vector3 &c);
    TatamiTriangle(double a[3], double b[3], double c[3]);
    TatamiTriangle(double* a);
    TatamiTriangle();
    Vector3 &operator[](int index);
    TatamiTriangle &operator=(const TatamiTriangle &other);
    void render_vbo(Matrix &matProjection);
    void draw();
    void rotate(Vector3 v_norm);
};