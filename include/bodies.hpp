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
};

struct circle
{
    Vector2 velocity;
    Vector2 position;
    Vector2 acceleration;
    float radius;
    std::string name;
    Color color;
    std::vector<Vector2> trail;
};

class bodies
{
private:
    const float dt = GetFrameTime();
 
public:
    bool AABBvsAABB(AABB& a, AABB& b);
    void collisionres(AABB& a, AABB& ground);
    void update(AABB& a);
    void draw(AABB& a);
    AABB &spawnobject(Vector2 velocity, Vector2 poistion, Vector2 acceleration, float width, float height, std::string name, Color color,  std::vector<AABB> &objects);
};

