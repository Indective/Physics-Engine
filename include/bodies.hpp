#pragma once
#include "raylib.h"
#include <iostream>
#include <vector>


struct AABB
{
    Vector2 velocity;
    Vector2 position;
    Vector2 acceleration;
    float width, height;
    std::string name;
    Color color;
    std::vector<Vector2> trail;
    const float g = 100;

};

class bodies
{
private:
    const float friction = 100.0f;
 
public:
    bool AABBvsAABB(AABB& a, AABB& b);
    void collisionres(AABB& a, AABB& ground);
    void update(AABB& a, AABB& b, const float dt);
    void draw(AABB& a);
    void applyfriction(AABB& a, AABB &b, const float dt);
    bool AABBvsGround(AABB& a, AABB& b);
};

