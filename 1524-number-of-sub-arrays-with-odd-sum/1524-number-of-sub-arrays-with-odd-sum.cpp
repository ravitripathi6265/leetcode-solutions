class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();
        int m = 1e9 + 7;
        int ans = 0;
        int odd = 0;
        int even = 0;

        for(int x : arr ){
              long long od = odd;
              long long ev = even;
              if(x % 2 == 0){
                  odd = od;
                  even = ev + 1;
              }
              else {
                   even = odd;
                   odd = ev+1;
              }
              ans = (ans + odd) % m;
        }
        return ans;
    }
};