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

    // create objects
    AABB box = physics.spawnobject({100,0},{100,0},{0,500},50,50,"box1",BLUE,objects);

    AABB box2 = physics.spawnobject({0,0},{200,0},{-100,500},50,50,"box2",MAROON,objects);

    AABB box3 = physics.spawnobject({0,0},{300,0},{-100,500},50,50,"box3",RED,objects);

    AABB wall = physics.spawnobject({0,0},{0,0},{0,0},50,screen_height,"wall",BLACK,objects);

    AABB ground = physics.spawnobject({0,0},{0,650},{0,0},screen_width,50,"ground",BLACK,objects);

    // start initialization
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
