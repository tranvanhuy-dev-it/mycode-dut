import numpy as np

def svd_decomposition(A):
    U, sigma, VT = np.linalg.svd(A)

    # Create Sigma matrix with correct size
    Sigma = np.zeros((A.shape[0], A.shape[1]))
    np.fill_diagonal(Sigma, sigma)

    return U, Sigma, VT

def main():
    # Input the size of the matrix
    m = int(input("Enter the number of rows (m): "))
    n = int(input("Enter the number of columns (n): "))

    # Input matrix A
    print("Enter matrix A:")
    A = np.zeros((m, n))
    for i in range(m):
        for j in range(n):
            A[i, j] = float(input(f"A[{i+1},{j+1}]: "))

    # Perform SVD
    U, Sigma, VT = svd_decomposition(A)

    # Display results
    print("\nMatrix A:")
    print(A)

    print("\nMatrix U (Left Singular Vectors):")
    print(U)

    print("\nDiagonal Matrix Σ (Singular Values):")
    print(Sigma)

    print("\nMatrix V^T (Right Singular Vectors):")
    print(VT)

    # Verify decomposition
    A_reconstructed = U @ Sigma @ VT
    print("\nReconstructed Matrix A (UΣV^T):")
    print(A_reconstructed)

if __name__ == "__main__":
    main()
