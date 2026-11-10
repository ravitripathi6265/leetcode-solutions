class Solution {
public:
    

    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, -1);
        dp[n] = 0;
        for(int i = n-1;i>=0;i--){
            int d1 = costs[i] + 1 + dp[i+1];
            int d2 = INT_MAX;
            if(i+1<n){
                d2 = costs[i+1] + 4 + dp[i+2];
            }
            int d3 = INT_MAX;
            if(i+2<n){
                d3 = costs[i+2] + 9 +  dp[i+3];
            }
            dp[i] = min({d1,d2,d3});
        }

        return dp[0];
    }
};