#include <SDL.h>
#include "map.hpp"

const int SCALE = 2;

const int GRID_COLS = 100; 
const int GRID_ROWS = 70; 
const int WINDOW_WIDTH = 800;
const int CELL_SIZE = WINDOW_WIDTH / GRID_COLS;  // = 8
const int WINDOW_HEIGHT = GRID_ROWS * CELL_SIZE;  // = 70 * 8 = 560
 

int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Event e;
    SDL_Init(SDL_INIT_EVERYTHING);
    bool running = true;

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH*SCALE, WINDOW_HEIGHT*SCALE, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, SCALE, SCALE);

    // Create map object
    Map map(GRID_ROWS, GRID_COLS, CELL_SIZE);
    map.createEmptyMap();

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    
    while(running) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }
        // Clear render:
        SDL_RenderClear(renderer);
        
        // Render map:
        map.render(renderer);

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    return 0;
}