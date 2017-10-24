#include "sfwdraw.h"
#include "player.h"
#include <iostream>
#include "transform.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "enemy.h"
int main()
{
	srand(time(NULL));
	sfw::initContext(1900, 1050, "waddap");
	sfw::setBackgroundColor(0x1e0042ff);

	float ab = rand() % 4;
	float cd = rand() % 13;
	float ef = rand() % 8;
	
	

	Transform myTransform;
	myTransform.position = vec2{ 1800 , 50 };
	myTransform.dimension = vec2{ 1,1 };
	myTransform.angle = ab;

	Transform mybTransform;
	mybTransform.position = vec2{ 10 , 50 };
	mybTransform.dimension = vec2{ 1,1 };
	mybTransform.angle = ab;

	Transform yTransform[200];
	for (int i = 0; i < 199; i++)
	{
		yTransform[i].position = vec2{ -1.f - i, 1.f + i };
		yTransform[i].dimension = vec2{ 1,1 };
		yTransform[i].angle = ab;
		yTransform[i].e_parent = &myTransform;
		
	}
	Transform aTran[200];
	for (int i = 0; i < 199; i++)
	{
		aTran[i].position = vec2{ 1.5f *i  , 1.f -i };
		aTran[i].dimension = vec2{ 1,1 };
		aTran[i].angle = ab;
		aTran[i].e_parent = &myTransform;

	}

	Transform bTransform[200];
	for (int i = 0; i < 199; i++)
	{
		bTransform[i].position = vec2{ 1.f + i, 1.f + i };
		bTransform[i].dimension = vec2{ 1,1 };
		bTransform[i].angle = ab;
		bTransform[i].e_parent = &mybTransform;
	}

		Player me(vec2{ 900, 530 }, vec2{ 1,1 }, -15 ,30);
		Enemy dood(vec2{ 800, 530 }, vec2{ 1,1 }, -15, 29);

	while (sfw::stepContext())
	{
		float t = sfw::getTime();
		me.update();
		me.Draw();
		dood.update();
		dood.Draw();
		//DrawMatrix(myTransform.getGlobalTransform(), 20);
		//myTransform.angle += sfw::getDeltaTime() + 5;
		myTransform.dimension = vec2{ sinf(t) * ab, sinf(t) + ab };
		mybTransform.dimension = vec2{ sinf(t) * ab, sinf(t) + 3 };

		for (int i = 0; i < 199; i++)
		{
			yTransform[i].angle = { sinf(360) * ab};
			yTransform[i].dimension = vec2{ sinf(t) * cd, sinf(t)* ab };

			//aTran[i].angle = { sinf(360) * ab};
			aTran[i].dimension = vec2{ sinf(t) + ab, sinf(t) / ab };
			
			bTransform[i].dimension = vec2{ sinf(t) * ab, sinf(t) - ef };
			
			DrawMatrix(yTransform[i].getGlobalTransform(), i+2 );
			DrawMatrix(aTran[i].getGlobalTransform(), i * 5);
			DrawMatrix(bTransform[i].getGlobalTransform(), i + 4);
			
		}
		
	}

	
	
	sfw::termContext();
}