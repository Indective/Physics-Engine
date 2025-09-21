#include "bodies.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

int main()
{
    const int screen_width = 800;
    const int screen_height = 450;

    bodies physics;                // physics engine
    std::vector<AABB> objects;     // all objects

    // Falling box
    AABB box;
    box.position = {100,100};
    box.width = 50;
    box.height = 50;
    box.velocity = {0,0};
    box.acceleration = {0,500};
    objects.push_back(box);

    // Ground
    AABB ground;
    ground.position = {0,400};   
    ground.width = 800;
    ground.height = 50;
    ground.velocity = {0,0};
    ground.acceleration = {0,0};
    objects.push_back(ground);

    InitWindow(screen_width,screen_height,"engine");
    SetTargetFPS(60);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // update + draw all except ground
        for (size_t i = 0; i < objects.size(); i++) 
        {
            physics.update(objects[i]);
            if (i != objects.size() - 1) 
            {
                physics.collisionres(objects[i], objects.back()); // resolve vs ground
            }

            // draw
            Color color = (i == objects.size() - 1) ? BLUE : BLACK;
            DrawRectangle(objects[i].position.x, objects[i].position.y,
                          objects[i].width, objects[i].height, color);
        }
        std::cout << "pos: " << box.position.y 
        << " acc: " << box.acceleration.y << std::endl;
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
