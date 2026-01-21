import numpy as np

def nhap_ma_tran():
    n = int(input("Nhập kích thước ma trận vuông n x n: "))
    matrix = np.zeros((n, n))
    print("Nhập các phần tử của ma trận:")
    for i in range(n):
        for j in range(n):
            matrix[i][j] = float(input(f"A[{i}][{j}] = "))
    return matrix

def in_ma_tran(matrix, title="Ma trận"):
    print(title + ":")
    for row in matrix:
        print(["{:.3f}".format(x) for x in row])

def tinh_ma_tran_nghich_dao(matrix):
    try:
        inv_matrix = np.linalg.inv(matrix)
        return inv_matrix
    except np.linalg.LinAlgError:
        return None

def main():
    matrix = nhap_ma_tran()
    in_ma_tran(matrix, "Ma trận vừa nhập")
    
    inv_matrix = tinh_ma_tran_nghich_dao(matrix)
    if inv_matrix is None:
        print("Ma trận không khả nghịch (det = 0) :(((")
    else:
        in_ma_tran(inv_matrix, "Ma trận nghịch đảo")

if __name__ == "__main__":
    main()
