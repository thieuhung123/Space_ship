#include"ship.h"

void SHIP_VOID( SDL_Texture* space_ship_head_png, SDL_Texture* space_ship_body_png, ship_struct &SHIP , SDL_Renderer* renderer)
{
     SDL_Rect SHIP_HEAD_RECT = {  SHIP.X + 19 , SHIP.Y - 10 , SHIP_HEAD_WIDTH , SHIP_HEAD_HEIGHT };
     SDL_Rect SHIP_BODY_RECT = {  SHIP.X , SHIP.Y + 10 , SHIP_BODY_WIDTH , SHIP_BODY_HEIGHT };
     SDL_RenderCopy(renderer, space_ship_head_png, NULL, &SHIP_HEAD_RECT);
     SDL_RenderCopy(renderer, space_ship_body_png, NULL, &SHIP_BODY_RECT);
}
