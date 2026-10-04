class Solution {
public:
    bool f(int i,int ct,string&s,vector<vector<int>>&dp){
        if(ct<0)return false;

        if(i == s.size()){
            return ct == 0;
        }
        if(dp[i][ct] != -1)return dp[i][ct];
        bool ans = false;
        if(s[i]  == '('){
            ans =  f(i+1,ct+1,s,dp);
        }
        else if(s[i] == ')'){
            ans =  f(i+1,ct-1,s,dp);
        }
        
        else {
            ans = f(i+1,ct+1,s,dp) ||
                  f(i+1,ct,s,dp)||
                  f(i+1,ct-1,s,dp);
        }
        return dp[i][ct] = ans;
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return f(0,0,s,dp);
    }
};