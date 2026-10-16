class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int>s;
        for(int i = 0;i<k;i++){
           s.insert(nums[i]);
        }
        vector<int>ans;

        int l = 0;
        int r = k-1;
        while(r<n){
            int m = *s.rbegin();
            ans.push_back(m);
            s.erase(s.find(nums[l]));
            l++;
            r++;
            if(r<n){
                s.insert(nums[r]);
            }
        }
      return ans;
        
       
    }
};