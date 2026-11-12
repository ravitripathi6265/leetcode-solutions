
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int ans = 1;

        for(int i = 0; i < n; i++) {
                bool f1 = true;
                bool f2 = true;
            for(int j = i; j < n; j++) {
                 if(j>i){
                    if(nums[j] <= nums[j-1]){
                        f1 = false;
                    }
                    if(nums[j]>= nums[j-1])f2 = false;
                 }

             
                if(f1 || f2) {
                    l = j - i + 1;
                    ans = max(l, ans);
                }
            }
        }

        return ans;
    }
};
