#pragma once
union vec2
{
	//acess by aarrrraaaayyyy
	float v[2];

	//acess by indiv component
	struct { float x, y; };

};

// arithmetic operators
vec2 operator+(const vec2 &lhs, const vec2 &rhs);

// compound assignment operators
vec2 &operator+=(vec2 &lhs, const vec2 &rhs);

// logical operators
bool operator==(const vec2 &lhs, const vec2 &rhs);

//multiply and 
bool operator* (const vec2 &lhs, const vec2 &rhs);