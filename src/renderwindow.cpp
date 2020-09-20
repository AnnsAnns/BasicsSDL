#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>

#include "RenderWindow.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_w, int p_h)
    :window(NULL), renderer(NULL) {
    window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_w, p_h,
        SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Window failed to init: %s\n", SDL_GetError());
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath) {
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, p_filePath);

    if (texture == NULL) {
        printf("Failed to load texture: %s\n", SDL_GetError());
    }

    return texture;
}

void RenderWindow::cleanUp(){
    SDL_DestroyWindow(window);
}

void RenderWindow::clear() {
    SDL_RenderClear(renderer);
}

void RenderWindow::render(SDL_Texture* p_tex) {
    SDL_RenderCopy(renderer, p_tex, NULL, NULL);
}

void RenderWindow::display() {
    SDL_RenderPresent(renderer);
}
