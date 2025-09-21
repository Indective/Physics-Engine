#pragma once
#include "raylib.h"
#include <iostream>


struct AABB
{
    Vector2 velocity;
    Vector2 position;
    Vector2 acceleration;
    float width, height;
};

class bodies
{
private:
    const float dt = GetFrameTime();
 
public:
    bool AABBvsAABB(AABB& a, AABB& b);
    void collisionres(AABB& a, AABB& ground);
    void update(AABB& a);
};

