#pragma once

#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <iostream>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include "CGameManager.cpp"

using namespace glm;

class CCamera
{
public:
	CCamera(GLint program);
	~CCamera();

	mat4 CameraView();

private:

	// Screen/Viewport size
	const unsigned int SCR_WIDTH = 800;
	const unsigned int SCR_HEIGHT = 800;

	// Camera Variables
	vec3 camPos		= vec3(0.0f, 0.0f, 3.0f);
	vec3 camLookDir = vec3(0.0f, 0.0f, -1.0f);
	vec3 camUpDir	= vec3(0.0f, 1.0f, 0.0f);
};

CCamera::CCamera(GLint program)
{
	// Orthographic Center Camera
	mat4 proj;

	/// Ortho Cam with origin (0,0) in the top left
	float halfScreenWidth = (float)SCR_WIDTH * 0.5f;
	float halfScreenHeight = (float)SCR_HEIGHT * 0.5f;
	proj = ortho(-halfScreenWidth, halfScreenWidth, -halfScreenHeight, halfScreenHeight, 0.1f, 100.0f);

	/// Ortho Cam with origin (0,0) in the center
	//proj - ortho(0.0f, (float)SCR_WIDTH, (float)SCR_HEIGHT, 0.0f, 0.1f, 100.0f);

	GLuint projLoc = glGetUniformLocation(program, "proj");
	glUniformMatrix4fv(projLoc, 1, GL_FALSE, value_ptr(proj));
}

CCamera::~CCamera()
{
}

mat4 CCamera::CameraView()
{
	mat4 view = lookAt(camPos, camPos + camLookDir, camUpDir);
	return(view);
}

