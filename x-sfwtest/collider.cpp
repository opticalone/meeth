#include "collider.h"

Collision collides(const Transform & At, const Collider & Ac,
				   const Transform & Bt, const Collider & Bc)
{
	return intersect_AABB(Ac.getGlobalBox(At), Bc.getGlobalBox(Bt));
}

void static_resolution(vec2 & pos, vec2 & vel, const Collision & hit)
{
}
