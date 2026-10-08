class Solution {
public:
    int f(int i,int prev,vector<vector<int>>&dp,vector<int>&nums){
        int n = nums.size();
        if(i == n){
            return 0;

        }
        if(dp[i][prev+1] != -1)return dp[i][prev+1];
        int notake = f(i+1,prev,dp,nums);
        int take = -1e9;
        if(prev == -1 || nums[prev]<nums[i]){
            take = 1 + f(i+1,i,dp,nums);
        }
        return dp[i][prev+1] = max(take,notake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,-1,dp,nums);
    }
};