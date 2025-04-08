#include"check.h"

void CHECK_VOID( bool &quit , bool &restart)
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_MOUSEBUTTONDOWN)
        {
            int mouse_x, mouse_y;
            SDL_GetMouseState(&mouse_x, &mouse_y);
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                SDL_Rect MOUSE_RECT = { mouse_x, mouse_y , 1 , 1 };
                SDL_Rect BUTTON_QUIT_RECT = { 270 , 360 , 100 , 40 };
                if(SDL_HasIntersection(&MOUSE_RECT , &BUTTON_QUIT_RECT))
                {
                    quit = true;
                    break;
                }
            }
            if (event.button.button == SDL_BUTTON_LEFT)
            {
                SDL_Rect MOUSE_RECT = { mouse_x, mouse_y , 1 , 1 };
                SDL_Rect BUTTON_RESTART_RECT = { 210 , 420 , 210 , 40};
                if(SDL_HasIntersection(&MOUSE_RECT , &BUTTON_RESTART_RECT))
                {
                    restart = true;
                    break;
                }
            }
        }
    }
}
