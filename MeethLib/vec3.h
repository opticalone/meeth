#pragma once
#include "vec2.h"
union vec3
{

	//array
	float v[3];

	//components
	struct { float x, y, z; };

	//acess to vec3 by idex
	float &operator[](unsigned idx);
	float operator[](unsigned idx) const;

	//acess as vec2
	vec2 xy;
};

vec3 operator+(const vec3 &lhs, const vec3 &rhs);
vec3 operator-(const vec3 &lhs, const vec3 &rhs);
vec3 operator*(const vec3 &lhs, float rhs);
vec3 operator*(float lhs, const vec3 &rhs);
vec3 operator/(const vec3 &lhs, float rhs);
vec3 operator-(const vec3 &lhs);

vec3 operator+=(vec3 &lhs, const vec3 &rhs);
vec3 &operator-=(vec3 &lhs, const vec3 &rhs);
vec3 &operator*=(vec3 &lhs, float &rhs);
vec3 &operator/=(vec3 &lhs, float &rhs);


bool operator==(const vec3 &lhs, const vec3 &rhs);
bool operator!=(const vec3 &lhs, const vec3 &rhs);

float mag(const vec3 &v);
vec3 norm(const vec3 &v);
vec3 &normalize(vec3 &v);
float dot(const vec3 &a, const vec3 &b);
float dist(const vec3 &a, const vec3 &b);


vec3 min(const vec3 &a, const vec3 &b);
vec3 max(const vec3 &a, const vec3 &b);

vec3 clamp(const vec3 &a_min, const vec3 &v, const vec3 & a_max);


vec3 cross(const vec3 &a, const vec3 &b);