#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"

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

   Prop props[2]{
        Prop{Vector2{600.f,300.f},LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f,500.f},LoadTexture("nature_tileset/Log.png")}
   };

   Enemy monster{
            Vector2{},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };
            
 
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(player.getWorldPos(), -1.f);

        // draw a map here
        DrawTextureEx(map, mapPos, 0.0, mapScale, WHITE);


        //draw the props
        for(auto prop : props)
        {
            prop.Render(player.getWorldPos());
        }

        player.tick(GetFrameTime());
        // check map bounds
        if(player.getWorldPos().x < 0.f ||
            player.getWorldPos().y < 0.f ||
            player.getWorldPos().x + windowWidth > map.width * mapScale ||
            player.getWorldPos().y + windowHeight > map.width * mapScale)
            {
                player.undoMovement();
            }

            // checking a rock and tree prop collisions
            for(auto prop: props)
            {
               if (CheckCollisionRecs(prop.getCollisionRec(player.getWorldPos()), player.GetCollisionRec()))
               {
                   player.undoMovement();
               }
            }

            monster.tick(GetFrameTime());

        EndDrawing();

    }
    CloseWindow();
}