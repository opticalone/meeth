#include "sfwdraw.h"
#include "player.h"
#include <iostream>
#include "transform.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h> 

#include"meethutils.h"
#include "Rigidbody.h"
#include "shapes.h"
#include "DrawShape.h"
#include"collision.h"



int main()
{
	sfw::initContext(800, 800, "Don't Go Into the Light");
	sfw::setBackgroundColor(0x110030ff);

	Player player;

	player.sprite = sfw::loadTextureMap("res/dudebro.png");
	player.transform.dimension = vec2{ 52, 62 };
	player.transform.position = vec2{ 400,300 };
	player.collider.box.extents = { .5,.5 };

	Enemy enemy[20];
	enemy[0].sprite = sfw::loadTextureMap("res/antidudebro.png");
	enemy[0].transform.dimension = vec2{ 36,36 };
	enemy[0].transform.position = vec2{ 300,200 };
	enemy[0].collider.box.extents = { .5,.5 };

	enemy[1].sprite = sfw::loadTextureMap("res/antidudebro.png");
	enemy[1].transform.dimension = vec2{ 36,36 };
	enemy[1].transform.position = vec2{ 400,200 };
	enemy[1].collider.box.extents = { .5,.5 };

	enemy[2].sprite = sfw::loadTextureMap("res/antidudebro.png");
	enemy[2].transform.dimension = vec2{ 36,36 };
	enemy[2].transform.position = vec2{ 200,300 };
	enemy[2].collider.box.extents = { .5,.5 };

	enemy[3].sprite = sfw::loadTextureMap("res/antidudebro.png");
	enemy[3].transform.dimension = vec2{ 36,36 };
	enemy[3].transform.position = vec2{ 100,200 };
	enemy[3].collider.box.extents = { .5,.5 };

	enemy[4].sprite = sfw::loadTextureMap("res/antidudebro.png");
	enemy[4].transform.dimension = vec2{ 36,36 };
	enemy[4].transform.position = vec2{ 200,100 };
	enemy[4].collider.box.extents = { .5,.5 };

	

	Wall floor[20];

	floor[0].transform.position = { 400,10 };
	floor[0].transform.dimension = { 800,20 };
	floor[0].collider.box.extents = { .5, .5 };
	floor[0].sprite.dim = { 1,1 };
	//floor[0].sprite.handle = sfw::loadTextureMap("res/floor.png");

	floor[1].transform.position = { 10,400 };
	floor[1].transform.dimension = { 20,800 };
	floor[1].collider.box.extents = { .5, .5 };
	floor[1].sprite.dim = { 1,1 };
	//floor[1].sprite.handle = sfw::loadTextureMap("res/floor.png");

	floor[2].transform.position = { 400,790 };
	floor[2].transform.dimension = { 800,20 };
	floor[2].collider.box.extents = { .5, .5 };
	floor[2].sprite.dim = { 1,1 };
	//floor[2].sprite.handle = sfw::loadTextureMap("res/floor.png");

	floor[3].transform.position = { 790,400 };
	floor[3].transform.dimension = { 20,800 };
	floor[3].collider.box.extents = { .5, .5 };
	floor[3].sprite.dim = { 1,1 };
	//floor[3].sprite.handle = sfw::loadTextureMap("res/floor.png");

	floor[4].transform.position = { 400,400 };
	floor[4].transform.dimension = { 20,300 };
	floor[4].collider.box.extents = { .5, .5 };
	floor[4].sprite.dim = { 1,1 };
	//floor[3].sprite.handle = sfw::loadTextureMap("res/floor.png");

	while (sfw::stepContext())
	{
		
		

		float dt = sfw::getDeltaTime();

		player.comtroller.poll(player.rigidbody, player.transform);

		player.rigidbody.integrate(player.transform, dt);
		

		for (int i=0; i < 20; i++)
		{
		enemy[i].rigidbody.integrate(enemy[i].transform, dt);
		enemy[i].sprite.draw(enemy[i].transform); 
		}
		
		

		player.sprite.draw(player.transform);
		

		for (int i = 0; i < 20; i++)
		{
			floor[i].sprite.draw(floor[i].transform);

			

		}



		for (int i = 0; i < 20; ++i)
		{
			doCollision(player, floor[i]);
			
			doCollision(player, enemy[i]);
			for (int j = 0; j < 20; ++j)
			{
				doCollision(enemy[i], floor[j]);
			}
		}
		
		//drawAABB(player.collider.getGlobalBox(player.transform), BLUE);


		for (int i = 0; i < 5; ++i)
		{
			drawAABB(floor[i].collider.getGlobalBox(floor[i].transform), GREEN);
			
		}

		//std::cout << player.transform.position.x << "," << player.transform.position.y << std::endl;
	}
sfw::termContext();

}



























