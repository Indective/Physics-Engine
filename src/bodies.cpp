#include "bodies.hpp"
#include "raylib.h"
#include "raymath.h"
#include <iostream>
#include <cmath>

Constants con; 

bool PhysicsSystem::AABBvsAABB(PhysicsObject& a, PhysicsObject& b) // checks for object collision (excluding ground)
{
    return (a.position.x < b.position.x + b.width &&
            a.position.x + a.width > b.position.x &&
            a.position.y < b.position.y + b.height &&
            a.position.y + a.height > b.position.y && (a.name != "ground" && b.name != "ground"));
}

void PhysicsSystem::collisionres(PhysicsObject &a, PhysicsObject& b) // resolves collision for all objects (including ground vs object)
{
    if (AABBvsAABB(a, b)) 
    {
        float overlapX = std::min(a.position.x + a.width, b.position.x + b.width) -
                         std::max(a.position.x, b.position.x);

        float overlapY = std::min(a.position.y + a.height, b.position.y + b.height) -
                         std::max(a.position.y, b.position.y);

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
            a.velocity.y = 0;
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

void PhysicsSystem::update(PhysicsObject &a, PhysicsObject& b,const float dt) // updates velocity and position
{
    if(a.position.y == 650 - a.height && a.velocity.x == 0)
    {
        return;
    }
    
    if (AABBvsGround(a, b))
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
} 

void PhysicsSystem::applyfriction(PhysicsObject &a, PhysicsObject &b,const float dt) // applies friction on velocity.x when an object is colliding with the ground
{
    const float stopThreshold = 0.5f;
    const float frictionForce = con.friction * dt;

    if(abs(a.velocity.y < 10))
    {
        a.velocity.y = 0;
        a.acceleration.y = 0;
    }

    if (abs(a.velocity.x - stopThreshold) <= 0.5f)
    {
        a.velocity.x = 0.0f;
        return;
    }

    if (a.velocity.x > 0)
    {
        a.velocity.x = std::max(0.0f, a.velocity.x - frictionForce);
    }
    else if (a.velocity.x < 0)
    {
        a.velocity.x = std::min(0.0f, a.velocity.x + frictionForce);
    }
}

bool PhysicsSystem::AABBvsGround(PhysicsObject &a, PhysicsObject &b) // checks for a collision only between the ground and an object
{
    if (b.name != "ground" && a.name != "ground") 
    {
        return false;
    }
    
    PhysicsObject& obj = (a.name == "ground") ? b : a;
    PhysicsObject& ground = (a.name == "ground") ? a : b;

    return obj.position.y + obj.height >= ground.position.y;
}

