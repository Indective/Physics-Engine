#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>

struct PhysicsObject
{
    Vector2 velocity;
    Vector2 position;
    Vector2 acceleration;
    float width, height;
    std::string name;
    Color color;
};

struct Constants
{
    const float g = 100;
    const float friction = 100.0f;
};

namespace PhysicsSystem
{
    bool AABBvsAABB(PhysicsObject& a, PhysicsObject& b);
    void collisionres(PhysicsObject& a, PhysicsObject& ground);
    void update(PhysicsObject& a, PhysicsObject& b, const float dt);
    void applyfriction(PhysicsObject& a, PhysicsObject &b, const float dt);
    bool AABBvsGround(PhysicsObject& a, PhysicsObject& b);
};

