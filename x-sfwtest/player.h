#pragma once
#include "vec2.h"
#include "transform.h"
#include "collider.h"
#include "Sprite.h"
#include "Rigidbody.h"
#include "controller.h"

class Enemy;

class Player
{
public:
	Transform transform;
	Rigidbody rigidbody;
	Collider collider;
	Controller comtroller;
	Sprite sprite;
	Enemy * enemy;
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

void chasem(Enemy &enemy, Player &player);

bool doCollision(Player &player, const Wall &wall);

void doCollision(Player &player, Enemy & enemy);

bool doCollision(Enemy & enemy, const Wall & wall);
