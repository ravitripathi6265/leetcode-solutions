class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
       string ans = "";
        if(sum<=9 && num>=1){
            ans.push_back(sum + '0');
            int ct = 1;
            while(ct<num){
                ans.push_back('0');
                ct++;
            }
            return ans;
        }
        if(num<=1 && sum>9)return "";
        int ss = 9;
        int a = 9;
        int ct = 0;
        while(ct < num && ss<=sum){
           
            ans.push_back(a + '0');
            ct++;
          
             if(ss == sum){
                while(ct<num){
                    ans.push_back('0');
                    ct++;
                }
                return ans;
            }
              ss += 9;
        }
        ss = ss - 9;
         
         if(ct < num && ss<sum){
            int rem = sum - ss;
            ss = sum;
           ans.push_back(rem+'0');
           ct++;

         }
         while(ct<num){
            ans.push_back('0');
            ct++;
         }
         if(ss == sum)return ans;
         return "";
        
    }
};