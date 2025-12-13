#include <SDL.h>
#include "map.hpp"

const int SCALE = 2;
const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 500;
const int CELL_SIZE = 10;

const int GRID_COLS = WINDOW_WIDTH / CELL_SIZE;  
const int GRID_ROWS = WINDOW_HEIGHT / CELL_SIZE; 

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

    while(running) {
        while(SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Render the map
        int** grid = map.getGrid();
        for(int row = 0; row < map.getRows(); row++) {
            for(int col = 0; col < map.getCols(); col++) {
                SDL_Rect cell;
                cell.x = col * map.getCellSize();
                cell.y = row * map.getCellSize();
                cell.w = map.getCellSize();
                cell.h = map.getCellSize();

                if (grid[row][col] == 1) {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                } else {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                }
                SDL_RenderFillRect(renderer, &cell);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    return 0;
}