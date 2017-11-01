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

void static_resolution(vec2 &pos, vec2 &vel, const Collision &hit, float elas);

void dynamic_resolution(vec2 &Apos, vec2 &Avel, vec2 &Bpos, vec2 &Bvel, const Collision &hit, float elas);
