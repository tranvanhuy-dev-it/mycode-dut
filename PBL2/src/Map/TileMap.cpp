#include "TileMap.h"
#include <iostream>
#include <cmath>

TileMap::TileMap()
    : map_vertices(sf::Quads), map_textureLoaded(false),
      map_width(0), map_height(0)
{
}

bool TileMap::LoadTileset(const std::string &tilesetPath, sf::Vector2u tileSize)
{
    if (!map_tileSetTexture.loadFromFile(tilesetPath))
    {
        cout << "Khong the tai hinh anh: " << tilesetPath << endl;
        map_textureLoaded = false;
        return false;
    }
    map_tileSetTexture.setRepeated(false);
    map_textureLoaded = true;
    map_tileSize = tileSize;

    cout << "Da tai tileset thanh cong: " << tilesetPath << endl;
    return true;
}

void TileMap::buildMap(const Map &Map)
{
    map_width = Map.get_width();
    map_height = Map.get_height();
    
    if (map_width == 0 || map_height == 0)
    {
        cout << "Loi: Khong doc duoc ban do (kich thuoc = 0)" << endl;
        return;
    }

    cout << "Dang xay dung TileMap (" << map_width << "x" << map_height << ")..." << endl;

    // Tính số tile cần vẽ
    size_t totalTiles = static_cast<size_t>(map_width) * static_cast<size_t>(map_height);
    size_t vertexCount = totalTiles * 4;

    cout << "So luong tile: " << totalTiles << endl;
    cout << "So luong vertex: " << vertexCount << endl;

    // Khởi tạo mảng Vertex
    map_vertices.setPrimitiveType(sf::Quads);
    map_vertices.resize(vertexCount);

    // Kiểm tra resize thành công
    if (map_vertices.getVertexCount() != vertexCount)
    {
        std::cerr << "LOI: Khong the cap phat vertex array!" << std::endl;
        std::cerr << "Yeu cau: " << vertexCount << ", thuc te: " << map_vertices.getVertexCount() << std::endl;
        return;
    }

    const auto &grid = Map.get_grid();
    int tilePerRow = map_tileSetTexture.getSize().x / map_tileSize.x;

    cout << "Tile per row trong texture: " << tilePerRow << endl;

    // ===== FIX 2: SỬA TEXTURE COORDS =====
    for (int y = 0; y < map_height; y++)
    {
        for (int x = 0; x < map_width; x++)
        {
            const Tile &tile = grid[y][x];
            int tileIndex = tile.getTilesetIndex();

            int tx = tileIndex % tilePerRow;
            int ty = tileIndex / tilePerRow;

            sf::Vertex *quad = &map_vertices[(x + y * map_width) * 4];

            // ✅ Position (vị trí thực trên màn hình)
            quad[0].position = sf::Vector2f(x * map_tileSize.x, y * map_tileSize.y);              // Top-Left
            quad[1].position = sf::Vector2f((x + 1) * map_tileSize.x, y * map_tileSize.y);        // Top-Right
            quad[2].position = sf::Vector2f((x + 1) * map_tileSize.x, (y + 1) * map_tileSize.y); // Bottom-Right
            quad[3].position = sf::Vector2f(x * map_tileSize.x, (y + 1) * map_tileSize.y);       // Bottom-Left

            // ✅ FIX: Texture Coords phải khớp với thứ tự Position
            quad[0].texCoords = sf::Vector2f(tx * map_tileSize.x, ty * map_tileSize.y);              // Top-Left
            quad[1].texCoords = sf::Vector2f((tx + 1) * map_tileSize.x, ty * map_tileSize.y);        // Top-Right
            quad[2].texCoords = sf::Vector2f((tx + 1) * map_tileSize.x, (ty + 1) * map_tileSize.y); // Bottom-Right
            quad[3].texCoords = sf::Vector2f(tx * map_tileSize.x, (ty + 1) * map_tileSize.y);       // Bottom-Left
        }

        // Progress indicator
        if ((y + 1) % 100 == 0)
            cout << "  Da xay dung " << (y + 1) << "/" << map_height << " hang..." << endl;
    }

    cout << "Xay dung TileMap hoan tat!" << endl;
}

