#include "bodies.hpp"
#include "raylib.h"
#include "raymath.h"
#include <iostream>

bool bodies::AABBvsAABB(AABB& a, AABB& b)
{
    return (a.position.x < b.position.x + b.width &&
            a.position.x + a.width > b.position.x &&
            a.position.y < b.position.y + b.height &&
            a.position.y + a.height > b.position.y);
}

void bodies::collisionres(AABB &a, AABB& b)
{
    if (AABBvsAABB(a, b)) 
    {
        // compute overlap depths
        float overlapX = std::min(a.position.x + a.width, b.position.x + b.width) -
                        std::max(a.position.x, b.position.x);

        float overlapY = std::min(a.position.y + a.height, b.position.y + b.height) -
                        std::max(a.position.y, b.position.y);

        // resolve along the shallowest axis
        if (overlapX < overlapY)
        {
            if (a.position.x < b.position.x) 
            {
                a.position.x -= overlapX;  
            }
            else 
            {
                a.position.x += overlapX; 
            }

            a.velocity.x *= -0.5f; // 
        }
        else
        {
            if (a.position.y < b.position.y) 
            {
                a.position.y -= overlapY;  
            }
            else 
            {
                a.position.y += overlapY;  
            }

            a.velocity.y *= -0.5f; // bounce with damping
        }
        
    }
}

void bodies::update(AABB &a)
{
    // Apply acceleration to velocity
    a.velocity.x += a.acceleration.x * GetFrameTime();
    a.velocity.y += a.acceleration.y * GetFrameTime();

    // Apply velocity to position
    a.position.x += a.velocity.x * GetFrameTime();
    a.position.y += a.velocity.y * GetFrameTime();
    a.trail.push_back(a.position);
}

void bodies::draw(AABB &a)
{
    DrawRectangle(a.position.x,a.position.y,a.width,a.height,a.color);
}


