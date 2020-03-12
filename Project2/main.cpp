#pragma once

#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <iostream>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include "ShaderLoader.h"
#include "CObject.cpp"
#include "CGameManager.cpp"

using namespace glm;

int main(int argc, char** argv)
{
	CGameManager mainGameManager(int argc, char** argv);
	mainGameManager.ManagerMain();

	return(0);
}



