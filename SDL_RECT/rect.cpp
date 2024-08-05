#include "rect.hpp"

void Rect::change_position(int x, int y, int x_speed, int y_speed) {
    x += x_speed;
    y += y_speed;
}

void Rect::draw_r(SDL_Renderer* renderer, SDL_Rect& position) {
    SDL_RenderFillRect(renderer, &position);
    SDL_RenderPresent(renderer);
}
