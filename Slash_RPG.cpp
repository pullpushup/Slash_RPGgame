#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"

int main()
{
    // Window Dimensions
    const int windowWidth{720};
    const int windowHeight(720);
    InitWindow(windowWidth, windowHeight, "Slash The RPG Game");

    Texture2D map = LoadTexture("WorldMap.png");
    Vector2 mapPos{0.0, 0.0};
    const float mapScale{6.0f};

   Character player{windowWidth, windowHeight};

   Prop rock{Vector2{0.f,0.f},LoadTexture("nature_tileset/Rock.png")}; 
 

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(player.getWorldPos(), -1.f);

        // draw a map here
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);

        rock.Render(player.getWorldPos());

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