class Solution {
public:
    const long long INF = LLONG_MAX / 4;

    // builds temp[i] = cost to make window [i..i+x-1] equal, in O(n log x)
    vector<long long> getCosts(vector<int>& nums, int x) {
        int n = nums.size();
        vector<long long> temp;
        multiset<int> low, high;          // low = smaller half, high = larger half
        long long sumLow = 0, sumHigh = 0;
        int target = (x + 1) / 2;         // size of low, so max(low) is the median

        for (int r = 0; r < n; r++) {
            // element enters
            if (low.empty() || nums[r] <= *low.rbegin()) {
                low.insert(nums[r]);
                sumLow += nums[r];
            } else {
                high.insert(nums[r]);
                sumHigh += nums[r];
            }

            // element leaves
            if (r >= x) {
                int u = nums[r - x];
                if (u <= *low.rbegin()) {
                    low.erase(low.find(u));
                    sumLow -= u;
                } else {
                    high.erase(high.find(u));
                    sumHigh -= u;
                }
            }

            // rebalance so low.size() == target
            while ((int)low.size() > target) {
                int v = *low.rbegin();
                low.erase(prev(low.end()));
                sumLow -= v;
                high.insert(v);
                sumHigh += v;
            }
            while ((int)low.size() < target && !high.empty()) {
                int v = *high.begin();
                high.erase(high.begin());
                sumHigh -= v;
                low.insert(v);
                sumLow += v;
            }

            if (r >= x - 1) {
                long long med = *low.rbegin();
                temp.push_back(med * (long long)low.size() - sumLow
                             + sumHigh - med * (long long)high.size());
            }
        }
        return temp;
    }

    // your solve, unchanged except INF
    long long solve(int i, int k, vector<vector<long long>>& dp, vector<long long>& temp, int x) {
        int m = temp.size();
        if (k == 0) return 0;
        if (i >= m) return INF;
        if (dp[i][k] != -1) return dp[i][k];
        long long notake = solve(i + 1, k, dp, temp, x);
        long long take = temp[i] + solve(i + x, k - 1, dp, temp, x);
        return dp[i][k] = min(take, notake);
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        vector<long long> temp = getCosts(nums, x);
        int m = temp.size();
        vector<vector<long long>> dp(m + 1, vector<long long>(k + 1, -1));
        return solve(0, k, dp, temp, x);
    }
};