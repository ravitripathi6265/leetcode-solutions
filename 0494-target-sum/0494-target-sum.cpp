class Solution {
public:
   int findans(int i,vector<int>&nums,int target,vector<vector<int>>&dp,int off){
      if(target < -off || target > off)
            return 0;
  if(i == 0) {
    if(target == 0 && nums[0] == 0)
        return 2;

    if(nums[0] == target || nums[0] == -target)
        return 1;

    return 0;
}
    if(dp[i][target+off] != -1)return dp[i][target+off];
    int plus = findans(i-1,nums,target- nums[i],dp,off);
    int minus = findans(i-1,nums,target+nums[i],dp,off);
    return dp[i][target+off] = plus+ minus;
   }
     
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = 0;
        for(int x : nums)sum+= x;
         if(abs(target) > sum)
            return 0;
        vector<vector<int>>dp(n,vector<int>(2*sum+1,-1));
        return findans(n-1,nums,target,dp,sum);
    }
};