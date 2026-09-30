class Solution {
public:
    int solve(int i,int j,string &s,string&t,vector<vector<int>>&dp){
          if(j==t.size())
           return 1;
       
        if(i==s.size())return 0;
     
       if(dp[i][j] != -1)return dp[i][j];
       int take = 0;
       int notake = 0;
       if(s[i] == t[j]){
        take = solve(i+1,j+1,s,t,dp);
       }
      notake = solve(i+1,j,s,t,dp);
     return dp[i][j]= take + notake;
    }
    int numDistinct(string s, string t) {
        if(s.size()<=t.size())return t == s;
        int n = s.size();
        int m = t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
      
        ans = solve(0,0,s,t,dp);
        return ans;
    }
};