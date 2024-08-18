#include <SDL2/SDL.h>
#include "rect.hpp"
#include <vector>
#include <cassert>

void delete_elem(std::vector<Rect>& obj, Rect& elem) {
    assert(!obj.empty());
    assert(&obj.front() <= &elem);
    assert(&elem <= &obj.back());
    auto idx = &elem - &obj.front();
    std::swap(obj[idx], obj.back());
    obj.resize(obj.size() - 1);
}
/*
void borders_deletion(Rect) {
    
}
*/

void explosion(Rect curr_rect, std::vector<Rect>& objects) {
    int chp = 4;
     
    int explode_rad = 10;
    double angle = 360 / chp;
    for (int i = 0; i < chp; i++) {
        double rad_angle = M_PI / 180 * angle;
        Rect inst(curr_rect.m_x_cord, curr_rect.m_y_cord, curr_rect.m_x_speed + (cos((rad_angle) * (i)) * explode_rad), curr_rect.m_y_speed, curr_rect.m_edge_len-1);
        objects.push_back(inst);
    }
}

int main(int, char* []) {
    SDL_Window* window = SDL_CreateWindow("Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        1280,
        600,
        SDL_WINDOW_SHOWN);

    // Setup renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    std::vector<Rect> fireballs;
    // Set render color to red
    SDL_SetRenderDrawColor(renderer, 25, 0, 0, 255);

    // Clear window
    SDL_RenderClear(renderer);

    Rect beginner(640,200,10,100,10);
    Rect second(320, 200, 10, 100, 20);

    fireballs.push_back(beginner);


    
    while(true){
        for ( Rect& rect : fireballs) {
            rect.m_x_cord += rect.m_x_speed;
            rect.m_y_cord += rect.m_y_speed;
            rect.m_y_speed -= 2;

            if (rect.m_y_speed < 0) {
//                explosion(rect, fireballs);
                delete_elem(fireballs, rect);
            }
        }

//        SDL_SetRenderDrawColor(renderer, 25, 0, 0, 255);
//        SDL_RenderClear(renderer);

        for (int iter = 0; iter < fireballs.size(); iter++) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            fireballs[iter].draw_r(renderer, fireballs[iter].position);
//            SDL_UpdateWindowSurface(window);

        }
    
    
        SDL_Event e;
        while (SDL_PollEvent(&e) > 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                SDL_DestroyWindow(window);
                break;
            }

            SDL_UpdateWindowSurface(window);
        }
        SDL_Delay(50);
    }
    return 0;

}