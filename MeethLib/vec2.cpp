#include "vec2.h"
#include <cmath>
#include <climits>
#include <cfloat>


vec2 operator+(const vec2 & lhs, const vec2 & rhs)
{
	
	return{ lhs.x + lhs.x,lhs.y + lhs.y };
}

vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

bool operator==(const vec2 & lhs, const vec2 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return true;
	}
}

vec2 operator*(const vec2 & lhs, const vec2 & rhs)
{

	lhs.x * rhs.x;
	lhs.y * rhs.y;
	return lhs;
}


