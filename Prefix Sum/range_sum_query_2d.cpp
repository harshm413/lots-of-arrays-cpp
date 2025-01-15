#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
private:
    vector<vector<int>> prefixSums;

public:
    // Constructor to initialize the 2D matrix and compute the prefix sums
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        prefixSums.resize(m + 1, vector<int>(n + 1, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                prefixSums[i + 1][j + 1] = matrix[i][j] 
                                         + prefixSums[i][j + 1] 
                                         + prefixSums[i + 1][j] 
                                         - prefixSums[i][j];
            }
        }
    }

    // Function to calculate the sum of elements in the rectangle defined by (row1, col1) and (row2, col2)
    int sumRegion(int row1, int col1, int row2, int col2) {
        return prefixSums[row2 + 1][col2 + 1] 
             - prefixSums[row1][col2 + 1] 
             - prefixSums[row2 + 1][col1] 
             + prefixSums[row1][col1];
    }
};

/*
Time Complexity:
- Precomputing prefix sums takes O(m * n), where m and n are the dimensions of the matrix.
- Querying the sum of any submatrix takes O(1) due to the precomputed prefix sums.
- For q queries, the total complexity is O(m * n + q).
  Explanation: The prefix sums allow constant-time queries after an initial preprocessing step.
Space Complexity: O(m * n), to store the prefix sums.
*/

int main() {
    // Example input
    vector<vector<int>> matrix = {
        {3, 0, 1, 4, 2},
        {5, 6, 3, 2, 1},
        {1, 2, 0, 1, 5},
        {4, 1, 2, 1, 4},
        {1, 0, 3, 0, 1}
    };

    NumMatrix numMatrix(matrix);

    // Example queries
    cout << "Sum of region (2, 1) to (4, 3): " << numMatrix.sumRegion(2, 1, 4, 3) << endl; // Output: 8
    cout << "Sum of region (1, 1) to (2, 2): " << numMatrix.sumRegion(1, 1, 2, 2) << endl; // Output: 11
    cout << "Sum of region (1, 2) to (2, 4): " << numMatrix.sumRegion(1, 2, 2, 4) << endl; // Output: 12

    return 0;
}

/*
// Approach: Brute Force
class NumMatrix {
private:
    vector<vector<int>> matrix;

public:
    NumMatrix(vector<vector<int>>& matrix) : matrix(matrix) {}

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;

        // Iterate over the submatrix and calculate the sum
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                sum += matrix[i][j];
            }
        }

        return sum;
    }
};


Time Complexity:
- Calculating the sum for a submatrix takes O((row2 - row1 + 1) * (col2 - col1 + 1)).
- For q queries, the total complexity is O(q * m * n), where m and n are the dimensions of the matrix.
  Explanation: Each query involves iterating over all elements in the given submatrix.
Space Complexity: O(1), as no additional data structures are used.

*/