#pragma once
#include "vec2.h"
#include "transform.h"
#include "player.h"
#include "vec2.h"
class Enemy
{
public:
	bool isCol = false;
	Transform broT;

	Enemy(vec2 pos, vec2 scale, float angle, float speeds, int radius, int health);

	float speed;
	void update();
	void Draw();
	int h;
	int m;
	bool Collision(Player &me);
};