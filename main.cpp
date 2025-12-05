#include <SDL.h>
#include <iostream>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow(
        "Window Title",           // title
        SDL_WINDOWPOS_CENTERED,   // x position
        SDL_WINDOWPOS_CENTERED,   // y position
        WINDOW_WIDTH,             // width
        WINDOW_HEIGHT,            // height
        SDL_WINDOW_SHOWN          // flags
    );

    // Keep window open (basic event loop)
    bool running = true;
    SDL_Event event;
    
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
    }

    // Cleanup
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}