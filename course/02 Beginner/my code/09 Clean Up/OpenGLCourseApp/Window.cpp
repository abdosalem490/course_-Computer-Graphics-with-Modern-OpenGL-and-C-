#include "Window.h"



Window::Window()
{
	width = 800;
	width = 600;
}

Window::Window(GLint windowWidth, GLint WindowHeight)
{
	width = windowWidth;
	height = WindowHeight;
}

int Window::Initialise()
{
	// initialize GLFW
	if (!glfwInit())
	{
		printf("GLFW Initialization failed!");
		glfwTerminate();
		return 1;
	}

	// setup GLFW window properties
	// OPENGL version
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	// core profile = no Bakwards Compatibility
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	// allow forward compatibility
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	mainWindow = glfwCreateWindow(width, height, "Test window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW Window creation failed");
		glfwTerminate();
		return 1;
	}

	// Get Buffer Size information
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	// Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	// Allow modern extension features
	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialization failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	glEnable(GL_DEPTH_TEST);

	// setup Viewport size
	glViewport(0, 0, bufferWidth, bufferHeight);
	return 0;
}


Window::~Window()
{
	printf("GLEW initialization failed!");
	glfwDestroyWindow(mainWindow);
	glfwTerminate();
}
