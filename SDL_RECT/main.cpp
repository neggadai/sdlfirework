#include <SDL2/SDL.h>
#include "rect.hpp"
#include <vector>

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

    Rect beginner(640,200,10,100,50);
    fireballs.push_back(beginner);
    while(true){
        for (int i = 0; i < fireballs.size(); i++) {
            if (fireballs[i].m_y_speed < 0) {
                fireballs[i].explosion(fireballs[i], fireballs);
            }
        }

        SDL_SetRenderDrawColor(renderer, 25, 0, 0, 255);
        SDL_RenderClear(renderer);

        for (int i = 0; i < fireballs.size(); i++) {
            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
            fireballs[i].draw_r(renderer, fireballs[i].position);
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