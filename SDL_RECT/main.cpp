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
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    Rect r;
    r.position.x = 640;
    r.position.y = 960;
    r.position.h = 20;
    r.position.w = 20;

    fireballs.push_back(r);

    r.draw_r(renderer, r.position);
    for (int i = 0; i < 100; i++) {
        r.draw_r(renderer, r.position);
        SDL_SetRenderDrawColor(renderer, 25, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 25, 255, 255);
        r.position.x += r.x_speed;
        r.position.y -= r.y_speed;
        r.y_speed -= 6;




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