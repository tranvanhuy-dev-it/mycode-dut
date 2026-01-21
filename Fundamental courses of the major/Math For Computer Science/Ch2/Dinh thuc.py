def determinant(matrix):
    # Ma trận 1x1
    if len(matrix) == 1:
        return matrix[0][0]
    
    # Ma trận 2x2
    if len(matrix) == 2:
        return matrix[0][0]*matrix[1][1] - matrix[0][1]*matrix[1][0]
    
    det = 0
    for c in range(len(matrix)):
        # Tạo ma trận con bằng cách loại bỏ hàng 0 và cột c
        sub_matrix = [row[:c] + row[c+1:] for row in matrix[1:]]
        det += ((-1)**c) * matrix[0][c] * determinant(sub_matrix)
    return det

# Nhập ma trận từ người dùng
def main():
    n = int(input("Nhập kích thước ma trận vuông n x n: "))
    matrix = []
    for i in range(n):
        row = []
        for j in range(n):
            row.append(float(input(f"A[{i}][{j}] = ")))
        matrix.append(row)

    print("Ma trận vừa nhập là:")
    for row in matrix:
        print(row)

    print(f"Định thức của ma trận là: {determinant(matrix)}")

if __name__ == "__main__":
    main()
