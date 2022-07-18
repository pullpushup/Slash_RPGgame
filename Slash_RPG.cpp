#include "raylib.h"
#include "raymath.h"
int main()
{
    //Window Dimensions
    const int windowWidth{720};
    const int windowHeight(720);
    InitWindow(windowWidth,windowHeight,"Slash The RPG Game");

    Texture2D map = LoadTexture("WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    float speed{4.0}; 

    Texture2D Player = LoadTexture("characters/knight_idle_spritesheet.png");
    Vector2 PlayerPos{
         (float)windowWidth/2.0f - 4.0f * (0.5f * (float)Player.width/6.0f),
         (float)windowHeight/2.0f - (0.5f * (float)Player.height)
    };

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        
        Vector2 direction{};
        if(IsKeyDown(KEY_A)) direction.x -= 1.0;
        if(IsKeyDown(KEY_D)) direction.x += 1.0;
        if(IsKeyDown(KEY_W)) direction.y -= 1.0;
        if(IsKeyDown(KEY_S)) direction.y += 1.0;
        if(Vector2Length(direction) != 0.0)
        {
            //set mapPos = mapPose - direction "noted here"
           
            mapPos = Vector2Subtract(mapPos,Vector2Scale( Vector2Normalize(direction), speed));
        }
        
        // draw a map here
        DrawTextureEx(map, mapPos, 0.0, 3.0, WHITE);
     
        //draw the character
        Rectangle source{0.f, 0.f, (float)Player.width/6.f, (float)Player.height};
        Rectangle dest{PlayerPos.x, PlayerPos.y, 4.0f * Player.width/6.0f, 4.0f * (float)Player.height};
        DrawTexturePro(Player, source, dest, Vector2{}, 0.f, WHITE);
        EndDrawing();
    }
    CloseWindow();
    
}