//
//int main()
//{
//
//	srand(time(NULL));
//
//	sfw::initContext(800, 600, "Don't Go Into the Light");
//
//	sfw::setBackgroundColor(0x1e0042ff);
//
//	Player player;
//	player.sprite = sfw::loadTextureMap("res/dudebro.png");
//	player.transform.dimension = vec2{ 20,20 };
//	player.transform.position = vec2{ 300,400 };
//	player.collider.box.extents = { .5,.5 };
//
//
//
//	
//	float dt = sfw::getDeltaTime();
//	Transform transformR;
//
//	Rigidbody rigidbody;
//
//	circle circ = {{ 0,0 }, 1};
//	circle circ2 = { { 100,100 },10 };
//
//
//	AABB aabb = { { 0,0 }, {1,1} };
//	AABB box2 = { {400,300},{50,50} };
//
//	transformR.position = vec2{ 400,300 };
//	transformR.dimension = vec2{ 50,75 };
//
//	//static transforms for rotating around
//
//	//Transform myTransform;
//	//myTransform.position = vec2{ 1800 , 50 };
//	//myTransform.dimension = vec2{ 1,1 };
//	//myTransform.angle = ab;
//
//	//Transform mybTransform;
//	//mybTransform.position = vec2{ 10 , 50 };
//	//mybTransform.dimension = vec2{ 1,1 };
//	//mybTransform.angle = ab;
//
//	//Transform mycTransform;
//	//mycTransform.position = vec2{ 10 , 1030 };
//	//mycTransform.dimension = vec2{ 1,1 };
//	//mycTransform.angle = ef;
//
//	//Transform mydTransform;
//	//mydTransform.position = vec2{ 1890 , 1000 };
//	//mydTransform.dimension = vec2{ 1,1 };
//	//mydTransform.angle = ab;
//
//	//Transform yTransform[300];
//	//for (int i = 0; i < 299; i++)
//	//{
//	//	yTransform[i].position = vec2{ -1.f - i, 1.f + i };
//	//	yTransform[i].dimension = vec2{ 1,1 };
//	//	yTransform[i].angle = ab;
//	//	yTransform[i].e_parent = &myTransform;
//	//	float ab = rand() % 4;
//	//	
//	//
//
//	//Transform aTran[300];
//	//for (int i = 0; i < 299; i++)
//	//{
//	//	aTran[i].position = vec2{ 1.f +i  , 1.f +i };
//	//	aTran[i].dimension = vec2{ 1,1 };
//	//	aTran[i].angle = ab;
//	//	aTran[i].e_parent = &mydTransform;
//	//	float ab = rand() % 10;
//	//}
//
//	//Transform bTransform[300];
//	//for (int i = 0; i < 299; i++)
//	//{
//	//	bTransform[i].position = vec2{ 1.f + i, 1.f + i };
//	//	bTransform[i].dimension = vec2{ 1,1 };
//	//	bTransform[i].angle = ab;
//	//	bTransform[i].e_parent = &mybTransform;
//	//	float ab = rand() % 7;
//	//}
//
//	//Transform cTransform[300];
//	//for (int i = 0; i < 299; i++)
//	//{
//	//	cTransform[i].position = vec2{ 1.f - i, 1.f - i };
//	//	cTransform[i].dimension = vec2{ 1,1 };
//	//	cTransform[i].angle = ef;
//	//	cTransform[i].e_parent = &mycTransform;
//	//}
//
//		//Player me(vec2{ 100, 100 }, vec2{ 1,1 }, 15 ,30, 16); // CREATe PLAYER
//		//Enemy dood(vec2{ 200, 200 }, vec2{ 1,1 }, 15, 29, 16, 100); // CREATE ENEMY
//		//Enemy dood2(vec2{ 300, 200 }, vec2{ 1,1 }, 15, 20, 16, 100); // CREATE ENEMY
//	
//
//	while (sfw::stepContext())
//	{
//		
//		player.comtroller.poll(player.rigidbody, player.transform);
//
//		player.rigidbody.integrate(player.transform, dt);
//		player.sprite.draw(player.transform);
//		
//	
//		drawAABB(player.collider.getGlobalBox(player.transform), GREEN);
//
//		drawCircle(circ2);
//		drawCircle(transformR.getGlobalTransform()*circ);
//
//		rigidbody.force = { 0,-75 };
//
//		
//
//		rigidbody.integrate(transformR, dt);
//
//		DrawMatrix(transformR.getGlobalTransform(), 12);
//
//		float t = sfw::getTime();
//
//		Collision result = intersect_AABB(transformR.getGlobalTransform()* aabb, box2);
//		Collision result2 = intersect_circle(transformR.getGlobalTransform()* circ, circ2);
//		unsigned color = result.pDepth < 0 ? BLUE : GREEN;
//
//		if (result.pDepth >= 0)
//			transformR.position += result.axis* result.hand * result.pDepth;
//		if (result2.pDepth >= 0)
//			transformR.position += result2.axis* result2.hand * result2.pDepth;
//
//
//		drawAABB(box2,color);
//		drawAABB(transformR.getGlobalTransform()*aabb, color);
//
//
//
//		/*me.update();
//		me.Draw();
//		dood.update();
//		dood.Draw();
//
//		dood2.update();
//		dood2.Draw();*/
//
//		//DrawMatrix(myTransform.getGlobalTransform(), 20);
//		//myTransform.angle += sfw::getDeltaTime() + 5;
//
//		/*myTransform.dimension = vec2{ sinf(t) * ab, sinf(t) + ab };
//		mybTransform.dimension = vec2{ sinf(t) * ab, sinf(t) + cd };
//		mycTransform.dimension = vec2{ sinf(t) * ab, -sinf(t) + ef };
//		mydTransform.dimension = vec2{ sinf(t) * ab, -sinf(t) - cd };
//
//		for (int i = 0; i < 199; i++)
//		{
//			yTransform[i].angle = { sinf(t) * ab};
//			yTransform[i].dimension = vec2{ sinf(t) * cd, sinf(t)* ab };
//
//			bTransform[i].dimension = vec2{ sinf(t) * ab, sinf(t) - ef };
//			bTransform[i].angle = { sinf(t) * cd };
//
//			cTransform[i].dimension = vec2{ sinf(t) * ab, sinf(t) - cd };
//			bTransform[i].angle = { sinf(t) * ef };
//
//			aTran[i].angle = { sinf(t) * ab};
//			aTran[i].dimension = vec2{ sinf(t) * cd, sinf(t) * ab };
//			
//			
//			
//			
//
//			DrawMatrix(yTransform[i].getGlobalTransform(), i+1 );
//			DrawMatrix(aTran[i].getGlobalTransform(), i + 1);
//			DrawMatrix(bTransform[i].getGlobalTransform(), i + 1);
//			DrawMatrix(cTransform[i].getGlobalTransform(), i + 1);
//		}*/
//
//		//dood.Collision(me);
//		//dood2.Collision(me);
//		//std::cout <<"enemy 1:"<< dood.m <<std::endl<<std::endl;
//		//std::cout <<"enemy 2:"<< dood2.m << std::endl;
//	}
//
//	
//	
//	sfw::termContext();
//}