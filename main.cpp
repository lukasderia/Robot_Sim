#include <SDL.h>

const int SCALE = 2;
const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

// Primary control - the cell size
const int CELL_SIZE = 10;

// Calculate grid dimensions from window and cell size
const int GRID_COLS = WINDOW_WIDTH / CELL_SIZE;   // 800/5 = 160 columns
const int GRID_ROWS = WINDOW_HEIGHT / CELL_SIZE;  // 600/5 = 120 rows


int main(int argc, char* argv[]) {
    SDL_Window* window = nullptr;
    SDL_Renderer* renderer = nullptr;
    SDL_Event e;
    SDL_Init(SDL_INIT_EVERYTHING);
    bool running = true;

    SDL_CreateWindowAndRenderer(WINDOW_WIDTH*SCALE, WINDOW_HEIGHT*SCALE, 0, &window, &renderer);
    SDL_RenderSetScale(renderer, SCALE, SCALE);

    // Store the grid state: 0 = free (white), 1 = obstacle (black)
    int grid[GRID_ROWS][GRID_COLS] = {0};  // Initialize all to 0

    // Set some obstacles manually
    grid[2][3] = 1;  // Cell at row 2, col 3 is an obstacle
    grid[4][5] = 1;  // Cell at row 4, col 5 is an obstacle
    
    while(running)
    {
        while(SDL_PollEvent(&e)) {if (e.type == SDL_QUIT) {running = false;}}

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);

        for(int row=0; row<GRID_ROWS; row++){
            for(int col=0; col<GRID_COLS; col++){
                SDL_Rect cell;
                cell.x = col * CELL_SIZE;
                cell.y = row * CELL_SIZE;
                cell.w = CELL_SIZE;
                cell.h = CELL_SIZE;

                // Choose color based on grid state
                if (grid[row][col] == 1) {
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Black for obstacles
                    SDL_RenderFillRect(renderer, &cell);  // Fill it
                } else {
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // White for free
                    SDL_RenderFillRect(renderer, &cell);  // Fill it
                }
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(10);
    }

    return 0;
}