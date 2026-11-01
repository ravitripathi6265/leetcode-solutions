class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mn = INT_MAX;
        int n = nums.size();
        for(int i = 0 ;i<n;i++){
            if(nums[i]<mn) mn = nums[i];
        }
        int ans = 0;
        for(int i = 0;i<n;i++){
            ans = ans + nums[i]-mn;
        }
        return ans;
    }
};