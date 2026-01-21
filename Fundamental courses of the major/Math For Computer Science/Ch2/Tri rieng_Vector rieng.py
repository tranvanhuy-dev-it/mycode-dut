import numpy as np

def nhap_ma_tran():
    n = int(input("Nhập kích thước ma trận vuông n x n: "))
    matrix = np.zeros((n, n))
    print("Nhập các phần tử của ma trận: ")
    for i in range(n):
        for j in range(n):
            matrix[i][j] = float(input(f"A[{i}][{j}] = "))
    return matrix

def in_ma_tran(matrix, title="Ma trận"):
    print(title + ":")
    for row in matrix:
        print(["{:.3f}".format(x) for x in row])

def tinh_tri_rieng_vector_rieng(matrix):
    eigenvalues, eigenvectors = np.linalg.eig(matrix)
    return eigenvalues, eigenvectors

def main():
    matrix = nhap_ma_tran()
    in_ma_tran(matrix, "\nMa trận vừa nhập")
    
    eigenvalues, eigenvectors = tinh_tri_rieng_vector_rieng(matrix)
    print("\nTrị riêng của ma trận là:")
    print(["{:.2f}".format(x) for x in eigenvalues])
    
    print("\nVector riêng của ma trận là (mỗi cột là một vector riêng):")
    for row in eigenvectors:
        print(["{:.2f}".format(x) for x in row])

if __name__ == "__main__":
    main()
