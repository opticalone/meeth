#pragma once
#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"
//poll for input and apply to rigid body
class Controller
{

public:
	float turningSpeed;
	float speed;
	float brakePower;

	Controller() : turningSpeed(240), speed(500), brakePower(9)
	{

	}

	void poll(Rigidbody &rb, const Transform &t)
	{

		if (sfw::getKey('W'))rb.force +=
			norm(t.getGlobalTransform()[1].xy) * speed;

		if (sfw::getKey('S'))rb.force -=
			norm(t.getGlobalTransform()[1].xy) * speed;

		if (sfw::getKey('A'))rb.force -=
			norm(t.getGlobalTransform()[0].xy) * speed;

		if (sfw::getKey('D'))rb.force +=
			norm(t.getGlobalTransform()[0].xy) * speed;

		

		if (sfw::getKey(' ')) //breaking force
		{
			rb.force += -rb.velocity * brakePower;
			rb.torque += -rb.aVelocity * brakePower;
		}
		if (sfw::getKey('E'))rb.impulse;
	}
};