#include "sfwdraw.h"
#include "player.h"
#include <iostream>
#include "transform.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 
#include "enemy.h"
#include"meethutils.h"

int main()
{
	
	srand(time(NULL));
	sfw::initContext(1900, 1050, "Don't Go Into the Light");
	sfw::setBackgroundColor(0x1e0042ff);

	
	float ab = rand() % 4;
	float cd = rand() % 5;
	float ef = rand() % 6;





	//static transforms for rotating around

	Transform myTransform;
	myTransform.position = vec2{ 1800 , 50 };
	myTransform.dimension = vec2{ 1,1 };
	myTransform.angle = ab;

	Transform mybTransform;
	mybTransform.position = vec2{ 10 , 50 };
	mybTransform.dimension = vec2{ 1,1 };
	mybTransform.angle = ab;

	Transform mycTransform;
	mycTransform.position = vec2{ 10 , 1030 };
	mycTransform.dimension = vec2{ 1,1 };
	mycTransform.angle = ef;

	Transform mydTransform;
	mydTransform.position = vec2{ 1890 , 1000 };
	mydTransform.dimension = vec2{ 1,1 };
	mydTransform.angle = ab;




	//the beams

	Transform yTransform[300];
	for (int i = 0; i < 299; i++)
	{
		yTransform[i].position = vec2{ -1.f - i, 1.f + i };
		yTransform[i].dimension = vec2{ 1,1 };
		yTransform[i].angle = ab;
		yTransform[i].e_parent = &myTransform;
		float ab = rand() % 4;
		
	}


	Transform aTran[300];
	for (int i = 0; i < 299; i++)
	{
		aTran[i].position = vec2{ 1.f +i  , 1.f +i };
		aTran[i].dimension = vec2{ 1,1 };
		aTran[i].angle = ab;
		aTran[i].e_parent = &mydTransform;
		float ab = rand() % 10;
	}


	Transform bTransform[300];
	for (int i = 0; i < 299; i++)
	{
		bTransform[i].position = vec2{ 1.f + i, 1.f + i };
		bTransform[i].dimension = vec2{ 1,1 };
		bTransform[i].angle = ab;
		bTransform[i].e_parent = &mybTransform;
		float ab = rand() % 7;
	}


	Transform cTransform[300];
	for (int i = 0; i < 299; i++)
	{
		cTransform[i].position = vec2{ 1.f - i, 1.f - i };
		cTransform[i].dimension = vec2{ 1,1 };
		cTransform[i].angle = ef;
		cTransform[i].e_parent = &mycTransform;
	}

		Player me(vec2{ 100, 100 }, vec2{ 1,1 }, 15 ,30, 16); // CREATe PLAYER
		Enemy dood(vec2{ 200, 200 }, vec2{ 1,1 }, 15, 29, 16, 100); // CREATE ENEMY
		Enemy dood2(vec2{ 300, 200 }, vec2{ 1,1 }, 15, 20, 16, 100); // CREATE ENEMY







	while (sfw::stepContext())
	{
		float t = sfw::getTime();
		me.update();
		me.Draw();
		dood.update();
		dood.Draw();

		dood2.update();
		dood2.Draw();

		//DrawMatrix(myTransform.getGlobalTransform(), 20);
		//myTransform.angle += sfw::getDeltaTime() + 5;
		myTransform.dimension = vec2{ sinf(t) * ab, sinf(t) + ab };
		mybTransform.dimension = vec2{ sinf(t) * ab, sinf(t) + cd };
		mycTransform.dimension = vec2{ sinf(t) * ab, -sinf(t) + ef };
		mydTransform.dimension = vec2{ sinf(t) * ab, -sinf(t) - cd };

		for (int i = 0; i < 199; i++)
		{
			yTransform[i].angle = { sinf(t) * ab};
			yTransform[i].dimension = vec2{ sinf(t) * cd, sinf(t)* ab };

			bTransform[i].dimension = vec2{ sinf(t) * ab, sinf(t) - ef };
			bTransform[i].angle = { sinf(t) * cd };

			cTransform[i].dimension = vec2{ sinf(t) * ab, sinf(t) - cd };
			bTransform[i].angle = { sinf(t) * ef };

			aTran[i].angle = { sinf(t) * ab};
			aTran[i].dimension = vec2{ sinf(t) * cd, sinf(t) * ab };
			
			
			
			

			DrawMatrix(yTransform[i].getGlobalTransform(), i+1 );
			DrawMatrix(aTran[i].getGlobalTransform(), i + 1);
			DrawMatrix(bTransform[i].getGlobalTransform(), i + 1);
			DrawMatrix(cTransform[i].getGlobalTransform(), i + 1);
		}
		dood.Collision(me);
		dood2.Collision(me);
		std::cout <<"enemy 1:"<< dood.m <<std::endl<<std::endl;
		std::cout <<"enemy 2:"<< dood2.m << std::endl;
	}

	
	
	sfw::termContext();
}