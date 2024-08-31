#include <SDL2/SDL.h>
#include "rect.hpp"
#include <vector>
#include <cassert>
#include <iostream>
#include <AccCtrl.h>

//
//void delete_elem(std::vector<Rect>& obj, Rect& elem) {
//    assert(!obj.empty());
//    assert(&obj.front() <= &elem);
//    assert(&elem <= &obj.back());
//    auto idx = &elem - &obj.front();
//    std::swap(obj[idx], obj.back());
//    obj.resize(obj.size() - 1);
//    std::cout << "deleted object with " << idx << "index" << std::endl;
//}
/*
void borders_deletion(Rect) {
    
}
*/

void delete_elements(std::vector<Rect>& objects) {
    auto deleted = std::remove_if(objects.begin(), objects.end(), [&](Rect& curr_rect) {return curr_rect.m_edge_len == 0; });
    objects.erase(deleted, objects.end());
}

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

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    std::vector<Rect> fireballs;

    
    Rect beginner(640,200,10,100,10);



    fireballs.push_back(beginner);




    while (true) {
        for (int i = 0; i < fireballs.size(); i++) {
            fireballs[i].m_x_cord += fireballs[i].m_x_speed;
            fireballs[i].m_y_cord += fireballs[i].m_y_speed;
            int prev_y_speed = fireballs[i].m_y_speed;
            fireballs[i].m_y_speed -= 1;
            
            if (prev_y_speed > 0 && fireballs[i].m_y_speed < 0) {
                explosion(fireballs[i], fireballs);
            }
            
        }
        delete_elements(fireballs);
        
        SDL_SetRenderDrawColor(renderer, 25, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int iter = 0; iter < fireballs.size(); iter++) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            fireballs[iter].draw_r(renderer);
        }
        SDL_RenderPresent(renderer);

        SDL_Event e;
        while (SDL_PollEvent(&e) > 0)
        {
            switch (e.type)
            {
            case SDL_QUIT:
                SDL_DestroyWindow(window);
                return 0;
            }
          
            //SDL_UpdateWindowSurface(window);
        }  
        SDL_Delay(500);
    }
    return 0;

}

    