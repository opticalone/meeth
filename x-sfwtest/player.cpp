#include "player.h"
#include "sfwdraw.h"

void Player::update()
{
	vec2 movement = { 0,0 };
	if (sfw::getKey('W'))
	{
		movement.y += 1;
	}
	if (sfw::getKey('S'))
	{
		movement.y -= 1;
	}
	if (sfw::getKey('A'))
	{
		movement.x -= 1;
	}
	if (sfw::getKey('D'))
	{
		movement.x += 1;
	}

	movement *= speed;
	pos += movement;
	if (sfw::getKey('F'))
	{
		speed+=5;
	}
}

void Player::Draw()
{
	sfw::drawCircle(pos.x, pos.y, 30.f);
}
