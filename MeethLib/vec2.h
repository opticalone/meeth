#pragma once
union vec2
{
	//acess by aarrrraaaayyyy
	float v[2];

	//acess by indiv component
	struct { float x, y; };

	float operator[](int index) const;
	float &operator[](int index);
};

// arithmetic operators
vec2 operator+(const vec2 &lhs, const vec2 &rhs);
vec2 operator-(const vec2 &lhs, const vec2 &rhs);
vec2 operator*(const vec2 &lhs, const vec2 &rhs);
vec2 operator/(const vec2 &lhs, const vec2 &rhs);

// compound assignment operators
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);
vec2 &operator-=(vec2 &lhs, const vec2 &rhs);
vec2 &operator*=(vec2 &lhs, const vec2 &rhs);
vec2 &operator/=(vec2 &lhs, const vec2 &rhs);

// logical operators
bool operator==(const vec2 &lhs, const vec2 &rhs);
bool operator!=(const vec2 &lhs, const vec2 &rhs);

//multiply and 
vec2 operator* (const vec2 &lhs, const vec2 &rhs);

//divide 
vec2 operator/ (const vec2 &lhs, const vec2 &rhs);

//magnanimous tood part
//Magnitude
float magnitood(vec2 a);

float normie(vec2 a);



