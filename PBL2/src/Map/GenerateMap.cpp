#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

#define MAP_SIZE 500

// Terrain types
enum Terrain {
    Grass = 0,
    Forest = 1,
    Hill = 2,
    Mountain = 3,
    Water = 4,
    Tree = 5,
    Stone = 6,
    Sand = 7,
    Coal = 8,
    Iron = 9,
    Gold = 10,
    Diamond = 11,
    Emerald = 12
};

// Perlin Noise functions
float fade(float t) { return t * t * t * (t * (t * 6 - 15) + 10); }
float lerp(float a, float b, float t) { return a + t * (b - a); }

float grad(int hash, float x, float y) {
    switch (hash & 3) {
        case 0: return x + y;
        case 1: return -x + y;
        case 2: return x - y;
        case 3: return -x - y;
    }
    return 0;
}

int p[512];

void initPerlin() {
    int permutation[] = {151, 160, 137, 91, 90, 15,
                         131, 13, 201, 95, 96, 53, 194, 233, 7, 225, 140, 36,
                         103, 30, 69, 142, 8, 99, 37, 240, 21, 10, 23,
                         190, 6, 148, 247, 120, 234, 75, 0, 26, 197, 62, 94, 252, 219, 203, 117,
                         35, 11, 32, 57, 177, 33, 88, 237, 149, 56, 87, 174, 20, 125, 136,
                         171, 168, 68, 175, 74, 165, 71, 134, 139, 48, 27, 166,
                         77, 146, 158, 231, 83, 111, 229, 122, 60, 211, 133, 230, 220, 105, 92, 41,
                         55, 46, 245, 40, 244, 102, 143, 54, 65, 25, 63, 161, 1, 216, 80,
                         73, 209, 76, 132, 187, 208, 89, 18, 169, 200, 196, 135, 130, 116,
                         159, 86, 164, 100, 109, 198, 173, 186, 3, 64, 52, 217, 226, 250, 124,
                         123, 5, 202, 38, 147, 118, 126, 255, 82, 85, 212, 207, 206, 59,
                         227, 47, 16, 58, 17, 182, 189, 28, 42, 223, 183, 170, 213,
                         119, 248, 152, 2, 44, 154, 163, 70, 221, 153, 101, 155,
                         167, 43, 172, 9, 129, 22, 39, 253, 19, 98, 108, 110, 79,
                         113, 224, 232, 178, 185, 112, 104, 218, 246, 97, 228,
                         251, 34, 242, 193, 238, 210, 144, 12, 191, 179, 162, 241,
                         81, 51, 145, 235, 249, 14, 239, 107, 49, 192, 214, 31,
                         181, 199, 106, 157, 184, 84, 204, 176, 115, 121, 50,
                         45, 127, 4, 150, 254, 138, 236, 205, 93, 222, 114, 67,
                         29, 24, 72, 243, 141, 128, 195, 78, 66, 215, 61,
                         156, 180};

    for (int i = 0; i < 256; i++)
        p[256 + i] = p[i] = permutation[i];
}

float perlin(float x, float y) {
    int xi = (int)floor(x) & 255;
    int yi = (int)floor(y) & 255;

    float xf = x - floor(x);
    float yf = y - floor(y);

    float u = fade(xf);
    float v = fade(yf);

    int aa = p[p[xi] + yi];
    int ab = p[p[xi] + yi + 1];
    int ba = p[p[xi + 1] + yi];
    int bb = p[p[xi + 1] + yi + 1];

    float x1 = lerp(grad(aa, xf, yf), grad(ba, xf - 1, yf), u);
    float x2 = lerp(grad(ab, xf, yf - 1), grad(bb, xf - 1, yf - 1), u);

    return (lerp(x1, x2, v) + 1) / 2;
}

// Multi-octave Perlin for more detail
float multiOctavePerlin(float x, float y, int octaves, float persistence) {
    float total = 0;
    float frequency = 1;
    float amplitude = 1;
    float maxValue = 0;

    for (int i = 0; i < octaves; i++) {
        total += perlin(x * frequency, y * frequency) * amplitude;
        maxValue += amplitude;
        amplitude *= persistence;
        frequency *= 2;
    }

    return total / maxValue;
}

