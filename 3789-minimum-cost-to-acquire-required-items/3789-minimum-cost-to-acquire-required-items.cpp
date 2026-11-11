class Solution {
public:
    long long minimumCost(int c1, int c2, int cb, int need1, int need2) {
        
       long long ans = 0;
       if(cb < c1 + c2){
            long long a1 = (long long )cb * (max(need1,need2));
            long long a2 = (long long )cb* (min(need1,need2));
            if(need1>need2){
                a2+= (long long )c1*(need1 - need2);

            } 
            else {
                a2+= (long long )c2*(need2 - need1);

            }
            ans = min(a1,a2);
       }
       else {
           ans = (long long )need1 * c1 + (long long )need2 * c2;
       }
       return ans;
    }
};