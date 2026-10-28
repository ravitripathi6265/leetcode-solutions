class Solution {
public:
    static const int K = 1024;  

    int f(int i, int j, int cur, vector<vector<int>>& grid,
          vector<vector<vector<int>>>& dp) {
        int n = grid.size(), m = grid[0].size();

       
        if (i >= n || j >= m) return INT_MAX;

        cur ^= grid[i][j];

  
        if (i == n - 1 && j == m - 1) return cur;

        if (dp[i][j][cur] != -1) return dp[i][j][cur];

        int down  = f(i + 1, j, cur, grid, dp);
        int right = f(i, j + 1, cur, grid, dp);

        return dp[i][j][cur] = min(down, right);
    }

    int minCost(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(K, -1)));
        return f(0, 0, 0, grid, dp);
    }
};