#ifndef MAP_HPP
#define MAP_HPP

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
        bool isOccupied(int row, int col) const;
        int getRows() const { return rows; }
        int getCols() const { return cols; }
        int getCellSize() const { return cellSize; }
        int** getGrid() const { return grid; }
};

#endif