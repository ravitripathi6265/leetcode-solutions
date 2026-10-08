class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int n = s.size();
        // stack<char>st;
        // int start = 0;
        int ct = 1;
        for(int i = 1;i<n;i++){
            if(s[i] == '('){
                ans.push_back(s[i]);
                ct++;
            }
            else{
                ct--;
                if(ct == 0){
                    ct = 1;
                    i = i+1;
                    continue;
                }
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};