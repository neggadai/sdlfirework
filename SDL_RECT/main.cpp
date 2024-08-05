#include <SDL2/SDL.h>
#include "rect.hpp"

int main(int, char* []) {
    SDL_Window* window = SDL_CreateWindow("Jeu de la vie", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640,
        480,
        SDL_WINDOW_SHOWN);

    // Setup renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Set render color to red
    SDL_SetRenderDrawColor(renderer, 25, 0, 0, 255);

    // Clear window
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    Rect r;
    r.position.x = 10;
    r.position.y = 20;
    r.position.h = 30;
    r.position.w = 40;

    // Draw rect
    r.draw_r(renderer, r.position);

    bool keep_window_open = true;
    while (keep_window_open) {
        while (SDL_PollEvent()
        {

        }
    }
    return 0;
}
