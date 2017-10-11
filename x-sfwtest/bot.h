#pragma once
#include "vec2.h"

class Bot
{
public:
	vec2 pos;
	float speed;
	void update();
	void Draw();
};