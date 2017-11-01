#include "player.h"
#include "sfwdraw.h"
#include "cstdlib"

bool doCollision(Player & player, Wall & wall)
{
	auto hit = collides(player.transform, player.collider, wall.transform, wall.collider);

	if (hit.pDepth > 0)
	{
		static_resolution(player.transform.position, player.rigidbody.velocity, hit, 2);
		return true;
	}
	return false;
}

