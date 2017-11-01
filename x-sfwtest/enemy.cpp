#include "enemy.h"
#include "sfwdraw.h"

#include "mat3.h"
#include"meethutils.h"
#include <cmath>
#include "cstdlib"

bool isCol = false;



Enemy::Enemy(vec2 pos, vec2 scale, float angle, float speeds, int radius, int health)
{
	speed = speeds;
	broT.position = pos;
	broT.dimension = scale;
	broT.angle = angle;
	h = radius;
	m = health;
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
	if (sfw::getKey('Q'))
	{
		speed + 10;
	}

	if (isCol)
	{
		m-=5;
		
		
	}


}
void DrawCirclez(vec2 pos, float r)
{
	sfw::drawCircle(pos.x, pos.y, r, 12, ORANGE);
}
void Enemy::Draw()
{
	
	
	if (m<50 && m>0)
	{
		int bantidudebro = sfw::loadTextureMap("res/antidudebro.png");
		sfw::drawTexture(bantidudebro, broT.position.x, broT.position.y, 100, 100, 0, true, 0, RED);
	}
	
	else if (m > 0)
	{

	int antidudebro = sfw::loadTextureMap("res/antidudebro.png");
	sfw::drawTexture(antidudebro, broT.position.x, broT.position.y, 100, 100,0,true,0);
	DrawCirclez(broT.position, h);

	}
	 

		std::cout << "IM HITTING HIM"<<std::endl;
}







