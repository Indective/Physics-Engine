#include "bodies.hpp"
#include "raylib.h"
#include <iostream>

bool bodies::AABBvsAABB(AABB& a, AABB& b)
{
    return (a.position.x < b.position.x + b.width &&
            a.position.x + a.width > b.position.x &&
            a.position.y < b.position.y + b.height &&
            a.position.y + a.height > b.position.y);
}

void bodies::collisionres(AABB &a, AABB& ground)
{
    if (AABBvsAABB(a, ground)) 
    {
        // Put box on top of ground
        a.position.y = ground.position.y - a.height;

        // Stop downward velocity
        a.velocity.y = 0;
        a.acceleration.y = 0;
    }
}

void bodies::update(AABB &a)
{
    // Apply acceleration to velocity
    a.velocity.x += a.acceleration.x * GetFrameTime();
    a.velocity.y += a.acceleration.y * GetFrameTime();
    std::cout << "Velocity after change : " << a.velocity.x << " " << a.velocity.y << std::endl;

    // Apply velocity to position
    a.position.x += a.velocity.x * GetFrameTime();
    a.position.y += a.velocity.y * GetFrameTime();
}
