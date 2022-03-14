#include "TatamiEngine3d.h"

TatamiEngine3d::TatamiEngine3d(int iWidth, int iHeight)
{
    fDeltaTime = 0.f;
    glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(iWidth, iHeight, "Tatami", NULL, NULL);
    this->window = window;
	if (window == NULL)
	{
		glfwTerminate();
		throw("Failed to create GLFW window!\n");
	}

    glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
        throw("Failed to initialize GLAD!\n");
	}

    glClearColor(1.f,1.f,1.f,1.f);

	int width,height;
	glfwGetWindowSize(window, &width, &height);
	fNear=0.1f;
	fFar=1000.f;
	fFov=90.f;
	fAspectRatio=(float)height/(float)width;
	fFovRad=1.f/tan(fFov*0.5f/180.f*3.1415926f);
	matProjection[0][0] = fAspectRatio*fFovRad;
	matProjection[1][1] = fFovRad;
	matProjection[2][2] = fFar/(fFar - fNear);
	matProjection[2][3] = 1.f;
	matProjection[3][2] = (-fFar * fNear)/(fFar - fNear);
	matProjection.show();
}
void TatamiEngine3d::Start()
{
	PreparationToDraw();
    while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
        Update(this->fDeltaTime);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
bool TatamiEngine3d::Update(float fDeltaTime)
{
	tri.rotate(Vector3(0,1,0)*(1.f/180.f)*3.1415926);
	tri.render_vbo(matProjection);
    Display();
    return true;
}
void TatamiEngine3d::Display()
{
	glBindVertexArray(vao);
	tri.draw();
	glBindVertexArray(0);
}
void TatamiEngine3d::ProcessInput()
{

}
TatamiEngine3d::~TatamiEngine3d()
{

}
void TatamiEngine3d::PreparationToDraw()
{
	const char* vertexShaderSource=R"glsl(
    #version 150 core
    in vec2 position;
    void main()
    {
        gl_Position = vec4(position, 0.0, 1.0);
    }
    )glsl";
	const char* fragmentShaderSource=R"glsl(
	#version 150 core
	out vec4 outColor;
	void main()
	{
		outColor = vec4(0.0, 0.0, 0.0, 0.0);
	}
    )glsl";

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(vertexShader);
	glCompileShader(fragmentShader);
	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	glUseProgram(shaderProgram);

	double a[3]={0.f,0.f,0.5f},b[3]={0.f,0.f,0.f},c[3]={0.f,0.5f,0.f};
	tri=TatamiTriangle(a,b,c);

	glGenVertexArrays(1, &vao);  
	glBindVertexArray(vao);
	glVertexAttribFormat(glGetAttribLocation(shaderProgram, "position"), 2, GL_FLOAT, GL_FALSE, 0);
	glEnableVertexAttribArray(0);
	glBindVertexArray(0);
}