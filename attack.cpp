#include"attack.h"

void ATTACK_VOID(SDL_Texture* bullet_png,SDL_Texture* burst_png, meteorite_struct METEORITE[] , bullet_struct BULLET[], ship_struct &SHIP , Mix_Chunk * bang_wav , int &point, SDL_Renderer* renderer)
{
    for(int i = 0 ; i < AMMO ; i ++)
    {
        if(BULLET[i].SHOW)
        {
            if(BULLET[i].DISTANCE == 0)
            {
                BULLET[i].X = SHIP.X+SHIP_BODY_WIDTH/2;
                BULLET[i].Y = SHIP.Y;
            }
            BULLET[i].DISTANCE = BULLET[i].DISTANCE + 5;
            if(BULLET[i].Y - BULLET[i].DISTANCE <= 0)
            {
                BULLET[i].SHOW = false;
                BULLET[i].DISTANCE = 0;
                break;
            }
            SDL_Rect BULLET_RECT = { BULLET[i].X , BULLET[i].Y - BULLET[i].DISTANCE - 10 , BULLET_WIDTH , BULLET_HEIGHT };
            SDL_RenderCopy(renderer , bullet_png, NULL , &BULLET_RECT);
            for(int j = 0; j < QUANTITY; j++)
            {
                if(METEORITE[j].SHOW)
                {
                    SDL_Rect METEORITE_RECT = { METEORITE[j].X, METEORITE[j].Y, METEORITE[j].SIZE, METEORITE[j].SIZE };
                    if(SDL_HasIntersection(&BULLET_RECT, &METEORITE_RECT))
                    {
                        point=point +100;
                        METEORITE[j].BURST--;
                        METEORITE[j].VECTOR_Y=0;
                        play(bang_wav);
                        BULLET[i].SHOW = false;
                        BULLET[i].DISTANCE = 0;
                        SDL_Rect BRUSTRECT = { METEORITE[j].X, METEORITE[j].Y, METEORITE[j].SIZE, METEORITE[j].SIZE };
                        SDL_RenderCopy(renderer , burst_png, NULL , &BRUSTRECT);
                        break;
                    }
                    if(BULLET[i].Y <0)
                    {
                        BULLET[i].SHOW = false;
                        BULLET[i].DISTANCE = 0;
                    }
                }
            }
        }
    }
}
