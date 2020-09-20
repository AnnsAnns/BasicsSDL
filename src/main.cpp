#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argsc, char* args[]) {
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 720;

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
        printf("SDL failed to init: %s\n", SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG))) {
        printf("Img_Init failed to init: %s\n", SDL_GetError());
    }

    RenderWindow window("Game v1.0", SCREEN_WIDTH, SCREEN_HEIGHT);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");
    SDL_Texture* spriteTexture = window.loadTexture("res/gfx/tileset.png");

    std::vector<Entity> entities = {Entity(Vector2f(0, 0), grassTexture)};
    
    {
    Entity wilson(Vector2f(100, 50), grassTexture);
    entities.push_back(wilson);
    }

    Entity sprite(Vector2f(150, 70), spriteTexture);

    bool gameRunning = true;

    SDL_Event event;

    int iW = 100, iH = 100;
    int x = SCREEN_WIDTH / 2 - iW / 2;
    int y = SCREEN_HEIGHT / 2 - iH / 2;

    //Setup the clips for our image
    SDL_Rect clips[4];
    for (int i = 0; i < 4; ++i){
        clips[i].x = i / 2 * iW;
        clips[i].y = i % 2 * iH;
        clips[i].w = iW;
        clips[i].h = iH;
    }

    int useClip = 0;

    while (gameRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
            }

            if (event.type == SDL_KEYDOWN){
                switch (event.key.keysym.sym){
                    case SDLK_1:
                        useClip = 0;
                        break;
                    case SDLK_2:
                        useClip = 1;
                        break;
                    case SDLK_3:
                        useClip = 2;
                        break;
                    case SDLK_4:
                        useClip = 3;
                        break;
                    case SDLK_ESCAPE:
                        gameRunning = false;
                        break;
                    default:
                        break;
                }
            }
        }

        window.clear();

        for (Entity& e : entities) {
            window.render(e);
        }

        sprite.setCurrentFrame(&clips[useClip]);

        window.render(sprite);

        window.display();
    }

    window.cleanUp();
    SDL_Quit();
    
    return 0;
}