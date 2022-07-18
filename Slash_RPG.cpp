#include "raylib.h"
#include "raymath.h"
#include "Character.h"

int main()
{
    // Window Dimensions
    const int windowWidth{720};
    const int windowHeight(720);
    InitWindow(windowWidth, windowHeight, "Slash The RPG Game");

    Texture2D map = LoadTexture("WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{6.0f};

   Character player;
    player.setScreenPos(windowWidth, windowHeight);

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(player.getWorldPos(), -1.f);

        // draw a map here
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);
        player.tick(GetFrameTime());
        // check map bounds
        if(player.getWorldPos().x < 0.f ||
            player.getWorldPos().y < 0.f ||
            player.getWorldPos().x + windowWidth > map.width * mapScale ||
            player.getWorldPos().y + windowHeight > map.width * mapScale)
            {
                player.undoMovement();
            }

        EndDrawing();

    }
    CloseWindow();
}