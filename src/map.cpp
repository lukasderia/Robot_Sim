#include "map.hpp"

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

bool Map::isOccupied(int row, int col) const {
    if(row < 0 || row >= rows || col < 0 || col >= cols) {
        return true;  // out of bounds = occupied
    }
    return grid[row][col] == 1;
}