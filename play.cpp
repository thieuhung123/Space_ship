#include"play.h"

void PLAY_VOID( bool &prepare )
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
                SDL_Rect BUTTON_PLAY_RECT = { 200 , 450 , 230 , 90 };
                if(SDL_HasIntersection(&MOUSE_RECT , &BUTTON_PLAY_RECT))
                {
                    prepare = false;
                    break;
                }
            }
        }
    }
}
