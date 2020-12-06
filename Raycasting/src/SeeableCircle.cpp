#include "SeeableCircle.h"

SeeableCircle::SeeableCircle(float x, float y, float radius)
{
	circle.x = x;
	circle.y = y;
	circle.radius = radius;
}

bool SeeableCircle::seenBy(Geo::LineSeg & ray, float & dist, float & intersectedAt, std::array<float, 2>* pointOfIntersection)
{
	std::vector<std::array<float, 2>> poi;
	if (!circle.getIntersection(ray, &poi)) {
		return false;
	}

	float distSQ = 0.0f;
	if (poi.size() > 0) {
		distSQ = pow(poi[0][0] - ray.x1, 2) + pow(poi[0][1] - ray.y1, 2);
		if (pointOfIntersection)
			*pointOfIntersection = poi[0];
		if (poi.size() > 1) {
			if (distSQ > pow(poi[1][0] - ray.x1, 2) + pow(poi[1][1] - ray.y1, 2)) {
				distSQ = pow(poi[1][0] - ray.x1, 2) + pow(poi[1][1] - ray.y1, 2);
				if (pointOfIntersection) 
					*pointOfIntersection = poi[1];
			}
		}
	}
	else {
		return false;
	}

	dist = sqrt(distSQ);

	return true;
}

void SeeableCircle::renderPrimitive()
{
	circle.renderOutline(color[0], color[1], color[2]);
}

void SeeableCircle::renderPrimitive(std::array<float, 2> translation, float scale)
{
	Geo::Circle circleCopy = circle;
	circleCopy.radius *= scale;
	circleCopy.x += translation[0];
	circleCopy.y += translation[1];
	circleCopy.renderOutline(color[0], color[1], color[2]);
}