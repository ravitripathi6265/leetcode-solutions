class Solution {
public:
    int maxLength(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            long long p = nums[i];
            int g = nums[i];
            int l = nums[i];
            for(int j = i+1;j<n;j++){
                g = gcd(g,nums[j]);
                l = lcm(l,nums[j]);
                p*=nums[j];
                if(p == g*l){
                    ans = max(ans,j-i+1);
                }
                if(p>g*l)break;
            }
        }
        return ans;
    }
};