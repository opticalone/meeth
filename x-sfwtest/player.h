#pragma once
#include "vec2.h"
#include "transform.h"


class Player
{
public:

	Transform dudeT;

	Player(vec2 pos, vec2 scale, float angle, float speeds, int rdius);
	
	float speed;
	void update();
	void Draw();
	int h;
	
};