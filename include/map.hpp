#ifndef MAP_HPP
#define MAP_HPP
#include <SDL.h>

class Map {
    private:
        int rows;
        int cols;
        int cellSize;
        int** grid;  // 2D array stored as pointer


    public:
        Map(int rows, int cols, int cellSize);
        ~Map();  // destructor to clean up memory
        
        void createEmptyMap();
        void loadFromImage(const char* filename);
        bool isOccupied(int row, int col) const;
        int getRows() const { return rows; }
        int getCols() const { return cols; }
        int getCellSize() const { return cellSize; }
        int** getGrid() const { return grid; }
        void render(SDL_Renderer* renderer);
};

#endif