// ===== FIX 3: SỬA HÀM updateTile =====
void TileMap::updateTile(const Map &map, int x, int y)
{
    if (x < 0 || y < 0 || x >= map_width || y >= map_height)
    {
        cout << "Vi tri khong hop le: (" << x << ", " << y << ")\n";
        return;
    }

    const Tile &tile = map.get_grid()[y][x];
    int tilePerRow = map_tileSetTexture.getSize().x / map_tileSize.x;
    int tileIndex = tile.getTilesetIndex();
    int tx = tileIndex % tilePerRow;
    int ty = tileIndex / tilePerRow;

    sf::Vertex *quad = &map_vertices[(x + y * map_width) * 4];

    // ✅ FIX: CHỈ CẬP NHẬT TEXTURE COORDS, KHÔNG ĐỘNG VÀO POSITION!
    quad[0].texCoords = sf::Vector2f(tx * map_tileSize.x, ty * map_tileSize.y);
    quad[1].texCoords = sf::Vector2f((tx + 1) * map_tileSize.x, ty * map_tileSize.y);
    quad[2].texCoords = sf::Vector2f((tx + 1) * map_tileSize.x, (ty + 1) * map_tileSize.y);
    quad[3].texCoords = sf::Vector2f(tx * map_tileSize.x, (ty + 1) * map_tileSize.y);
}

void TileMap::drawVisible(sf::RenderTarget &target, sf::RenderStates state, const sf::View &view) const
{
    if (!map_textureLoaded)
    {
        cout << "Khong the ve: texture chua duoc load\n";
        return;
    }

    state.transform *= getTransform();
    state.texture = &map_tileSetTexture;

    // Lấy vùng nhìn thấy của camera
    sf::FloatRect viewRect(view.getCenter() - view.getSize() / 2.f, view.getSize());

    // Xác định phạm vi tile cần vẽ
    int startX = TileMap::Get_max(0, static_cast<int>(viewRect.left / map_tileSize.x));
    int startY = TileMap::Get_max(0, static_cast<int>(viewRect.top / map_tileSize.y));
    int endX = TileMap::Get_min(map_width, static_cast<int>((viewRect.left + viewRect.width) / map_tileSize.x) + 1);
    int endY = TileMap::Get_min(map_height, static_cast<int>((viewRect.top + viewRect.height) / map_tileSize.y) + 1);

    int w = TileMap::Get_max(0, endX - startX);
    int h = TileMap::Get_max(0, endY - startY);

    if (w == 0 || h == 0)
        return;

    // Tạo vertex array tạm cho vùng visible
    sf::VertexArray visible(sf::Quads);
    visible.resize(static_cast<std::size_t>(w) * static_cast<std::size_t>(h) * 4);

    // Copy các tile trong vùng nhìn
    for (int y = startY; y < endY; ++y)
    {
        for (int x = startX; x < endX; ++x)
        {
            const sf::Vertex *src = &map_vertices[(x + y * map_width) * 4];
            sf::Vertex *dst = &visible[((x - startX) + (y - startY) * w) * 4];
            
            for (int i = 0; i < 4; i++)
                dst[i] = src[i];
        }
    }

    target.draw(visible, state);
}

void TileMap::update(float deltaTime)
{
    // Nếu có animated tiles, update ở đây
}

void TileMap::draw(sf::RenderTarget &target, sf::RenderStates state) const
{
    if (!map_textureLoaded)
    {
        cout << "Khong the ve: texture chua duoc load\n";
        return;
    }
    
    state.transform *= getTransform();
    state.texture = &map_tileSetTexture;
    target.draw(map_vertices, state);
}

bool TileMap::is_TextureLoaded() const
{
    return map_textureLoaded;
}

int TileMap::Get_min(int a, int b)
{
    return (a < b) ? a : b;
}

int TileMap::Get_max(int a, int b)
{
    return (a > b) ? a : b;
}