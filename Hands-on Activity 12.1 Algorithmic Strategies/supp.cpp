#include <iostream>
#include <vector>

// Counts paths from (i, j) to the last cell that cost exactly 'cost'
int countPaths(const std::vector<std::vector<int>>& mat, int i, int j, int cost,
               std::vector<std::vector<std::vector<int>>>& memo) {
    int M = mat.size(), N = mat[0].size();

    // Stop if outside the matrix or cost is already too much
    if (i >= M || j >= N || cost < 0) return 0;

    cost -= mat[i][j];          // add this cell's cost
    if (cost < 0) return 0;

    // Last cell: it is a path only if the cost matches exactly
    if (i == M - 1 && j == N - 1)
        return (cost == 0) ? 1 : 0;

    // If already solved, reuse the saved answer
    if (memo[i][j][cost] != -1) return memo[i][j][cost];

    // Paths going right + paths going down
    memo[i][j][cost] = countPaths(mat, i, j + 1, cost, memo)
                     + countPaths(mat, i + 1, j, cost, memo);
    return memo[i][j][cost];
}

int solve(const std::vector<std::vector<int>>& mat, int cost) {
    int M = mat.size(), N = mat[0].size();
    // -1 means "not solved yet"
    std::vector<std::vector<std::vector<int>>> memo(M, std::vector<std::vector<int>>(N, std::vector<int>(cost + 1, -1)));
    return countPaths(mat, 0, 0, cost, memo);
}

int main() {
    std::vector<std::vector<int>> mat = {
        {4, 7, 1, 6},
        {6, 7, 3, 9},
        {3, 8, 1, 2},
        {7, 1, 7, 3}
    };

    std::cout << "Cost 25: " << solve(mat, 25) << "\n";
    std::cout << "Cost 21: " << solve(mat, 21) << "\n";
    return 0;
}