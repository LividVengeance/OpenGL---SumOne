//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2020 Media Design School
//
// File Name   : CObject.cpp
// Description : Object class
// Author      : Andrew Barnes
// Mail        : andrew.bar8456@mediadesign.school.nz
//
#pragma once

#include "CObject.h"

/// Constructor for CObject
/// Argument: Nothing
/// Return Type: Void
CObject::CObject()
{
	GLfloat vertices[]{
		// Position				// Color			// Texture Coords
		 0.33f,  1.0f,  0.0f,	1.0f, 1.0f, 1.0f,	0.33f,  1.0f,	// Top left
		 0.66f,  1.0f,  0.0f,	1.0f, 1.0f, 1.0f,	0.66f,  1.0f,	// Mid left
		 1.0f,   0.5f,  0.0f,	1.0f, 1.0f, 1.0f,	1.0f,   0.5f,	// Bot left
		 0.66f,  0.0f,  0.0f,	1.0f, 1.0f, 1.0f,	0.66f,  0.0f,	// Top Right
		 0.33f,  0.0f,  0.0f,	1.0f, 1.0f, 1.0f,	0.33f,  0.0f,	// Mid Right
		 0.0f,   0.5f,  0.0f,	1.0f, 1.0f, 1.0f,	0.0f,   0.5f,	// Bot Right
	};
	GLuint indices[] = {
		4, 1, 0,	// First Triangle
		4, 3, 1,	// Second Triangle
		3, 2, 1,	// Third Triangle
		5, 4, 0, 	// Fourth Triangle
	};
}

/// Deconstructor for CObject
/// Argument: Nothing
/// Return Type: Void
CObject::~CObject()
{
}

/// Creates a translation maxtrix from given obj position
/// Argument: Oject Position
/// Return Type: mat4
mat4 CObject::Translation(vec3 objPosition)
{
	/// Creates Translation Matrax of Objects Postion
	mat4 translationMatrix = translate(mat4(), objPosition);
	return(translationMatrix);
}

/// Creates a rotaion maxtrix from given axis and angle
/// Argument: Axis of rotaion, angle of rotaion
/// Return Type: mat4
mat4 CObject::Rotation(vec3 rotationAxis, float angle)
{
	/// Creates Rotation Matrix Given Angle and Rotation Axis
	mat4 rotationMatrix = rotate(mat4(), radians(angle), rotationAxis);
	return(rotationMatrix);
}

/// Creates a scale maxtrix from given axis and angle
/// Argument: Object scale, scale amount
/// Return Type: mat4
mat4 CObject::Scale(vec3 objScale, float scaleAmount)
{
	/// Create Scale Matrix of Object
	mat4 scaleMatrix = scale(mat4(), objScale * scaleAmount);
	return(scaleMatrix);
}

/// Creates a maxtrix given translaiton, rotaion, scaleMatrix
/// Argument: Transaltion Matrix, Rotation Matrix, Scale Matrix of object
/// Return Type: mat4
mat4 CObject::Combine(mat4 translationMatrix, mat4 rotationMatrix, mat4 scaleMatrix)
{
	// Create model matrix to combine them
	mat4 model = translationMatrix * rotationMatrix * scaleMatrix;
	return(model);
}