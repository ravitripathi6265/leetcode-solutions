class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int mans = 0;
        for(char  c : s){
            if(c == '('){
                ans++;
                mans = max(mans,ans);
            }
            if(c == ')'){
                ans --;
            }
        }
        return mans;
    }
};