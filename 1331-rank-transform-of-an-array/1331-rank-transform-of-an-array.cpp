class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       vector<int>t = arr;
       sort(t.begin(),t.end());
       unordered_map<int,int>m;
      
       int r = 1;
       int n = arr.size();
       if(n == 0)return {};
        m[t[0]] = 1;
       for(int i = 1;i<n;i++){
           if(t[i]  == t[i-1]){
              continue;
           }
           else {
               m[t[i]] = r+1;
               r++;
           }
       }
       vector<int>ans(n,0);
       for(int i = 0;i<n;i++){
           ans[i] = m[arr[i]];
       }
       return ans;
      
    }
};