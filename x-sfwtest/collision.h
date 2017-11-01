#pragma once
#include"meethutils.h"
#include <cmath>
#include "shapes.h"

struct Collision
{
	float pDepth;
	float hand;
	vec2 axis;
		
};
Collision intersect_1D(float Amin, float Amax, float bMin, float bMax);
Collision intersect_AABB(const AABB & A, const AABB & B);
Collision intersect_circle(const circle &A, const circle &B);
Collision intersect_AABB_Circle(const AABB&A, const circle &B);

