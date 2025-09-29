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
    a.position.x = 2 * a.position.x - a.trail.back().x + a.acceleration.x * (dt * dt);
    a.position.y = 2 * a.position.y - a.trail.back().y + a.acceleration.y * (dt * dt);

    a.trail.push_back(a.position);
}

void bodies::draw(AABB &a)
{
    DrawRectangle(a.position.x,a.position.y,a.width,a.height,a.color);
}

AABB &bodies::spawnobject(Vector2 velocity, Vector2 poistion, Vector2 acceleration, float width, float height, std::string name, Color color, std::vector<AABB> &objects)
{
    AABB newobject;
    newobject.position = poistion;
    newobject.width = width;
    newobject.height = height;
    newobject.velocity = velocity;
    newobject.acceleration = acceleration;
    newobject.name = name;
    newobject.color = color;
    newobject.trail.push_back(newobject.position);
    objects.push_back(newobject);
    return objects.back();
}
