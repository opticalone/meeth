#include "vec2.h"
#include "meethutils.h"
#include <climits>
#include <cmath>
#include <cfloat>


//vec2 operator+(const vec2 &lhs, const vec2 & rhs)
//{
//	
//	return{ lhs.x + lhs.x,lhs.y + lhs.y };
//}
//
//vec2 operator-(const vec2 &lhs, const vec2 & rhs)
//{
//	return{ lhs.x - lhs.x,lhs.y - lhs.y };
//}
//
//vec2 operator*(const vec2 &lhs, const vec2 & rhs)
//{
//
//	lhs.x * rhs.x;
//	lhs.y * rhs.y;
//	return lhs;
//}
//
//vec2 operator/(const vec2 &lhs, int rhs)
//{
//	vec2 value;
//	value.x = lhs.x / rhs;
//	value.y = lhs.y / rhs;
//	return value;
//}
//
//
//
//
//vec2 & operator+=(vec2 & lhs, const vec2 & rhs)
//{
//	lhs.x += rhs.x;
//	lhs.y += rhs.y;
//	return lhs;
//}
//
//vec2 & operator-=(vec2 & lhs, const vec2 & rhs)
//{
//	lhs.x -= rhs.x;
//	lhs.y -= rhs.y;
//	return lhs;
//}
//
//vec2 & operator*=(vec2 & lhs, const vec2 & rhs)
//{
//	lhs.x *= rhs.x;
//	lhs.y *= rhs.y;
//	return lhs;
//}
//
//vec2 & operator/=(vec2 & lhs, const vec2 & rhs)
//{
//	lhs.x /= rhs.x;
//	lhs.y /= rhs.y;
//	return lhs;
//}
//
//
//
//
//bool operator==(const vec2 & lhs, const vec2 & rhs)
//{
//	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
//		abs(lhs.y - rhs.y) < FLT_EPSILON)
//	{
//		return true;
//	}
//}
//
//bool operator!=(const vec2 & lhs, const vec2 & rhs)
//{
//	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
//		abs(lhs.y - rhs.y) < FLT_EPSILON)
//	{
//		return false;
//	}
//}
//
//
//
//float vec2::operator[](int index) const
//{
//	return v[index];
//	
//}
//
//float & vec2::operator[](int index)
//{
//	return v[index];
//}
//
//float magnitood(vec2 a, vec2 b)
//{
//	float numa = (abs(a.x - b.x));
//	float numb = (abs(a.y - b.y));
//	numa *= numa;
//	numb *= numb;
//	float numc = numa + numb;
//	numc = sqrt(numc);
//	return numc;
//	
//}
//
//float normie(vec2 &a, vec2 &b,vec2 &c)
//{
//	c = c / magnitood(a, b);
//}


float vec2::operator[](unsigned idx)
{
	return v[idx];
}
float vec2::operator[](unsigned idx) const
{
	return v[idx];
}

vec2 operator+(const vec2 &lhs, const vec2 &rhs)
{
	vec2 result;
	result.x = lhs.x + rhs.x;
	result.y = lhs.y + rhs.y;

	return result;
}
vec2 operator-(const vec2 &lhs, const vec2 &rhs)
{
	vec2 result;
	result.x = lhs.x - rhs.x;
	result.y = lhs.y - rhs.y;

	return result;
}
vec2 operator*(const vec2 &lhs, float rhs)
{
	vec2 result;
	result.x = lhs.x * rhs;
	result.y = lhs.y * rhs;

	return result;
}
vec2 operator*(float lhs, const vec2 &rhs)
{
	return rhs * lhs;
}
vec2 operator/(const vec2 &lhs, float rhs)
{
	vec2 result;
	result.x = lhs.x / rhs;
	result.y = lhs.y / rhs;

	return result;
}
vec2 operator-(const vec2 &lhs)
{
	vec2 result;
	result.x = lhs.x * -1;
	result.y = lhs.y * -1;

	return result;
}

vec2 &operator+=(vec2 &lhs, const vec2 &rhs)
{
	lhs = lhs + rhs;

	return lhs;
}
vec2 &operator-=(vec2 &lhs, const vec2 &rhs)
{
	lhs = lhs - rhs;

	return lhs;
}
vec2 &operator*=(vec2 &lhs, float &rhs)
{
	lhs = lhs * rhs;

	return lhs;
}
vec2 &operator/=(vec2 &lhs, float &rhs)
{
	lhs = lhs / rhs;

	return lhs;
}

bool operator==(const vec2 &lhs, const vec2 &rhs)
{
	if (abs(lhs.x - rhs.x) < FLT_EPSILON &&
		abs(lhs.y - rhs.y) < FLT_EPSILON)
	{
		return true;
	}

	return false;
}
bool operator!=(const vec2 &lhs, const vec2 &rhs)
{
	return !(lhs == rhs);
}

float mag(const vec2 &v)
{
	float aSqr = v.x * v.x;
	float bSqr = v.y * v.y;

	return sqrtf(aSqr + bSqr);
}
vec2 norm(const vec2 &v)
{
	vec2 temp = v;
	float len = mag(v);

	temp /= len;

	return temp;
}
vec2 &normalize(vec2 &v)
{
	v = norm(v);

	return v;
}
float dot(const vec2 &a, const vec2 &b)
{
	float x = a.x * b.x;
	float y = a.y * b.y;
	return x + y;
}
float dist(const vec2 &a, const vec2 &b)
{
	return mag(b - a);
}
vec2 perp(const vec2 &v)
{
	return vec2{ v.y, -v.x };
}
vec2 lerp(const vec2 &s, const vec2 &e, float a)
{
	return s + a * (e - s);
}
vec2 min(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	temp.x = fmin(a.x, b.x);
	temp.y = fmin(a.y, b.y);

	return temp;
}
vec2 max(const vec2 &a, const vec2 &b)
{
	vec2 temp;
	
	temp.x = fmax(a.x, b.x);
	temp.y = fmax(a.y, b.y);

	return temp;
}

vec2 project(const vec2 & v, const vec2 & axis)
{
	return dot(v, axis)* axis;
}

vec2 reflect(const vec2 & v, const vec2 & axis)
{
	
	return 2* project(v, axis)-v;
}


