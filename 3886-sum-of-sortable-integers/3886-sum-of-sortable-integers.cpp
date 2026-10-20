class Solution {
public:
    bool check(vector<int>& nums, int k) {
        int n = nums.size();
        int prevMax = INT_MIN;

        for (int i = 0; i < n; i += k) {
            int l = i;
            int r = i + k - 1;

            int mn = nums[l];
            int mx = nums[l];
            int cnt = 0;

            for (int j = l; j <= r; j++) {
                mn = min(mn, nums[j]);
                mx = max(mx, nums[j]);

                int next;
                if(j == r)next = l;
                else next =j+1;

                if (nums[j] > nums[next]) {
                    cnt++;
                }
            }

            if (cnt > 1) return false;

            if (prevMax > mn) return false;

            prevMax = mx;
        }

        return true;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int k = 1; k <= n; k++) {
            
            if(n%k == 0){
                if(check(nums,k))ans+=k;
            }
        }

        return ans;
    }
};