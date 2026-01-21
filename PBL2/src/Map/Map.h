#pragma once
#include <SFML/Graphics.hpp>
#include "Tile.h"
#include "EntityManager.h"

class Map {
private:
    int width;
    int height;
    Tile** grid; // mang 2D luu tile

public:
    Map();
    Map(float width, float height);
    ~Map();

    int get_width() const;
    int get_height() const;
    Tile* get_tile(int x, int y) const;
    Tile** get_grid() const { return grid; }
    // int get_tile_id(int x, int y) const;

    bool load_File(const char* filename);
    void saveToFile(const char* filename) const;

    bool isWalkable(int x, int y) const;
};
