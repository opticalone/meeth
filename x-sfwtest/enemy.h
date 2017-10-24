#pragma once
#include "vec2.h"
#include "transform.h"


class Enemy
{
public:

	Transform broT;

	Enemy(vec2 pos, vec2 scale, float angle, float speeds);

	float speed;
	void update();
	void Draw();
};