
class Solution {
public:
    int getCost(string &s, int l, int r) {
        int len = r - l + 1;
        int ans = INT_MAX;

        for (int d = 1; d < len; d++) {
            if (len % d != 0) continue;

            int changes = 0;

            for (int start = 0; start < d; start++) {
                int i = l + start;
                int j = l + start + (len / d - 1) * d;

                while (i < j) {
                    if (s[i] != s[j])
                        changes++;

                    i += d;
                    j -= d;
                }
            }

            ans = min(ans, changes);
        }

        return ans;
    }

    int minimumChanges(string s, int k) {
        int n = s.size();
        const int INF = 1e9;

        vector<vector<int>> cost(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                cost[i][j] = getCost(s, i, j);
            }
        }

      
        vector<vector<int>> dp(
            k + 1, vector<int>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {
                for (int j = 2 * (p - 1); j <= i - 2; j++) {
                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
