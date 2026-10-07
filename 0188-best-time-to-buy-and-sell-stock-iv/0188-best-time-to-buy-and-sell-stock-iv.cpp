class Solution {
public:
    int f(int i, int buy,int cap, vector<vector<vector<int>>>&dp,
          vector<int>& prices, int n) {
       if(cap == 0)return 0;

        if (i == n)
            return 0;

        if (dp[i][buy][cap] != -1)
            return dp[i][buy][cap];

        if (buy) {
            // Buy or skip
             return dp[i][buy][cap]  = max(-prices[i] + f(i+1,0,cap,dp,prices,n),
                   f(i+1,1,cap,dp,prices,n));
        }
        else {
            // Sell or skip
            return dp[i][buy][cap] = max(
                prices[i] + f(i + 1, 1,cap-1, dp, prices, n),
                f(i + 1, 0, cap,dp, prices, n)
            );
        }
    }
    int maxProfit(int k, vector<int>& prices) {
          int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,dp,prices,n);
    }
};