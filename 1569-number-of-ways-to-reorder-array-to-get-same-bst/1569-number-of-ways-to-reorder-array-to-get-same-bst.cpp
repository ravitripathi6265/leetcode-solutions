class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<vector<long long>> dp;

    long long nCr(int n, int r) {
        if (r == 0 || r == n) return 1;

        if (dp[n][r] != -1)
            return dp[n][r];

        return dp[n][r] =
            (nCr(n - 1, r - 1) + nCr(n - 1, r)) % MOD;
    }

    long long solve(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2) return 1;

        vector<int> left, right;

        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[0])
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        int l = left.size();
        int r = right.size();

        long long ways = nCr(l + r, l);

        ways = ways * solve(left) % MOD;
        ways = ways * solve(right) % MOD;

        return ways;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        dp.assign(n + 1, vector<long long>(n + 1, -1));

        return (solve(nums) - 1 + MOD) % MOD;
    }
};