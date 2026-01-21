#pragma once
enum class TileType
{
    Grass = 0,
    Forest = 1,
    Hill = 2,
    Mountain = 3,
    Water = 4,
    Tree = 5,    // Go
    Stone = 6,   // Đa
    Sand = 7,    // Cat
    Coal = 8,    // Than
    Iron = 9,    // Sat
    Gold = 10,    // Vang
    Diamond = 11, // Kim cuong
    Emerald = 12, // Ngoc luc bao

};

class Tile
{
private:
    // ====== Cac thuoc tinh logic cua tile ======
    TileType type;
    bool walkable; // Co di qua duoc khong
    int cost;      // Chi phi di chuyen (Dung ho A*)

    // ====== Thuoc tinh Render ======
    int tileSetIndex; // vi tri cua tile nay trong anh tileset lon
    // Ham thay doi trang thai cua Tile
    void setupTile(TileType);

public:
    Tile(TileType);
    Tile() = default;
    ~Tile() = default;
    // Các hàm để lấy thông tin (getter)
    bool isWalkable() const; 
    int getCost() const;
    TileType getType() const;
    int getTilesetIndex() const; 

    // Ham thay doi trang thai cua dia hinh
    void setType(TileType);
};
