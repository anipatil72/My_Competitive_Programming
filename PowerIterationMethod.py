import numpy as np


def power_iteration(A, max_iter=1000, tol=1e-6):
    n = A.shape[0]
    x = np.random.rand(n)
    x /= np.linalg.norm(x)

    for i in range(max_iter):
        y = A @ x
        eigenvalue = np.dot(y, x)
        x_new = y / np.linalg.norm(y)

        if np.linalg.norm(x_new - x) < tol:
            break

        x = x_new

    return eigenvalue, x


# Example usage
A = np.array([[1, 2], [3, 4]])
eigenvalue, eigenvector = power_iteration(A)

print(f"Dominant eigenvalue: {eigenvalue}")
print(f"Dominant eigenvector: {eigenvector}")
