#include "mathies.h"


#define _USE_MATH_DEFINES
#include <cmath>
int walk(int x)
{
	int x = 0;
	int y = 0;
	y = x * x;
	return 0;

}

int dFunction(int x, int y)
{
	y = x * 2;
	return y;
}

int squares(int x)
{
	return x*x;
	
}


int cubes(int x)
{
	return x *x *x;

}

float degtoRad(float r, float d, float x)
{
	float r = 0.01745329252f;
	d = x*r;

}

float radtoDEg(float r, float d, float x)
{
	r = d *(3.14 / 180);
}

float basicQuat(float x)
{
	return sqrt(x) + 2 * x - 7;
}

float lerp(float start, float end, float time)
{
	return start + time * (end - start);
}

float dist(point2d a, point2d b)
{
	return sqrtf(sqrt(b.x - a.x) + sqrt(b.y - a.y));
}