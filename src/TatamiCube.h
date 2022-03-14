#include "TatamiTriangle.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
using namespace std;
class TatamiCube
{
private:
    vector<TatamiTriangle> tris;
public:
    TatamiCube();
    void rotate(Vector3 v_norm);
    void render_vbo(Matrix &matProjection);
    TatamiCube &operator=(const TatamiCube &other);
    void draw();
};