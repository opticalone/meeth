#include "vec2.h"
#include <cmath>
#include <climits>
#include <cfloat>


vec2 operator+(const vec2 &lhs, const vec2 & rhs)
{
	
	return{ lhs.x + lhs.x,lhs.y + lhs.y };
}

vec2 operator-(const vec2 &lhs, const vec2 & rhs)
{
	return{ lhs.x - lhs.x,lhs.y - lhs.y };
}

vec2 operator*(const vec2 &lhs, const vec2 & rhs)
{

	lhs.x * rhs.x;
	lhs.y * rhs.y;
	return lhs;
}

vec2 operator/(const vec2 &lhs, int rhs)
{
	vec2 value;
	value.x = lhs.x / rhs;
	value.y = lhs.y / rhs;
	return value;
}




vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x += rhs.x;
	lhs.y += rhs.y;
	return lhs;
}

vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x -= rhs.x;
	lhs.y -= rhs.y;
	return lhs;
}

vec2 & operator*=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x *= rhs.x;
	lhs.y *= rhs.y;
	return lhs;
}

vec2 & operator/=(vec2 & lhs, const vec2 & rhs)
{
	lhs.x /= rhs.x;
	lhs.y /= rhs.y;
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

bool operator!=(const vec2 & lhs, const vec2 & rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return false;
	}
}



float vec2::operator[](int index) const
{
	return v[index];
	
}

float & vec2::operator[](int index)
{
	return v[index];
}

float magnitood(vec2 a, vec2 b)
{
	float numa = (abs(a.x - b.x));
	float numb = (abs(a.y - b.y));
	numa *= numa;
	numb *= numb;
	float numc = numa + numb;
	numc = sqrt(numc);
	return numc;
	
}

float normie(vec2 &a, vec2 &b,vec2 &c)
{
	c = c / magnitood(a, b);
}