#pragma once
#include "vec2.h"
#include "transform.h"
class Rigidbody
{
public:
	float mass;

	vec2 velocity,
		 acceleration,
		 force,
		 impulse;

	float drag;

	float aVelocity;
	float aAcceleration;
	float torque;
	float aDrag;


	Rigidbody() : velocity{ 0,0 }, 
				  acceleration{ 0,0 },
				  force{0,0},
				  impulse{0,0},
				  mass(1),
				  drag(1.1f),
		aVelocity(0),
		aAcceleration(0),
		torque(0),
		aDrag(1)
				  //speed * Direction
	{

	}
	

	void integrate(Transform &T, float dt)
	{
		acceleration = force / mass;
		velocity += acceleration* dt + impulse / mass;
		T.position += velocity * dt;

		impulse  = { 0,0 };
		force = -velocity * drag;

		aAcceleration = torque / mass;
		aVelocity += aAcceleration * dt;
		T.angle += aVelocity * dt;
		torque = -aVelocity * aDrag;
	}

};