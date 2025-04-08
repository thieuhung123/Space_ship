#include"Header.h"
#include"declare.h"
#include"initialize.h"
#include"control.h"
#include"play.h"
#include"check.h"
#include"attack.h"
#include"ship.h"
#include"meteorite.h"

int main(int argc, char *argv[])
{
    init();
    SDL_Window* window = initSDL(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOWTITLE);
    SDL_Renderer* renderer = createRenderer(window);
    bool quit=false;
    bool prepare=true;
    Mix_Music * music_space_mp3 = loadMusic("music_space.mp3");
    play(music_space_mp3);
    while(prepare)
    {
        SDL_Texture* screenpng = loadTexture("screen.png" , renderer);
        system("cls");
        while(prepare)
        {
            SDL_RenderClear( renderer  );
            SDL_RenderCopy( renderer, screenpng , NULL, NULL);
            PLAY_VOID(prepare);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
    }
    while(!quit)
    {
        bool game_over = false;
        bool restart=false;
        int point=0;
        int order = 0 ;
        ship_struct SHIP = {SCREEN_WIDTH / 2, SHIP_Y};
        bullet_struct BULLET[AMMO] = {};
        meteorite_struct METEORITE[QUANTITY] = {};
        for(int i = 0 ; i < QUANTITY ; i++)
        {
            METEORITE[i].BURST = TIME_BURST;
            METEORITE[i].Y = -30;
        }
        Mix_Chunk * bang_wav = loadSound("bang.wav");
        Mix_Chunk * noise_gun_wav = loadSound("noise_gun.wav");
        SDL_Texture* meteorite_png = loadTexture("meteorite.png" , renderer);
        SDL_Texture* space_ship_head_png = loadTexture("space_ship_head.png" , renderer);
        SDL_Texture* space_ship_body_png = loadTexture("space_ship_body_1.png", renderer);
        SDL_Texture* space_ship_body_1_png =  loadTexture("space_ship_body_1.png", renderer);
        SDL_Texture* space_ship_body_2_png =  loadTexture("space_ship_body_2.png", renderer);
        SDL_Texture* bullet_png = loadTexture( "bullet.png" , renderer);
        SDL_Texture* burst_png = loadTexture( "burst.png" , renderer);
        SDL_Texture* galaxy_png = loadTexture("galaxy.png" , renderer);
        SDL_Texture* game_over_png = loadTexture( "game_over.png" , renderer);
        system("cls");
        int time_body = BODY_TIME;
        bool body=false;
        SDL_ShowCursor(SDL_DISABLE);
        while(!game_over)
        {
            if(body == true && time_body <= 0)
            {
                space_ship_body_png = space_ship_body_1_png;
                body = false;
                time_body = BODY_TIME;
            }
            if(body == false && time_body <= 0)
            {
                space_ship_body_png = space_ship_body_2_png;
                body = true;
                time_body = BODY_TIME;
            }
            time_body = time_body - 1;
            point++;
            SDL_RenderClear( renderer  );
            SDL_RenderCopy( renderer, galaxy_png , NULL, NULL);
            CONTROL_VOID( BULLET , SHIP , noise_gun_wav , game_over , order );
            ATTACK_VOID( bullet_png , burst_png ,METEORITE, BULLET , SHIP , bang_wav , point , renderer);
            SHIP_VOID( space_ship_head_png , space_ship_body_png , SHIP  , renderer );
            METEORITE_VOID( meteorite_png , burst_png , METEORITE , SHIP , game_over , renderer );
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
        cout<<point/100;
        SDL_ShowCursor(SDL_ENABLE);
        while(!restart&&!quit)
        {
            SDL_RenderClear(renderer);
            CHECK_VOID(quit,restart);
            SDL_RenderCopy( renderer, game_over_png, NULL, NULL);
            SDL_RenderPresent(renderer);
            SDL_Delay(10);
        }
        if ( bang_wav != nullptr ) Mix_FreeChunk( bang_wav );
        if ( noise_gun_wav != nullptr ) Mix_FreeChunk( noise_gun_wav );
    }
    quitSDL(window, renderer);
    return 0;
}
