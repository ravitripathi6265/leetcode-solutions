class Solution {
public:
    int f(int i,int prev,int ct,vector<vector<vector<int>>>&dp,vector<int>&nums){
        int n = nums.size();
        if(i == n)return 0;
        if(ct <0)return 0;
        if(dp[i][prev+1][ct] != -1){
            return dp[i][prev+1][ct];
        }
        int notake = f(i+1,prev,ct,dp,nums);
        int take = -1e9;
      
        if(prev == -1) {
            take = 1 + f(i + 1, i, ct, dp, nums);
        }
        else if(nums[prev] == nums[i]) {
            take = 1 + f(i + 1, i, ct, dp, nums);
        }
        else if(ct > 0) {
            take = 1 + f(i + 1, i, ct - 1, dp, nums);
        }
       return  dp[i][prev+1][ct] = max(take,notake);
        
    }
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return f(0,-1,k,dp,nums);
    }
};