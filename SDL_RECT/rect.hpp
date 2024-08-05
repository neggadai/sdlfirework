#pragma once
#include <SDL2/SDL.h>

class Rect {
public:
    SDL_Rect position;
    int x_speed;
    int y_speed;
    void draw_r(SDL_Renderer* renderer, SDL_Rect& position);
    void change_position(int x, int y, int x_speed, int y_speed);
};
