#include "prop.h"
#include "raymath.h"

Prop::Prop(Vector2 pos, Texture2D tex) : 
        worldPos(pos),
        texture(tex)
{
}

void Prop::Render(Vector2 playerPos)
{
     Vector2 screenPos{Vector2Subtract(worldPos, playerPos)};
    DrawTextureEx(texture, screenPos, 0.f, scale, WHITE);
}

    Rectangle Prop::getCollisionRec(Vector2 playerPos)
    {
        Vector2 screenPos{ Vector2Subtract(worldPos, playerPos) };
        return Rectangle{
            screenPos.x,
            screenPos.y,
            texture.width * scale,
            texture.height * scale
        };
    }