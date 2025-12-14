#include "map.hpp"
#include <SDL.h>
#include <SDL_image.h>


Map::Map(int rows, int cols, int cellSize) 
    : rows(rows), cols(cols), cellSize(cellSize) {
    // Allocate 2D array
    grid = new int*[rows];
    for(int i = 0; i < rows; i++) {
        grid[i] = new int[cols];
    }
}

Map::~Map() {
    // Free memory
    for(int i = 0; i < rows; i++) {
        delete[] grid[i];
    }
    delete[] grid;
}

void Map::createEmptyMap() {
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            if(row == 0 || row == rows-1 || col == 0 || col == cols-1) {
                grid[row][col] = 1;
            } else {
                grid[row][col] = 0;
            }
        }
    }
}

void Map::loadFromImage(const char* filename){
    SDL_Surface* surface = IMG_Load(filename);
    if(!surface){
        return;
    }

    SDL_LockSurface(surface);

    
    for(int y = 0; y < surface->h; y++){
        for(int x = 0; x < surface->w; x++){
            Uint32* pixels = (Uint32*)surface->pixels;
            Uint32 pixel = pixels[y * surface->w + x];   // Calculate 1D array index
            
        }
    }
    

    SDL_UnlockSurface(surface);
    
    // Clean up
    SDL_FreeSurface(surface);
}

bool Map::isOccupied(int row, int col) const {
    if(row < 0 || row >= rows || col < 0 || col >= cols) {
        return true;  // out of bounds = occupied
    }
    return grid[row][col] == 1;
}

void Map::render(SDL_Renderer* renderer){
    // Render the map
    for(int row = 0; row < rows; row++) {
        for(int col = 0; col < cols; col++) {
            SDL_Rect cell;
            cell.x = col * cellSize;
            cell.y = row * cellSize;
            cell.w = cellSize;
            cell.h = cellSize;

            if (grid[row][col] == 1) {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
            } else {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            }
            SDL_RenderFillRect(renderer, &cell);
        }
    }
}