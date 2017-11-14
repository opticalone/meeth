#include "player.h"
#include "sfwdraw.h"
#include "cstdlib"

bool doCollision(Player & player, const Wall & wall)
{

	auto hit = collides(player.transform, player.collider,
						wall.transform, wall.collider
					   );

	if (hit.pDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit, 1.0001);
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
		static_resolution(enemy.transform.position, enemy.rigidbody.velocity, hit, 1);
		std::cout << "is schmacko" << std::endl;
		return true;
	}
	return false;
}




