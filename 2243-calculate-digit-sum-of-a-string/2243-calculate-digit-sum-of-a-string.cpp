class Solution {
public:
    string digitSum(string s, int k) {
       int n = s.size();
       int i =0;
       
       while(n>k){
           string t = "";
         while(i<n){
           int sum = 0;
           int x = 0;
           while(i<n && x<k){
               sum += s[i] -'0';
                i++;
                x++;
           }
           t+= to_string(sum);
           
       }
        n = t.size();
        s = t;
        i = 0;
       }
       return s;
    }
};