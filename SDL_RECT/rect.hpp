#pragma once
#include <SDL2/SDL.h>
#include <vector>
#include <cmath>

class Rect {
public:
    Rect(int x_cord, int y_cord, int x_speed, int y_speed): m_x_cord(x_cord), m_y_cord(y_cord), m_x_speed(x_speed), m_y_speed(y_speed) {}
    SDL_Rect position;
    int m_x_cord = 0;
    int m_y_cord = 0;
    int m_x_speed = 5;
    int m_y_speed = 100;
    void draw_r(SDL_Renderer* renderer, SDL_Rect& position);
    void change_position(int x, int y, int x_speed, int y_speed);
    void explosion(Rect curr_rect,std::vector<Rect> *objects);
};
