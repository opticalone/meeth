#include "player.h"
#include "sfwdraw.h"

#include "cstdlib"

Player::Player(vec2 pos, vec2 scale, float angle, float speeds)
{
	speed = speeds;
	dudeT.position = pos;
	dudeT.dimension = scale;
	dudeT.angle = angle;
}

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
	dudeT.position += movement;
	if (sfw::getKey('F'))
	{
		speed = 10;
	}
}

void Player::Draw()
{
	int dudebro = sfw::loadTextureMap("res/dudebro.png");
	sfw::drawTexture(dudebro, dudeT.position.x, dudeT.position.y,100,100);
}
