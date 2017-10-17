#pragma once
#include "vec3.h"
union mat3
{
	float m[9];
	float mm[3][3];
	vec3 c[3];

	vec3 &operator[](size_t idx);
	const vec3 &operator[](size_t idx) const;
};


mat3 operator+(const mat3 &A, const mat3 &B);

mat3 operator-(const mat3 &A, const mat3 &B);

mat3 operator*(const mat3 &A, const mat3 &B); //combine

mat3 operator*(const mat3 &A, const mat3 &V); //apply

mat3 transpose(const mat3 &A); //flip rows and columns

float determinant(const mat3 &A); 

mat3 inverse(const mat3 &A);