#include"Header.h"
#include"declare.h"

void logErrorAndExit(const char* msg, const char* error);
void init() ;
SDL_Window* initSDL(int SCREEN_WIDTH, int SCREEN_HEIGHT, const char* WINDOW_TITLE);
SDL_Texture *loadTexture(const char *filename, SDL_Renderer* renderer);
SDL_Renderer* createRenderer(SDL_Window* window);
Mix_Music *loadMusic(const char* path);
void play(Mix_Music *gMusic);
Mix_Chunk* loadSound(const char* path);
void play(Mix_Chunk* gChunk);
void quitSDL(SDL_Window* window, SDL_Renderer* renderer);
