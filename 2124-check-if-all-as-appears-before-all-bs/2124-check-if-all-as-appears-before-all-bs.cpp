class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool ans  = true;
        int b = 0;
        for(char c : s){
             if(c == 'b'){
                 b =1 ;

             }
             if(b && c == 'a')ans = false;
        }
        return ans;
    }
};