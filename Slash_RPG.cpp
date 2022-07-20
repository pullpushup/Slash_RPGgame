/*
This is parent source file of Slash RPG game
*/

#include "raylib.h"
#include "raymath.h"
#include "Character.h"
#include "Prop.h"
#include "Enemy.h"
#include <string>

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


   Prop props[2]{
        Prop{Vector2{600.f,300.f},LoadTexture("nature_tileset/Rock.png")},
        Prop{Vector2{400.f,500.f},LoadTexture("nature_tileset/Log.png")}
   };

   Enemy monster{
            Vector2{800.f, 300.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  
   Enemy monster2{
        Vector2{500.f, 700.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_idle_spritesheet.png")
     };

     Enemy* enemies[2]{
            &monster,
            &monster2
     };
        for (auto enemy : enemies)
        {
         enemy->setTarget(&player); 
         }
            

   monster.setTarget(&player);
            
 
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
            EndDrawing();
            continue;
        }

        if (!player.getAlive()) //player is dead
        {
                DrawText("Game Over!", 55.f, 45.f, 40, RED);
                EndDrawing();
                continue;
        }else //player is alive
        {
            std::string playerHealth = " Health: ";
            playerHealth.append(std::to_string(player.getHealth()), 0, 5);
            DrawText(playerHealth.c_str(), 55.f, 45.f, 40, BLUE);
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
               if (CheckCollisionRecs(prop.getCollisionRec(player.getWorldPos()), player.getCollisionRec()))
               {
                   player.undoMovement();
               }
            }

            
        for (auto enemy : enemies)
        {
            enemy->tick(GetFrameTime());
        }
            
            if(IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                for(auto enemy: enemies)
                {
                if(CheckCollisionRecs(enemy->getCollisionRec(), player.getWeaponCollisionRec()))
                    {
                    enemy->setAlive(false);
                    }
                }
                
            }

        EndDrawing();

    }
    CloseWindow();
}