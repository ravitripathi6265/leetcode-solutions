class Solution {
public:
    int m = 1e9+7;
    int maxSum(vector<int>& nums, int k) {
        vector<int>bits(32,0);
        for(int num : nums){
            for(int i = 0;i<32;i++){
                  if(num & (1<<i)){
                    bits[i]++;
                  }
            }
        }
        long long  ans = 0;
        for(int j = 0;j<k;j++){
            int x = 0;
            for(int i = 0;i<32;i++){
                if(bits[i] != 0){
                    x = x|(1<<i);
                    bits[i]--;
                }
            }
            ans = (ans+ 1LL*x*x)%m;
        }
        return ans;
    }
};