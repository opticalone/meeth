#pragma once
#include "vec2.h"
#include "transform.h"
#include "collider.h"
#include "Sprite.h"
#include "Rigidbody.h"
#include "controller.h"
class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller comtroller;
	Sprite sprite;
	
};

class Enemy
{

public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;
};

class Wall
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Sprite sprite;

};



bool doCollision(Player &player, const Wall &wall);

void doCollision(Player &player, Enemy & enemy);

bool doCollision(Enemy & enemy, const Wall & wall);
