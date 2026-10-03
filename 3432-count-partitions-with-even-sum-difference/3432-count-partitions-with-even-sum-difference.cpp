class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>psum(n+1,0);
        for(int i = 0;i<n;i++){
            psum[i+1] = nums[i]+ psum[i];
        }
        int ans = 0;
        for(int i = 0;i<n-1;i++){
            int lsum = psum[i+1] - psum[0];
            int rsum = psum[n] - psum[i+1];
            if(abs(rsum - lsum)%2 == 0)ans++;
        }
        return ans;
    }
};