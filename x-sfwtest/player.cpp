#include "player.h"
#include "sfwdraw.h"

#include "cstdlib"

Player::Player(vec2 pos, vec2 scale, float angle, float speeds,int rdius)
{
	speed = speeds;
	dudeT.position = pos;
	dudeT.dimension = scale;
	dudeT.angle = angle;
	h = rdius;

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
		speed * 10;
	}
}

void DrawCircle(vec2 pos, float r)
{
	  sfw::drawCircle(pos.x, pos.y, r, 12, GREEN);
}

void Player::Draw()
{
	int dudebro = sfw::loadTextureMap("res/dudebro.png");
	//harrisDrawCircle(dudeT.position, h);
	sfw::drawTexture(dudebro, dudeT.position.x-25, dudeT.position.y-25,100,100);
	
}
