#include "bodies.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

int main()
{
    const int screen_width = 1500;
    const int screen_height = 700;

    bodies physics;                // physics engine
    std::vector<AABB> objects;     // all objects

    AABB box;
    box.position = {100,0};
    box.width = 50;
    box.height = 50;
    box.velocity = {100,0};
    box.acceleration = {0,500};
    box.name = "box1";
    box.color = BLUE;
    box.trail.push_back(box.position);
    objects.push_back(box);

    AABB box2;
    box2.position = {200,0};
    box2.width = 50;
    box2.height = 50;
    box2.velocity = {0,0};
    box2.acceleration = {-100,500};
    box2.name = "box2";
    box2.color = MAROON;
    box2.trail.push_back(box2.position);
    objects.push_back(box2);

    AABB box3;
    box3.position = {300,0};
    box3.width = 50;
    box3.height = 50;
    box3.velocity = {0,0};
    box3.acceleration = {-100,500};
    box3.name = "box2";
    box3.color = RED;
    box3.trail.push_back(box3.position);
    objects.push_back(box2);

    AABB wall;
    wall.position = {0,0};
    wall.width = 50;
    wall.height = screen_height;
    wall.velocity = {0,0};
    wall.acceleration = {0,0};
    wall.name = "wall";
    wall.color = BLACK;
    wall.trail.push_back(wall.position);
    objects.push_back(wall);

    AABB ground;
    ground.position = {0,650};   
    ground.width = screen_width;
    ground.height = 50;
    ground.velocity = {0,0};
    ground.acceleration = {0,0};
    ground.name = "ground";
    ground.color = BLACK;
    ground.trail.push_back(ground.position);
    objects.push_back(ground);

    InitWindow(screen_width,screen_height,"engine");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < objects.size(); i++) 
        {
            physics.update(objects[i]);

            // handle collisions vs ground
            for (int j = 0; j < objects.size(); j++)
            {
                if (i == j) continue;

                physics.collisionres(objects[i], objects[j]);
                
            }

            // draw everyone
            physics.draw(objects[i]);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
