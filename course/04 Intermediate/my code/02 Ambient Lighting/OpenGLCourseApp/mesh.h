#pragma once

#include <GL\glew.h>

class mesh
{
public:
	mesh();

	void CreateMesh(GLfloat *vertices, unsigned int *indices, unsigned int numOfVertices, unsigned int numOfIndices);
	void RenderMesh();
	void ClearMesh();

	~mesh();

private:
	GLuint VAO, VBO, IBO;
	GLsizei indexCount;

};

