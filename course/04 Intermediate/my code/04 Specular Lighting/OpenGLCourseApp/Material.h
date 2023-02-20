#pragma once

#include <GL\glew.h>

class Material
{
public:
	Material();

	Material(GLfloat sInensity, GLfloat shine);

	void UseMaterial(GLuint specularIntensityLocation, GLuint shininessLocation);

	~Material();

private:
	GLfloat specularIntensity;
	GLfloat shininess;
};

