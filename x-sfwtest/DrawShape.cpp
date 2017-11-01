#include "DrawShape.h"
#include "vec2.h"
#include "shapes.h"
#include "transform.h"
#include "sfwdraw.h"
void drawCircle(const circle &C)
{
	sfw::drawCircle(C.position.x, C.position.y, C.radius);
}

void drawAABB(const AABB & box, int color)
{
	sfw::drawLine(box.position.x + box.extents.x, box.position.y + box.extents.y,       box.position.x + box.extents.x, box.position.y - box.extents.y, color);
	sfw::drawLine(box.position.x - box.extents.x, box.position.y - box.extents.y,       box.position.x + box.extents.x, box.position.y - box.extents.y,color);
	sfw::drawLine(box.position.x - box.extents.x, box.position.y + box.extents.y,       box.position.x - box.extents.x, box.position.y - box.extents.y, color);
	sfw::drawLine(box.position.x + box.extents.x, box.position.y + box.extents.y,	    box.position.x - box.extents.x, box.position.y + box.extents.y, color);
}
