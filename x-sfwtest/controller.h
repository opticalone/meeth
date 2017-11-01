#pragma once
#include "transform.h"
#include "Rigidbody.h"
#include "sfwdraw.h"
//poll for input and apply to rigid body
class Controller
{
public:

	void poll(Rigidbody &rb, const Transform &t )
	{
		if (sfw::getKey('W'))rb.force += t.getGlobalTransform()[1].xy * 2.f;
		if (sfw::getKey('A'))rb.torque += 360;
		if (sfw::getKey('S'))rb.force += t.getGlobalTransform()[1].xy * 2.f;
		if (sfw::getKey('D'))rb.torque += -360;

		if (sfw::getKey('Q'))rb.impulse += t.getGlobalTransform()[1].xy * 1.005f;
		if (sfw::getKey(' '))
		{
			rb.force += rb.velocity * 20;
			rb.torque += rb.aVelocity * 20;
		}
	}

};