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