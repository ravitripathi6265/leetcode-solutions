class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        int n = nums1.size();
        vector<int>dif(n);
        int m = 0;
        long long s = 0;
        long long k = 1LL * (k1 + k2);

        for(int i = 0; i < n; i++){
            dif[i] = abs(nums1[i] - nums2[i]);
            m = max(m, dif[i]);
            s += dif[i];
        }

        if(s <= k) return 0;

        vector<int>freq(m + 1, 0);

        for(int i = 0; i < n; i++){
            freq[dif[i]]++;
        }

        freq[0] = 0;

        int i = m;

        while(i > 0 && k > 0){
            int d = freq[i];

            if(d <= k){
                freq[i] = 0;
                k -= d;
                freq[i - 1] += d;
                i--;
            }
            else {
                freq[i] -= k;
                freq[i - 1] += k;
                k = 0;
            }
        }

        long long ans = 0;

        for(int i = 0; i <= m; i++){
            int d = freq[i];

            if(d != 0){
                ans += 1LL * d * i * i;
            }
        }

        return ans;
    }
};