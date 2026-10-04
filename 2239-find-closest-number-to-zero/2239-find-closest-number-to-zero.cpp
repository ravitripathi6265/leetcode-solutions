class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int ans = INT_MAX;
        int num = INT_MAX;
        int n = nums.size();
        int aa = INT_MAX;
        for(int i = 0;i<n;i++){
           if(abs(nums[i])<ans){
            ans = min(ans,abs(nums[i]));
            aa = i;
            num = nums[i];
           }
          else if(ans == abs(nums[i])){
            if(nums[i] > num)aa = i;
        }
       
    }
     return nums[aa];
    }
};