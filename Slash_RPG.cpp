#include "raylib.h"
int main()
{
    //Window Dimensions
    const int windowWidth{720};
    const int windowHeight(720);
    InitWindow(windowWidth,windowHeight,"Slash The RPG Game");

    Texture2D map = LoadTexture("WorldMap.png");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);
        Vector2 mapPos{0.0, 0.0};
        DrawTextureEx(map, mapPos, 0.0, 3.0, WHITE);

        EndDrawing();
    }
    CloseWindow();
    
}