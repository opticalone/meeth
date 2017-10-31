#pragma once
#include "mat3.h"
#include "vec2.h"
struct circle 
{
	vec2 position;
	float radius;
};

struct AABB
{
	vec2 position;
	vec2 extents;
};
circle operator*(const mat3 &M, const circle &C);

AABB operator*(const mat3 &M, const AABB &B);