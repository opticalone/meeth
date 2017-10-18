#pragma once
#include "vec3.h"
union mat3
{
	vec3 c[3];
	float m[9];
	float mm[3][3];
	

	vec3 &operator[](size_t idx);
	const vec3 &operator[](size_t idx) const;

	static mat3 identity()
	{
		return mat3{ 1,0,0,
			0,1,0,
			0,0,1 };
	}

	static mat3 zero()
	{
		return mat3{ 0,0,0,
			0,0,0,
			0,0,0 };
	}
};

bool operator==(const mat3 &A, const mat3 &B);

mat3 operator+(const mat3 &A, const mat3 &B);

mat3 operator-(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, const mat3 &B); //combine

mat3 operator*(const mat3 &A, const mat3 &V); //apply

mat3 transpose(const mat3 &A); //flip rows and columns

float determinant(const mat3 &A); 

mat3 inverse(const mat3 &A);

/* Translation:
[1 0 X]
[0 1 Y]
[0 0 1] */
mat3 translate(const vec2 &t);

/* Scale:
[X 0 0]
[0 Y 0]
[0 0 1] */
mat3 scale(const vec2 &s);

/* Rotation:
A[0].xy is the x-axis
A[1].xy is the y-axis
[cos(a) -sin(a)  0]
[sin(a)  cos(a)  0]
[     0       0  1] */
mat3 rotate(float deg);