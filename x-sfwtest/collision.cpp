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

void static_resolution(vec2 & pos, vec2 & vel, const Collision & hit, float elas)
{
	pos += hit.axis * hit.hand * hit.pDepth;

	vel = -reflect(vel, hit.axis*hit.hand)* elas;
}



void dynamic_resolution(vec2 &Apos, vec2 & Avel, float Amass, 
						vec2 & Bpos, vec2 & Bvel,float Bmass, 
						const Collision & hit, float elas)
{
	// Law of Conservation
	/*
	mass*vel = momentum

	AP + BP = `AP + `BP // Conservation of Momentum
	Avel*Amass + Bvel*Bmass = fAvel*Amass + fBvel*Bmass
	Avel - Bvel = -(fBvel - fAvel)
	fBvel = Bvel - Avel + fAvel
	///
	Avel*Amass +  = fAvel*Amass - Avel*Bmass + fAvel*Bmass
	*/

	vec2 normal = hit.axis * hit.hand;

	vec2 Rvel = Avel - Bvel;

	float j = // impulse
			  // the total energy applied across the normal
		-(1 + elas)*dot(Rvel, normal) /
		dot(normal, normal*(1 / Amass + 1 / Bmass));


	Avel += (j / Amass) * normal;
	Bvel -= (j / Bmass) * normal;

	Apos += normal * hit.pDepth * Amass / (Amass + Bmass);
	Bpos -= normal * hit.pDepth * Bmass / (Amass + Bmass);
}


