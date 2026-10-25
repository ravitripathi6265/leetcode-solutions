class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>arr;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            arr.push_back({nums[i],i});
        }
        sort(arr.begin(),arr.end());
        vector<pair<int,int>>v;
        
        for(int i = n-1;i>=0;i--){
            if(k == 0)break;
            v.push_back({arr[i].first,arr[i].second});
            k--;
        }
        sort(v.begin(),v.end(),[](auto &a,auto &b){
               return a.second < b.second;
        });
        vector<int>ans;
        for(int i = 0;i<v.size();i++){
            ans.push_back(v[i].first);
        }
        return ans;

    }
};