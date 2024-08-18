#include "rect.hpp"

void Rect::change_position(int x, int y, int x_speed, int y_speed) {
    x += x_speed;
    y += y_speed;
}

void Rect::draw_r(SDL_Renderer* renderer ) {

    SDL_Rect position = { m_x_cord, m_y_cord, m_edge_len, m_edge_len };
    SDL_RenderFillRect(renderer, &position);
}
/*
void Rect::explosion(Rect curr_rect,std::vector<Rect>& objects) {
    int chp = 4;
    int explode_rad = 10;
    double angle = 360 / chp;
    for (int i = 0; i < chp; i++) {
        double rad_angle = M_PI/180*angle;
        Rect inst(curr_rect.m_x_cord, curr_rect.m_y_cord, curr_rect.m_x_speed + (cos((rad_angle) * (i)) * explode_rad), curr_rect.m_y_speed, curr_rect.m_edge_len);
        objects.push_back(inst);

        
    }
}
*/