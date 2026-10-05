class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int ct = 0;
        int n= s.size();
        for(int i = 0;i<n;i++){
            if(s[i] == '('){
                ct++;
            }
            else{
                ans = ans + pow(2,ct-1);
                ct= 0;
                while(i<n-1 && s[i+1] == ')'){
                    i++;
                }
                
            }

        }
        return ans;
    }
};