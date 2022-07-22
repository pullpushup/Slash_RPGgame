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
    const float mapScale{4.0f};

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
        LoadTexture("characters/slime_run_spritesheet.png")
     };
     Enemy monster3{
        Vector2{600.f, 800.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
     Enemy monster4{
        Vector2{1200.f, 1600.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
      Enemy monster5{
            Vector2{1350.f, 1800.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster6{
            Vector2{1750.f, 2500.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster7{
            Vector2{2050.f, 2500.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  
    Enemy monster8{
            Vector2{2100.f, 2700.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  
   Enemy monster9{
        Vector2{2290.f, 2700.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
     Enemy monster10{
        Vector2{2570.f, 2900.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
     Enemy monster11{
        Vector2{2800.f, 3500.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
      Enemy monster12{
            Vector2{2950.f, 2700.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster13{
            Vector2{1750.f, 3000.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster14{
            Vector2{500.f, 2950.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  
        Enemy monster15{
        Vector2{3500.f, 4000.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
     Enemy monster16{
        Vector2{3800.f, 4200.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
      Enemy monster17{
            Vector2{3900.f, 3280.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster18{
            Vector2{4000.f, 5000.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster19{
            Vector2{-2500.f, 5000.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };     Enemy monster20{
        Vector2{-3850.f, -4270.f},
        LoadTexture("characters/slime_idle_spritesheet.png"),
        LoadTexture("characters/slime_run_spritesheet.png")
     };
      Enemy monster21{
            Vector2{3900.f, 5000.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster22{
            Vector2{4280.f, 5580.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };  Enemy monster23{
            Vector2{-2500.f, -4000.f},
            LoadTexture("characters/goblin_idle_spritesheet.png"),
            LoadTexture("characters/goblin_run_spritesheet.png")
   };


     Enemy* enemies[23]{
            &monster,
            &monster2,
            &monster3, &monster4, &monster5, &monster6, &monster7,
            &monster8, 
            &monster9, &monster10,
            &monster11, &monster12, &monster13,
            &monster14, &monster15,&monster16,&monster17,
            &monster18, &monster19, &monster20, &monster21,
            &monster22, &monster23
     };
        for (auto enemy : enemies)
        {
         enemy->setTarget(&player); 
         }
             
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

        mapPos = Vector2Scale(player.getWorldPos(), -1.f);

        // draw a map here
        DrawTextureEx(map, mapPos, 0.0, 4.0, WHITE);


        //draw the props
        for(auto prop : props)
        {
            prop.Render(player.getWorldPos());
            
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