class Solution {
public:
    // bool isvalid(string &s){
    //     int cnt = 0;

    //     for(char c : s){
    //         if(c == '('){
    //             cnt++;
    //         }
    //         else if(c == ')'){
    //             if(cnt == 0) return false;
    //             cnt--;
    //         }
    //     }

    //     return cnt == 0;
    // }
    void f(int i,int n,string &s,vector<string>&ans,string&t,int& m,int ct){
        if(ct<0)return ;
        if(i == n){
            if(ct == 0){
               if(t.size()>m){
                   m = t.size();
                   ans.clear();
                   ans.push_back(t);
               }
               else if(t.size() == m){
                ans.push_back(t);
               }
            }
            return ;
        }
        f(i+1,n,s,ans,t,m,ct);
        t.push_back(s[i]);
        if(s[i] == '('){
            f(i+1,n,s,ans,t,m,ct+1);
        }
        else if(s[i] == ')'){
            f(i+1,n,s,ans,t,m,ct-1);
        }
        else f(i+1,n,s,ans,t,m,ct);
        t.pop_back();
    }
    vector<string> removeInvalidParentheses(string s) {

        vector<string>ans;
        int n = s.size();
        string t= "";
        int m = 0;
        int ct = 0;
        f(0,n,s,ans,t,m,ct);
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());
        return ans;
    }
};