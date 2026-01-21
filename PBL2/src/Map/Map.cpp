#include "Map.h"
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include "String.h"
#include "EntityManager.h"

Map::Map() : width(0), height(0), grid(nullptr) {}

Map::~Map()
{
    if (grid)
    {
        for (int i = 0; i < height; i++)
            delete[] grid[i];
        delete[] grid;
        grid = nullptr;
    }
}

int Map::get_width() const { return width; }
int Map::get_height() const { return height; }

Tile *Map::get_tile(int x, int y) const
{
    if (!grid || x < 0 || y < 0 || x >= width || y >= height)
        return nullptr;
    return &grid[y][x];
}

bool Map::isWalkable(int x, int y) const
{
    if (!grid || x < 0 || y < 0 || x >= width || y >= height)
        return false;
    return grid[y][x].isWalkable();
}

bool Map::load_File(const char *filename)
{
    // Xóa dữ liệu cũ
    if (grid)
    {
        for (int i = 0; i < height; i++)
            delete[] grid[i];
        delete[] grid;
        grid = nullptr;
    }

    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Khong the mo file ban do: %s\n", filename);
        return false;
    }

    const int MAX_LINE = 10240; // Tăng buffer cho map 500x500
    char line[MAX_LINE];
    int rowCount = 0, colCount = 0;

    printf("Dang doc kich thuoc map...\n");

    // ===== FIX 1: SỬA LOGIC ĐẾM =====
    while (fgets(line, MAX_LINE, file))
    {
        // Bỏ qua dòng trống
        if (line[0] == '\n' || line[0] == '\r' || line[0] == '\0')
            continue;

        int count = 0;
        const char *p = line;
        
        while (*p)
        {
            // Bỏ qua khoảng trắng
            while (*p && isspace((unsigned char)*p))
                p++;
            
            if (*p == '\0' || *p == '\n' || *p == '\r')
                break;

            // Đọc số
            char *end;
            strtol(p, &end, 10);
            
            // Nếu không đọc được số, dừng
            if (end == p)
                break;
            
            count++;
            p = end;  // ✅ FIX: Di chuyển con trỏ tới vị trí sau số vừa đọc
        }

        if (count > 0)
        {
            rowCount++;
            if (count > colCount)
                colCount = count;
        }
    }

    this->width = colCount;
    this->height = rowCount;

    printf("Kich thuoc map: %d x %d\n", width, height);

    // Kiểm tra kích thước hợp lệ
    if (width == 0 || height == 0)
    {
        printf("Loi: Khong the doc kich thuoc map tu file %s\n", filename);
        fclose(file);
        return false;
    }

    if (width > 1000 || height > 1000)
    {
        printf("Canh bao: Map qua lon (%dx%d). Co the gay crash!\n", width, height);
    }

    // Cấp phát mảng động 2 chiều
    printf("Dang cap phat bo nho cho map...\n");
    grid = new Tile *[height];
    for (int i = 0; i < height; i++)
        grid[i] = new Tile[width];

    // Quay lại đầu file để đọc dữ liệu thực
    fseek(file, 0, SEEK_SET);
    
    printf("Dang doc du lieu map...\n");
    int y = 0;
    while (y < height && fgets(line, MAX_LINE, file))
    {
        // Bỏ qua dòng trống
        if (line[0] == '\n' || line[0] == '\r' || line[0] == '\0')
            continue;

        int x = 0;
        const char *p = line;
        
        while (*p && x < width)
        {
            // Bỏ qua khoảng trắng
            while (*p && isspace((unsigned char)*p))
                p++;
            
            if (*p == '\0' || *p == '\n' || *p == '\r')
                break;

            // Đọc số
            char *end;
            long val = strtol(p, &end, 10);
            
            if (end == p)
                break;

            grid[y][x].setType(static_cast<TileType>(val));
            x++;
            p = end;
        }

        if (x < width)
        {
            printf("WARNING: hang %d chi co %d tile (thieu %d tile)\n",
                   y + 1, x, width - x);
        }
        
        y++;
        
        // Progress indicator cho map lớn
        if (y % 100 == 0)
            printf("  Da doc %d/%d hang...\n", y, height);
    }

    fclose(file);
    printf("Tai map thanh cong (%d x %d)\n", width, height);
    return true;
}

void Map::saveToFile(const char *filename) const
{
    FILE *file = fopen(filename, "w");
    if (!file)
    {
        printf("Khong the luu file map: %s\n", filename);
        return;
    }

    printf("Dang luu map...\n");
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            fprintf(file, "%d", (int)grid[y][x].getType());
            if (x < width - 1)
                fprintf(file, " ");
        }
        fprintf(file, "\n");
        
        if ((y + 1) % 100 == 0)
            printf("  Da luu %d/%d hang...\n", y + 1, height);
    }

    fclose(file);
    printf("Da luu map vao %s\n", filename);
}