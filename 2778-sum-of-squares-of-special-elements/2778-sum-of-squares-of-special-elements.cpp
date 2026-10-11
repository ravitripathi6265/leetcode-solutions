class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int i = 1;
        for(int num : nums){
            if(n%i == 0)ans+= num*num;
            i++;
        }
        return ans;
    }
};