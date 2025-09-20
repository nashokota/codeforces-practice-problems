#include <bits/stdc++.h>
using namespace std;

// Utility to display a matrix on the console
void displayMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << " ";
        }
        cout << endl;
    }
}

// Functions for adding and subtracting matrices
vector<vector<int>> matrixAdd(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int size = mat1.size();
    vector<vector<int>> result(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return result;
}

vector<vector<int>> matrixSubtract(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int size = mat1.size();
    vector<vector<int>> result(size, vector<int>(size));
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return result;
}

// Strassen's Matrix Multiplication Algorithm
vector<vector<int>> strassenMultiply(const vector<vector<int>>& matA, const vector<vector<int>>& matB) {
    int n = matA.size();

    // Base case for recursion
    if (n == 1) {
        return {{matA[0][0] * matB[0][0]}};
    }

    int newSize = n / 2;
    vector<vector<int>> a(newSize, vector<int>(newSize)), b(newSize, vector<int>(newSize));
    vector<vector<int>> c(newSize, vector<int>(newSize)), d(newSize, vector<int>(newSize));
    vector<vector<int>> e(newSize, vector<int>(newSize)), f(newSize, vector<int>(newSize));
    vector<vector<int>> g(newSize, vector<int>(newSize)), h(newSize, vector<int>(newSize));

    // Dividing matrices into submatrices
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            a[i][j] = matA[i][j];
            b[i][j] = matA[i][j + newSize];
            c[i][j] = matA[i + newSize][j];
            d[i][j] = matA[i + newSize][j + newSize];

            e[i][j] = matB[i][j];
            f[i][j] = matB[i][j + newSize];
            g[i][j] = matB[i + newSize][j];
            h[i][j] = matB[i + newSize][j + newSize];
        }
    }

    // Calculating the 7 products as per Strassen's formula
    auto p1 = strassenMultiply(a, matrixSubtract(f, h));
    auto p2 = strassenMultiply(matrixAdd(a, b), h);
    auto p3 = strassenMultiply(matrixAdd(c, d), e);
    auto p4 = strassenMultiply(d, matrixSubtract(g, e));
    auto p5 = strassenMultiply(matrixAdd(a, d), matrixAdd(e, h));
    auto p6 = strassenMultiply(matrixSubtract(b, d), matrixAdd(g, h));
    auto p7 = strassenMultiply(matrixSubtract(a, c), matrixAdd(e, f));

    // Combining results into resultant matrix
    vector<vector<int>> c11 = matrixAdd(matrixSubtract(matrixAdd(p5, p4), p2), p6);
    vector<vector<int>> c12 = matrixAdd(p1, p2);
    vector<vector<int>> c21 = matrixAdd(p3, p4);
    vector<vector<int>> c22 = matrixSubtract(matrixSubtract(matrixAdd(p1, p5), p3), p7);

    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            result[i][j] = c11[i][j];
            result[i][j + newSize] = c12[i][j];
            result[i + newSize][j] = c21[i][j];
            result[i + newSize][j + newSize] = c22[i][j];
        }
    }

    return result;
}

// Function to create a random square matrix of given size
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            matrix[i][j] = rand() % 10; // Random values between 0 and 9
        }
    }
    return matrix;
}

// Distance calculation for points
struct Point {
    int x, y;
};

double computeDistance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

// Brute-force method to find closest pair of points
pair<Point, Point> bruteForceClosestPair(const vector<Point>& points) {
    double minDistance = DBL_MAX;
    pair<Point, Point> closestPair;
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i + 1; j < points.size(); ++j) {
            double dist = computeDistance(points[i], points[j]);
            if (dist < minDistance) {
                minDistance = dist;
                closestPair = {points[i], points[j]};
            }
        }
    }
    return closestPair;
}

// Main function to test Strassen and Closest Pair
int main() {
    srand(time(0));

    // Testing Strassen's Algorithm
    int size = 4; // Ensure size is a power of 2
    auto matrixA = generateMatrix(size);
    auto matrixB = generateMatrix(size);

    cout << "Matrix A:\n";
    displayMatrix(matrixA);

    cout << "Matrix B:\n";
    displayMatrix(matrixB);

    auto resultMatrix = strassenMultiply(matrixA, matrixB);
    cout << "Resultant Matrix (Strassen's):\n";
    displayMatrix(resultMatrix);

    // Testing Closest Pair of Points
    vector<Point> points = {{0, 0}, {1, 1}, {2, 2}, {3, 3}, {5, 1}, {7, 2}};
    auto closest = bruteForceClosestPair(points);

    cout << "Closest Pair: (" << closest.first.x << ", " << closest.first.y << ") and ("
         << closest.second.x << ", " << closest.second.y << ")\n";

    return 0;
}
