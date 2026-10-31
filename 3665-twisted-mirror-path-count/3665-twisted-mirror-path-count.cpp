class Solution {
public:
    int mod = 1e9 + 7;

    int f(int i, int j, int d, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m) return 0;
        if (i == n - 1 && j == m - 1) return 1;
        if (dp[i][j][d] != -1) return dp[i][j][d];

        long long ans;
        if (grid[i][j] == 1) {
            // forced move: entered right -> go down, entered down -> go right
            if (d == 0) ans = f(i + 1, j, 1, grid, dp);
            else        ans = f(i, j + 1, 0, grid, dp);
        } else {
            // free cell: choose right or down
            ans = (f(i, j + 1, 0, grid, dp) + f(i + 1, j, 1, grid, dp)) % mod;
        }
        return dp[i][j][d] = ans;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(2, -1)));
        return f(0, 0, 0, grid, dp);
    }
};