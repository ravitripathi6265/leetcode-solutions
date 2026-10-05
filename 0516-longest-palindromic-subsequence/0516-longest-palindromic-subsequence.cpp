class Solution {
public:
    int f(int i,int j,string &t1,string& t2,vector<vector<int>>&dp){
    if(i<0 || j<0)return 0;
    if(dp[i][j] != -1)return dp[i][j];
    if(t1[i] == t2[j]){
        return dp[i][j] =  1 + f(i-1,j-1,t1,t2,dp);

    }
    return dp[i][j] =  max(f(i-1,j,t1,t2,dp),f(i,j-1,t1,t2,dp));

   }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string t = s;
        reverse(t.begin(),t.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return f(n-1,n-1,s,t,dp);
    }
};