import numpy as np

def nhap_ma_tran():
    n = int(input("Nhap kich thuoc ma tran n: "))
    A = np.zeros((n, n))
    print("Nhap cac phan tu cua ma tran:")
    for i in range(n):
        for j in range(n):
            A[i][j] = float(input(f"A[{i}][{j}] = "))
    return A

def main():
    A = nhap_ma_tran()

    print("\nMa tran A:")
    print(A)

    try:
        L = np.linalg.cholesky(A)
        print("\nMa tran L (Cholesky):")
        print(L)

        print("\nKiem tra L * L^T:")
        print(L @ L.T)
    except np.linalg.LinAlgError:
        print("Ma tran khong thoa man dieu kien Cholesky!")

if __name__ == "__main__":
    main()
