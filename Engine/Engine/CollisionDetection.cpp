#include "CollisionDetection.h"
#include "EngineCore.h"

CollisionDetection* CollisionDetection::instance = nullptr;

bool CollisionDetection::CheckCollision(const Circle& collisionCircle1, const Circle& collisionCircle2)
{
    float dx = collisionCircle2.x - collisionCircle1.x;
    float dy = collisionCircle2.y - collisionCircle1.y;
    float distanceSq = dx * dx + dy * dy;

    float radiusSum = collisionCircle1.radius + collisionCircle2.radius;
    float radiusSumSq = radiusSum * radiusSum;

    return distanceSq <= radiusSumSq;
}

