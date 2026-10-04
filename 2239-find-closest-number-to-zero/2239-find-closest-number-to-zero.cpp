class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int ans = INT_MAX;
        int num = INT_MAX;

        for(int x : nums) {

            if(abs(x) < ans) {
                ans = abs(x);
                num = x;
            }
            else if(abs(x) == ans && x > num) {
                num = x;
            }
        }

        return num;
    }
};