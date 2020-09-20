#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "RenderWindow.hpp"
#include "Entity.hpp"

int main(int argsc, char* args[]) {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0 ) {
        printf("SDL failed to init: %s\n", SDL_GetError());
    }
    if (!(IMG_Init(IMG_INIT_PNG))) {
        printf("Img_Init failed to init: %s\n", SDL_GetError());
    }

    RenderWindow window("Game v1.0", 1280, 720);

    SDL_Texture* grassTexture = window.loadTexture("res/gfx/ground_grass_1.png");

    Entity platform0(100, 50, grassTexture);

    bool gameRunning = true;

    SDL_Event event;

    while (gameRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                gameRunning = false;
            }
        }

        window.clear();
        window.render(platform0);
        window.display();
    }

    window.cleanUp();
    SDL_Quit();
    
    return 0;
}