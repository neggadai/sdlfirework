#include "rect.hpp"

void Rect::change_position(int x, int y, int x_speed, int y_speed) {
    x += x_speed;
    y += y_speed;
}

void Rect::draw_r(SDL_Renderer* renderer, SDL_Rect& position) {
    SDL_RenderFillRect(renderer, &position);
    SDL_RenderPresent(renderer);
}

void Rect::explosion(Rect curr_rect,std::vector<Rect>* objects) {
    int chp = 4;
    int explode_rad = 10;
    double angle = 360 / chp;
    for (int i = 0; i < chp; i++) {
        double rad_angle = M_PI/180*angle;
        Rect inst(curr_rect.);
        insr

    }
}