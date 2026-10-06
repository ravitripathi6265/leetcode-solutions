class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int len = 0;
        stack<char>st;
        for(int i = 0;i<n;i++){
            if(s[i]  =='('){
                st.push(s[i]);
            }
            else {
               if(!st.empty()){
                if(st.top() =='('){
                len++;
                st.pop();
               }
               }
               
            }
        }
        len = 2*len;
        return n - len;
    }
};