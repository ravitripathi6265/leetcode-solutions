class Solution {
public:
    int arrangeCoins(int n) {
        if(n<=1)return n;
        int i = 1;
        int ans = 0;
        long long a = 0;
        while(a<=n){
             a = (1LL * i * (i + 1)) / 2;
            i++;
            ans++;
        }
        return ans-1;
    }
};