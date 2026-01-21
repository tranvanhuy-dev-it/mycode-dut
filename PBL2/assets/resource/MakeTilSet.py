import os
from PIL import Image, ImageDraw

# ================= CẤU HÌNH =================
TILE_SIZE = 32   # <--- Kích thước tile đã chỉnh thành 32x32
COLUMNS = 4      # Số cột của TileSet (ví dụ 4 cột)
# ============================================

# Danh sách tên file tương ứng (Code sẽ tìm file .png, .jpg khớp tên trong này)
ASSETS = {
    0: ["grass"],
    1: ["forest"],
    2: ["hill"],  # Sẽ tự vẽ
    3: ["mountain"],
    4: ["water"],
    5: ["tree", "wood", "log"],
    6: ["stone", "rock"],
    7: ["sand"],
    8: ["coal"],
    9: ["iron"],
    10: ["gold"],
    11: ["diamond"],
    12: ["emerald"]
}

def create_hill_tile(size):
    """Vẽ tile Đồi (Hill) đơn giản cho kích thước 32x32"""
    img = Image.new("RGBA", (size, size), (0, 0, 0, 0))
    draw = ImageDraw.Draw(img)
    
    # Màu sắc
    base_color = (34, 139, 34, 255)      # Xanh lá đậm (Forest Green)
    highlight_color = (50, 205, 50, 255) # Xanh lá sáng (Lime Green)
    
    # Vẽ hình đồi (dạng bán nguyệt ở dưới đáy)
    # Tọa độ: Left, Top, Right, Bottom
    draw.ellipse((2, size//3, size-2, size + size//2), fill=base_color)
    
    # Vẽ điểm sáng nhỏ trên đỉnh đồi tạo khối
    draw.ellipse((size//2 - 4, size//2, size//2 + 4, size//2 + 5), fill=highlight_color)
    
    return img

def find_image(names, search_path="D:/PBL2/assets/resource"):
    """Tìm file ảnh có đuôi png/jpg/jpeg"""
    extensions = [".png", ".jpg", ".jpeg"]
    for name in names:
        for ext in extensions:
            full_path = os.path.join(search_path, name + ext)
            if os.path.exists(full_path):
                return full_path
    return None

def main():
    print(f"--- BẮT ĐẦU TẠO TILESET (Kích thước mỗi ô: {TILE_SIZE}x{TILE_SIZE}) ---")
    
    # Tính toán kích thước ảnh tổng
    total_items = max(ASSETS.keys()) + 1
    rows = (total_items + COLUMNS - 1) // COLUMNS
    
    tileset_width = COLUMNS * TILE_SIZE
    tileset_height = rows * TILE_SIZE
    
    # Tạo nền trong suốt
    tileset = Image.new("RGBA", (tileset_width, tileset_height), (0, 0, 0, 0))

    for index in range(total_items):
        names = ASSETS.get(index, ["unknown"])
        tile_img = None
        
        # Vị trí dán ảnh
        x = (index % COLUMNS) * TILE_SIZE
        y = (index // COLUMNS) * TILE_SIZE

        # Xử lý riêng cho Hill (index 2)
        if index == 2:
            print(f"[Index {index}] Hill: Đang tự tạo ảnh pixel...")
            tile_img = create_hill_tile(TILE_SIZE)
        else:
            # Tìm ảnh
            img_path = find_image(names)
            if img_path:
                try:
                    original_img = Image.open(img_path).convert("RGBA")
                    # Resize về 32x32 (Dùng LANCZOS để ảnh nét nhất khi thu nhỏ)
                    tile_img = original_img.resize((TILE_SIZE, TILE_SIZE), Image.Resampling.LANCZOS)
                    print(f"[Index {index}] Đã thêm: {img_path}")
                except Exception as e:
                    print(f"[Index {index}] LỖI đọc file {img_path}: {e}")
            else:
                print(f"[Index {index}] THIẾU ẢNH! (Đang tìm: {names})")
                # Nếu thiếu ảnh, tạo một ô màu hồng tím để dễ nhận biết
                tile_img = Image.new("RGBA", (TILE_SIZE, TILE_SIZE), (255, 0, 255, 255))

        # Dán vào tileset
        if tile_img:
            tileset.paste(tile_img, (x, y), tile_img if tile_img.mode == 'RGBA' else None)

    # Lưu file
    output_filename = "TileSet_32x32.png"
    tileset.save(output_filename)
    print(f"\nXONG! File đã được lưu tên là: {output_filename}")

if __name__ == "__main__":
    main()