#include "bodies.hpp"
#include "raylib.h"
#include <iostream>
#include <vector>

void draw(PhysicsObject& a)
{
    DrawRectangle(a.position.x,a.position.y,a.width,a.height,a.color);
}

int main()
{
    const int screen_width = 1500;
    const int screen_height = 700;
    Constants con;
    std::vector<PhysicsObject> objects;     // all objects

    PhysicsObject box;
    box.position = {100,0};
    box.width = 50;
    box.height = 50;
    box.velocity = {0,0};
    box.acceleration = {5,con.g};
    box.name = "box1";
    box.color = RED;    
    objects.push_back(box);

    PhysicsObject box2;
    box2.position = {200,0};
    box2.width = 50;
    box2.height = 50;
    box2.velocity = {0,0};
    box2.acceleration = {10,con.g};
    box2.name = "box2";
    box2.color = DARKBLUE;
    objects.push_back(box2);

    PhysicsObject box3;  
    box3.position = {300,0};
    box3.width = 50;
    box3.height = 100;
    box3.velocity = {0,0};
    box3.acceleration = {5,con.g};
    box3.name = "box3";
    box3.color = PINK;
    objects.push_back(box3);

    PhysicsObject wall;
    wall.position = {0,0};
    wall.width = 50;
    wall.height = screen_height;
    wall.velocity = {0,0};
    wall.acceleration = {0,0};
    wall.name = "wall";
    wall.color = BLACK;
    objects.push_back(wall);

    PhysicsObject ground;
    ground.position = {0,650};   
    ground.width = screen_width;
    ground.height = 50;
    ground.velocity = {0,0};
    ground.acceleration = {0,0};
    ground.name = "ground";
    ground.color = BLACK;
    objects.push_back(ground);

    InitWindow(screen_width,screen_height,"engine");
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        const float dt = GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);

        for (int i = 0; i < objects.size(); i++) 
        {

            for (int j = 0; j < objects.size(); j++)
            {
                if (i == j) continue;
                PhysicsSystem::update(objects[i],objects[j], dt);

                PhysicsSystem::collisionres(objects[i], objects[j]);
                
            }

            // draw everyone
            draw(objects[i]);
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}   