#include "collision.h"

Collision intersect_1D(float Amin, float Amax, float bMin, float bMax)
{
	Collision ret;

	float lPD = bMax - Amin;
	float rpd = Amax - bMin;

	ret.pDepth = min(lPD, rpd);
	ret.hand = copysign(1, rpd - lPD);

	return ret;
}

Collision intersect_AABB(const AABB & A, const AABB & B)
{
	Collision xres = intersect_1D(A.min().x, A.max().x, B.min().x, B.max().x);
	Collision yres = intersect_1D(A.min().y, A.max().y, B.min().y, B.max().y);

	xres.axis = vec2{ 1,0 };
	yres.axis = vec2{ 0,1 };

	return xres.pDepth < yres.pDepth ? xres : yres;
}

Collision intersect_circle(const circle & A, const circle & B)
{
	Collision ret;
	ret.axis = norm(B.position - A.position);
	ret.hand = -1;

	float ap = dot(ret.axis, A.position);
	float bp = dot(ret.axis, B.position);
	
	float Amin = ap - A.radius;
	float Amax = ap + A.radius;

	float Bmin = bp - B.radius;
	float Bmax = bp + B.radius;

	ret.pDepth = intersect_1D(Amin,Amax,Bmin,Bmax).pDepth;
	return ret;
}

Collision intersect_AABB_Circle(const AABB & A, const circle & B)
{
	return Collision();
}
