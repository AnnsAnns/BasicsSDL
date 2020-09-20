#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"

Entity::Entity(Vector2f p_pos, SDL_Texture* p_tex) 
:pos(p_pos), tex(p_tex) {
    currentFrame.x = 0;
    currentFrame.y = 0;
    currentFrame.w = 32;
    currentFrame.h = 32;
}

SDL_Texture* Entity::getTex() {
    return tex;
}

SDL_Rect Entity::getCurrentFrame() {
    return currentFrame;
}

void Entity::setCurrentFrame(SDL_Rect *p_rect) {
    currentFrame.x = p_rect->x;
    currentFrame.y = p_rect->y;
    currentFrame.w = p_rect->w;
    currentFrame.h = p_rect->h;
}