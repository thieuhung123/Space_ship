#include"meteorite.h"

void CHECK_COLLIDE_VOID(meteorite_struct METEORITE[],int i)
{
    for(int j = 0 ; j < QUANTITY ; j++)
    {
        if(i == j || METEORITE[j].SHOW == false)
        {
            continue;
        }
        SDL_Rect METEORITERECT_1_RECT = {  METEORITE[i].X , METEORITE[i].Y , METEORITE[i].SIZE , METEORITE[i].SIZE };
        SDL_Rect METEORITERECT_2_RECT = {  METEORITE[j].X , METEORITE[j].Y , METEORITE[j].SIZE , METEORITE[j].SIZE };
        if( SDL_HasIntersection(&METEORITERECT_1_RECT , &METEORITERECT_2_RECT) )
        {
            METEORITE[i].SHOW = false;
            METEORITE[i].VECTOR_Y = 0;
            break;
        }
        int time_X , time_after_X , time_before_X ;
        int time_Y , time_after_Y , time_before_Y ;
        if(METEORITE[i].VECTOR_X == METEORITE[j].VECTOR_X)
        {
            time_X = 0;
            time_after_X = 0;
            time_before_X = 1000000;
        }
        else
        {
            time_X = ( METEORITE[i].X - METEORITE[j].X ) / ( METEORITE[j].VECTOR_X - METEORITE[i].VECTOR_X );
            int VECTOR = abs( METEORITE[i].VECTOR_X - METEORITE[j].VECTOR_X );
            if(METEORITE[i].X < METEORITE[j].X)
            {
                time_after_X = time_X - ( ( METEORITE[i].SIZE + METEORITE[j].SIZE ) / VECTOR + 1 );
                time_before_X = time_X + ( ( METEORITE[i].SIZE + METEORITE[j].SIZE )  / VECTOR + 1 );
            }
            else
            {
                time_after_X = time_X - ( ( METEORITE[i].SIZE + METEORITE[j].SIZE )  / VECTOR + 1 ) ;
                time_before_X = time_X + ( ( METEORITE[i].SIZE + METEORITE[j].SIZE ) / VECTOR  + 1 ) ;
            }
        }
        if(METEORITE[i].VECTOR_Y == METEORITE[j].VECTOR_Y)
        {
            time_Y = 0;
            time_after_Y = 0;
            time_before_Y = 1000000;
        }
        else
        {
            time_Y = ( METEORITE[i].Y - METEORITE[j].Y ) / ( METEORITE[j].VECTOR_Y - METEORITE[i].VECTOR_Y );
            int VECTOR = abs( METEORITE[i].VECTOR_Y - METEORITE[j].VECTOR_Y );
            if(METEORITE[i].Y < METEORITE[j].Y)
            {
                time_after_Y = time_Y - ( ( METEORITE[i].SIZE + METEORITE[j].SIZE ) / VECTOR + 1 ) ;
                time_before_Y = time_Y + ( ( METEORITE[i].SIZE + METEORITE[j].SIZE ) / VECTOR + 1 ) ;
            }
            else
            {
                time_after_Y = time_Y - ( ( METEORITE[i].SIZE + METEORITE[j].SIZE )  / VECTOR + 1 ) ;
                time_before_Y = time_Y + ( ( METEORITE[i].SIZE + METEORITE[j].SIZE )  / VECTOR  + 1 ) ;
            }
        }
        if(time_after_X >= time_after_Y && time_after_X <= time_before_Y )
        {
            METEORITE[i].SHOW = false;
            METEORITE[i].VECTOR_Y = 0;
            break;
        }
        if(time_after_Y >= time_after_X && time_after_Y <= time_before_X )
        {
            METEORITE[i].SHOW = false;
            METEORITE[i].VECTOR_Y = 0;
            break;
        }
        if(time_before_X >= time_after_Y && time_before_X <= time_before_Y )
        {
            METEORITE[i].SHOW = false;
            METEORITE[i].VECTOR_Y = 0;
            break;
        }
        if(time_before_Y >= time_after_X && time_before_Y <= time_before_X )
        {
            METEORITE[i].SHOW = false;
            METEORITE[i].VECTOR_Y = 0;
            break;
        }
    }
}

void METEORITE_VOID(SDL_Texture* meteorite_png ,SDL_Texture* burst_png , meteorite_struct METEORITE[] ,ship_struct SHIP , bool &game_over, SDL_Renderer* renderer)
{
    srand(time(0));
    for(int i = 0 ; i < QUANTITY ; i++)
    {
        int RAND = rand() % DENSITY;
        if(RAND == 0) METEORITE[i].SHOW = true;
        if(METEORITE[i].SHOW)
        {
            if(METEORITE[i].BURST == TIME_BURST)
            {
                if(METEORITE[i].VECTOR_Y == 0)
                {
                    METEORITE[i].VECTOR_X = rand() % 7 - 3;
                    METEORITE[i].VECTOR_Y = rand()% 5 + 5 ;
                    METEORITE[i].X = rand() % SCREEN_WIDTH;
                    METEORITE[i].Y = -30;
                    METEORITE[i].SIZE = rand() % 50 + 20;
                    METEORITE[i].BURST = TIME_BURST;
                    CHECK_COLLIDE_VOID( METEORITE , i);
                }
                if(!METEORITE[i].SHOW )continue;
                METEORITE[i].X = METEORITE[i].X + METEORITE[i].VECTOR_X;
                METEORITE[i].Y = METEORITE[i].Y + METEORITE[i].VECTOR_Y;
                SDL_Rect METEORITE_RECT = {  METEORITE[i].X , METEORITE[i].Y , METEORITE[i].SIZE , METEORITE[i].SIZE };
                SDL_Rect SHIP_HEAD_RECT = {  SHIP.X + 19 , SHIP.Y - 10 , SHIP_HEAD_WIDTH , SHIP_HEAD_HEIGHT };
                SDL_Rect SHIP_BODY_RECT = {  SHIP.X , SHIP.Y + 10 , SHIP_BODY_WIDTH , SHIP_BODY_HEIGHT };
                if(METEORITE[i].Y > SCREEN_HEIGHT || METEORITE[i].X > SCREEN_WIDTH || METEORITE[i].X < -METEORITE[i].SIZE)
                {
                    METEORITE[i].SHOW = false;
                    METEORITE[i].VECTOR_Y = 0;
                }
                SDL_RenderCopy(renderer , meteorite_png, NULL , &METEORITE_RECT);
                if(SDL_HasIntersection(&SHIP_HEAD_RECT , &METEORITE_RECT) || SDL_HasIntersection(&SHIP_BODY_RECT , &METEORITE_RECT))
                {
                    game_over = true;
                    break;
                }
            }
            else
            {
                if(METEORITE[i].BURST <= 0)
                {
                    METEORITE[i].SHOW = false;
                    METEORITE[i].BURST = TIME_BURST;
                    METEORITE[i].Y = 0;
                }
                else
                {
                    METEORITE[i].BURST--;
                    SDL_Rect BRUST_RECT = { METEORITE[i].X, METEORITE[i].Y, METEORITE[i].SIZE, METEORITE[i].SIZE };
                    SDL_RenderCopy(renderer , burst_png, NULL , &BRUST_RECT);
                }
            }
        }
    }
}