int getTerrain(float height, float moisture, float resourceNoise, int i, int j) {
    // Địa hình cơ bản dựa trên height
    if (height < 0.30) {
        return Water; // 30% là nước
    }
    else if (height < 0.35) {
        return Sand; // Bờ biển
    }
    
    // Vùng đất liền
    if (height < 0.50) {
        // Vùng thấp - Grass với một số Forest và Tree
        if (moisture > 0.6 && rand() % 100 < 30) {
            return (rand() % 100 < 70) ? Forest : Tree;
        }
        return Grass;
    }
    else if (height < 0.65) {
        // Vùng trung bình - hỗn hợp Grass, Forest, Hill
        if (moisture > 0.55 && rand() % 100 < 40) {
            return (rand() % 100 < 60) ? Forest : Tree;
        }
        if (rand() % 100 < 25) {
            return Hill;
        }
        return Grass;
    }
    else if (height < 0.78) {
        // Vùng cao - Hill và Stone với tài nguyên
        if (rand() % 100 < 15) {
            return Stone;
        }
        
        // Spawn tài nguyên ở vùng đồi núi
        if (resourceNoise > 0.75) {
            int r = rand() % 100;
            if (r < 40) return Coal;      // 40% Coal
            else if (r < 65) return Iron;  // 25% Iron
            else if (r < 80) return Stone; // 15% Stone
            else return Hill;
        }
        
        return Hill;
    }
    else {
        // Vùng núi cao - Mountain với rare resources
        if (resourceNoise > 0.80) {
            int r = rand() % 100;
            if (r < 30) return Gold;      // 30% Gold
            else if (r < 50) return Iron;  // 20% Iron
            else if (r < 60) return Diamond; // 10% Diamond
            else if (r < 65) return Emerald; // 5% Emerald
            else return Stone;
        }
        
        if (rand() % 100 < 30) {
            return Stone;
        }
        
        return Mountain;
    }
}

int n_main() {
    srand(time(NULL));
    
    // Tạo thư mục
#ifdef _WIN32
    system("mkdir assets 2>nul");
    system("mkdir assets\\map 2>nul");
#else
    system("mkdir -p assets/map");
#endif

    std::ofstream outFile("assets/map/mapdata.txt");
    if (!outFile.is_open()) {
        std::cerr << "Không thể ghi file!\n";
        return 1;
    }

    initPerlin();

    std::cout << "Đang sinh map RTS " << MAP_SIZE << "x" << MAP_SIZE << "...\n";

    // Các tham số cho Perlin Noise
    float heightScale = 0.008f;    // Độ mượt của địa hình
    float moistureScale = 0.012f;  // Độ ẩm
    float resourceScale = 0.015f;  // Phân bố tài nguyên

    for (int i = 0; i < MAP_SIZE; i++) {
        if (i % 50 == 0) {
            std::cout << "Đang xử lý hàng " << i << "/" << MAP_SIZE << "\n";
        }
        
        for (int j = 0; j < MAP_SIZE; j++) {
            // Sử dụng nhiều lớp Perlin Noise
            float height = multiOctavePerlin(i * heightScale, j * heightScale, 4, 0.5f);
            float moisture = perlin(i * moistureScale + 1000, j * moistureScale + 1000);
            float resourceNoise = perlin(i * resourceScale + 2000, j * resourceScale + 2000);
            
            int type = getTerrain(height, moisture, resourceNoise, i, j);
            
            outFile << type;
            if (j < MAP_SIZE - 1)
                outFile << " ";
        }
        outFile << "\n";
    }

    outFile.close();
    std::cout << "✓ Map RTS đã được sinh thành công!\n";
    std::cout << "File: assets/map/mapdata.txt\n";
    std::cout << "\nPhân phối địa hình (ước lượng):\n";
    std::cout << "- Water: ~30%\n";
    std::cout << "- Grass: ~25%\n";
    std::cout << "- Forest/Tree: ~15%\n";
    std::cout << "- Hill: ~15%\n";
    std::cout << "- Mountain: ~8%\n";
    std::cout << "- Tài nguyên (Coal, Iron, Gold, etc.): ~5-7%\n";
    
    return 0;
}