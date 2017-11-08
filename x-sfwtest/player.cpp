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
		static_resolution(player.transform.position, player.rigidbody.velocity, hit);
		std::cout << "is schmacko" << std::endl;
		return true;
	}
	return false;
}

bool doCollision(Player & player, const Enemy & enemy)
{
	auto hit = collides(player.transform, player.collider,
		enemy.transform, enemy.collider
	);

	if (hit.pDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit);
		std::cout << "is schmacko" << std::endl;
		return true;
	}
	return false;
}




