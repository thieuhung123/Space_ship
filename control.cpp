#include"control.h"

void CONTROL_VOID( bullet_struct BULLET[] , ship_struct &SHIP , Mix_Chunk * noise_gun_wav , bool &game_over  , int &order)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_MOUSEMOTION)
        {
            int mouse_x , mouse_y;
            SDL_GetMouseState(&mouse_x , &mouse_y);
            if(mouse_x <= SHIP_BODY_WIDTH/2)
            {
                mouse_x = SHIP_BODY_WIDTH/2;
            }
            if(mouse_x >= SCREEN_WIDTH - SHIP_BODY_WIDTH/2)
            {
                mouse_x = SCREEN_WIDTH - SHIP_BODY_WIDTH/2;
            }
            if(mouse_y <= SHIP_BODY_HEIGHT + SHIP_HEAD_HEIGHT)
            {
                mouse_y = SHIP_BODY_HEIGHT + SHIP_HEAD_HEIGHT;
            }
            if(mouse_y >= SCREEN_HEIGHT - SHIP_BODY_HEIGHT/2)
            {
                mouse_y = SCREEN_HEIGHT - SHIP_BODY_HEIGHT/2;
            }
            SHIP.X = mouse_x - SHIP_BODY_WIDTH / 2;
            SHIP.Y = mouse_y - SHIP_BODY_HEIGHT;
        }
        if(BULLET[order].TIME<=0)
        {
            if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    BULLET[order].SHOW = true;
                    order++;
                    BULLET[order].TIME=BULLET_SPEED;
                    if(order == AMMO)order = 0;
                    play(noise_gun_wav);
                }
                break;
            }
        }
        else
        {
            BULLET[order].TIME--;
        }
    }
}
