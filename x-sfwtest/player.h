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

class Wall
{
public:
	Transform transform;
	Collider collider;
	Sprite sprite;
};

bool doCollision(Player &player, Wall &wall);