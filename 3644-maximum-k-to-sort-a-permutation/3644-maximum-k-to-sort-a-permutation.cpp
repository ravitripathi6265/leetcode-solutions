class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = INT_MIN;
        for(int i = 0;i<n;i++){
            if(nums[i] != i){
               if(k == INT_MIN)k = nums[i];
               else {
                k = k & nums[i];
               }
            }
        }
        if(k == INT_MIN) return 0;
        return k;
    }
};