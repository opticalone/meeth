#include "enemy.h"
#include "sfwdraw.h"

#include "cstdlib"

Enemy::Enemy(vec2 pos, vec2 scale, float angle, float speeds)
{
	speed = speeds;
	broT.position = pos;
	broT.dimension = scale;
	broT.angle = angle;
}

void Enemy::update()
{


	vec2 movement = { 0,0 };
	if (sfw::getKey('I'))
	{
		movement.y += 1;
	}
	if (sfw::getKey('K'))
	{
		movement.y -= 1;
	}
	if (sfw::getKey('J'))
	{
		movement.x -= 1;
	}
	if (sfw::getKey('L'))
	{
		movement.x += 1;
	}

	movement *= speed;
	broT.position += movement;
	if (sfw::getKey('F'))
	{
		speed = 10;
	}
}

void Enemy::Draw()
{
	int antidudebro = sfw::loadTextureMap("res/antidudebro.png");
	sfw::drawTexture(antidudebro, broT.position.x, broT.position.y, 100, 100);
}