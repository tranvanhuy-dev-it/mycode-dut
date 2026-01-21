import numpy as np

def nhap_he_pt():
    n = int(input("Nhập số phương trình / số ẩn: "))
    A = np.zeros((n, n))
    b = np.zeros(n)
    print("Nhập ma trận hệ số A:")
    for i in range(n):
        for j in range(n):
            A[i][j] = float(input(f"A[{i}][{j}] = "))
    print("Nhập vector kết quả b:")
    for i in range(n):
        b[i] = float(input(f"b[{i}] = "))
    return np.array(A), np.array(b)

def giai_he_pt(A, b):
    try:
        x = np.linalg.solve(A, b)
        return x
    except np.linalg.LinAlgError:
        return None

def main():
    A, b = nhap_he_pt()
    print("\nMa trận hệ số A:")
    print(A)
    print("Vector kết quả b:")
    print(b)

    x = giai_he_pt(A, b)
    if x is None:
        print("Hệ phương trình vô nghiệm hoặc có vô số nghiệm :(((")
    else:
        print("Nghiệm của hệ phương trình là:")
        print(np.round(x, 3))

if __name__ == "__main__":
    main()
