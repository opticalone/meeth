#pragma once
int walk(int x);

int dFunction(int x, int y);

int squares(int x);

int cubes(int x);

float degtoRad(float r, float d, float x);
 
float radtoDEg(float r, float d, float x);

struct point2d
{
	float x;
	float y;
};

// Returns the y value for the given x value in the represented quadratic.
float basicQuat(float x);

// LERP
float lerp(float start, float end, float time);

float dist(point2d a, point2d b);