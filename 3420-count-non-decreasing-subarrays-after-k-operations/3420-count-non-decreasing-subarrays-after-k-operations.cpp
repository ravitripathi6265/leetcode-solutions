class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);
        for (int i = 0; i < n; i++) pre[i + 1] = pre[i] + nums[i];

        deque<pair<int, long long>> dq; // (index, segment cost)
        long long total = 0, ans = 0;
        int r = n - 1;

        for (int l = n - 1; l >= 0; l--) {
            long long popped = 0;
            while (!dq.empty() && nums[dq.front().first] <= nums[l]) {
                popped += dq.front().second;
                dq.pop_front();
            }
            int nxt = dq.empty() ? r + 1 : dq.front().first;
            long long seg = 1LL * nums[l] * (nxt - l) - (pre[nxt] - pre[l]);
            total += seg - popped;
            dq.push_front({l, seg});

            while (total > k) {
                long long d = nums[dq.back().first] - nums[r];
                total -= d;
                dq.back().second -= d;
                if (dq.back().first == r) dq.pop_back();
                r--;
            }
            ans += r - l + 1;
        }
        return ans;
    }
};