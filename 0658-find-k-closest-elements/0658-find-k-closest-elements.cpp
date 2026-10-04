class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        vector<pair<int,int>>dif(n); 
       for(int i= 0;i<n;i++){
        dif[i].first = abs(x-arr[i]);
        dif[i].second = i;
       }
       sort(dif.begin(),dif.end());
       vector<int>ans(k,0);
       for(int i = 0;i<k;i++){
        ans[i] = arr[dif[i].second];
       }
       sort(ans.begin(),ans.end());
       return ans;

    }
};