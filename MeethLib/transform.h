#pragma once
#include "vec2.h"
#include "mat3.h"
#include <iostream>
class Transform
{
public:
	vec2 position;
	vec2 dimension;
	float angle;
	Transform *e_parent;
	Transform();
		mat3 getLocalTransform() const;
		mat3 getGlobalTransform() const;

};

void DrawMatrix(const mat3 &t, float drawing_scale);

void DrawTexture(unsigned sprite, const mat3 &t);
