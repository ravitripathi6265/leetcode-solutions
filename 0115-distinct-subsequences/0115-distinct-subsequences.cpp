class Solution {
public:
    // int solve(int i,int j,string &s,string&t,vector<vector<int>>&dp){
    //     if(j==0)return 1;
       
    //     if(i==0)return 0;
     
    //    if(dp[i][j] != -1)return dp[i][j];
    //    int take = 0;
    //    int notake = 0;
    //    if(s[i-1] == t[j-1]){
    //     take = solve(i-1,j-1,s,t,dp);
    //    }
    //   notake = solve(i-1,j,s,t,dp);
    //  return dp[i][j]= take + notake;
    // }
    int numDistinct(string s, string t) {
        if(s.size()<=t.size())return t == s;
        int n = s.size();
        int m = t.size();
        vector<vector<unsigned long long >>dp(n+1,vector<unsigned long long >(m+1,0));
        // int ans = 0;
      
        // ans = solve(n,m,s,t,dp);
        for(int i = 0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i = 1;i<= n;i++){
            for(int j = 1;j<=m;j++){
               
                if(s[i-1] == t[j-1]){
                    dp[i][j]= dp[i-1][j-1] + dp[i-1][j];
                }
            
                else dp[i][j] = dp[i-1][j];
                
            }
        }

        return (int)dp[n][m];
    }
};