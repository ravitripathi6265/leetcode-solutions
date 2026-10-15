class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
    
        for(int i = 0;i<n;i++){
            unordered_map<int,int>m;
            for(int j = i;j<n;j++){
                m[nums[j]]++;
                int ct = 0;
                for(auto &it : m){
                 ct++;
            }
            ans+= ct*ct;

            }
            
        }
        return ans;
    }
};