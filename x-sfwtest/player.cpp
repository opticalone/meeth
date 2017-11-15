#include "player.h"
#include "sfwdraw.h"
#include "cstdlib"
#include <cmath>
#include "vec2.h"
bool doCollision(Player & player, const Wall & wall)
{

	auto hit = collides(player.transform, player.collider,
						wall.transform, wall.collider
					   );

	if (hit.pDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit,0.1);
		std::cout << "is schmacko" << std::endl;
		return true;
	}
	return false;
}

void doCollision(Player &player, Enemy & enemy)
{
	Collision hit = collides(player.transform, player.collider,
							  enemy.transform,  enemy.collider);
	if (hit.pDepth >0)
	{
		dynamic_resolution(player.transform.position,
			player.rigidbody.velocity,
			player.rigidbody.mass,
			enemy.transform.position,
			enemy.rigidbody.velocity,
			enemy.rigidbody.mass,
			hit, 1.005);
	}
}

//bool doCollision(Player & player, const Enemy & enemy)
//{
//	auto hit = collides(player.transform, player.collider,
//		enemy.transform, enemy.collider
//	);
//
//	if (hit.pDepth > 0)
//	{
//		static_resolution(player.transform.position, player.rigidbody.velocity, hit,1.0001);
//		std::cout << "is schmacko" << std::endl;
//		return true;
//	}
//	return false;
//}


bool doCollision(Enemy & enemy, const Wall & wall)
{
	auto hit = collides(enemy.transform, enemy.collider,
		wall.transform, wall.collider
	);

	if (hit.pDepth > 0)
	{
		static_resolution(enemy.transform.position, enemy.rigidbody.velocity, hit,1.1);
		std::cout << "is schmacko" << std::endl;
		return true;
	}
	return false;
}

void chasem(Enemy &enemy, Player &player)
{
	vec2 pPos = { player.transform.position.x, player.transform.position.y };
	vec2 ePos = { enemy.transform.position.x, enemy.transform.position.y };


	vec2 VelocityDesx =  dist(ePos,pPos) * norm(pPos-ePos);

	enemy.rigidbody.force.x = (VelocityDesx.x - enemy.rigidbody.velocity.x) * 20;
	enemy.rigidbody.force.y = (VelocityDesx.y - enemy.rigidbody.velocity.y) *20;
	////Enemy needs to add force in a direction, whats the direction?
	//vec2 ProjectedVelocityX = pPos + (norm(player.rigidbody.velocity) * (float)20);

	//vec2 Dir = norm(ePos - pPos);

	// enemy.rigidbody.force.x += (Dir * ProjectedVelocity);



	


}




