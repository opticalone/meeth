#include "sfwdraw.h"
#include "player.h"
#include <iostream>
#include "transform.h"
int main()
{

	sfw::initContext(600, 600, "waddap");
	sfw::setBackgroundColor(BLACK);

	Transform myTransform;
	myTransform.position = vec2{ 300, 300 };
	myTransform.dimension = vec2{ 2,2 };
	myTransform.angle = 0;

	Transform yTransform;
	yTransform.position = vec2{ 50, 50 };
	yTransform.dimension = vec2{ 3,3 };
	yTransform.angle = 0;
	yTransform.e_parent = &myTransform;

	Transform aTransform;
	aTransform.position = vec2{ 25, 25 };
	aTransform.dimension = vec2{ 4,4 }; 
	aTransform.angle = 0;
	aTransform.e_parent = &yTransform;

	Transform bTransform;
	bTransform.position = vec2{ 50, 12 };
	bTransform.dimension = vec2{ 5,5 };
	bTransform.angle = 0;
	bTransform.e_parent = &aTransform;

	while (sfw::stepContext())
	{
		float t = sfw::getTime();

		myTransform.angle += sfw::getDeltaTime() * 90;
		myTransform.dimension = vec2{ sinf(t) * 2, sinf(t) * 4 };

		yTransform.angle *= sfw::getDeltaTime() - 90;
		yTransform.dimension = vec2{ sinf(t) - 1, sinf(t) - 1 };

		aTransform.angle += sfw::getDeltaTime() + 45;
		aTransform.dimension = vec2{ sinf(t) + 1, sinf(t) + 1};

		bTransform.angle *= sfw::getDeltaTime() + 30;
		bTransform.dimension = vec2{ sinf(t) * 2, sinf(t) / 2 };
		

		DrawMatrix(myTransform.getGlobalTransform(), 40);
		DrawMatrix(yTransform.getGlobalTransform(), 30);
		DrawMatrix(aTransform.getGlobalTransform(), 20);
		DrawMatrix(bTransform.getGlobalTransform(), 10);
	}

	
	
	sfw::termContext();
}