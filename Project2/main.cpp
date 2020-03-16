//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name   : main.cpp
// Description : Main
// Author      : Andrew Barnes
// Mail        : andrew.bar8456@mediadesign.school.nz
//
#pragma once

#include <glew.h>
#include <freeglut.h>
#include <SOIL.h>
#include <iostream>

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

#include "CCamera.h"
#include "CGameManager.h"
#include "CObject.h"
#include "ShaderLoader.h"

/// Runs the main fuc of program
/// Argument: Program pointer
/// Return Type: int
int main(int argc, char** argv)
{
	CGameManager mainGameManager(argc, argv);
	mainGameManager.ManagerMain();

	return(0);
}