#include "bodies.hpp"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <cmath>

bool bodies::AABBvsAABB(AABB& a, AABB& b)
{
    return (a.position.x < b.position.x + b.width &&
            a.position.x + a.width > b.position.x &&
            a.position.y < b.position.y + b.height &&
            a.position.y + a.height > b.position.y && (a.name != "ground" && b.name != "ground"));
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
            if(a.velocity.x > 1.0)
            {
                a.velocity.x *= -0.5f;
            }
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
    else if(AABBvsGround(a,b))
    {
        float overlapY = std::min(a.position.y + a.height, b.position.y + b.height) -
                         std::max(a.position.y, b.position.y);
        if (a.position.y < b.position.y) 
        {
            a.position.y -= overlapY;  
        }
        else 
        {
            a.position.y += overlapY;  
        }

        a.velocity.y *= -0.5f; 
    }
}


void bodies::update(AABB &a, AABB& b,const float dt)
{
    if (AABBvsGround(a, b) && b.name == "ground")
    {
        applyfriction(a, b, dt);
    }
    else
    {
        a.velocity.y += a.acceleration.y * dt;
        a.velocity.x += a.acceleration.x * dt;
    }

    a.position.x += a.velocity.x * dt;
    a.position.y += a.velocity.y * dt;
    std::cout << a.name << " velocity x " << a.velocity.x << std::endl;
    a.trail.push_back(a.position);
} 

void bodies::draw(AABB &a)
{
    DrawRectangle(a.position.x,a.position.y,a.width,a.height,a.color);
}

void bodies::applyfriction(AABB &a, AABB &b,const float dt)
{
    if (AABBvsGround(a, b) && b.name == "ground")
    {
        if (a.velocity.x > 0)   
            a.velocity.x -= friction * dt;
        else if (a.velocity.x < 0)
            a.velocity.x += friction * dt;

        if (fabs(a.velocity.x) < 1.0f)
            a.velocity.x = 0.0f;
            std::cout << a.name << " velocity after change : " << a.velocity.x << std::endl;
    }
}

bool bodies::AABBvsGround(AABB &a, AABB &b)
{
    return (a.position.x < b.position.x + b.width &&
            a.position.x + a.width > b.position.x &&
            a.position.y < b.position.y + b.height &&
            a.position.y + a.height > b.position.y && (a.name == "ground" || b.name == "ground"));
}
