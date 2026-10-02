class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& in) {
        sort(in.begin(),in.end());
        int n = in.size();
        long long ans = 0;
        for(int i = 0;i<n;i++){
            int l = i+1;
            int r = n-1;
            int pos = i;
            while(l<=r){
                int m = l +(r-l)/2;
                if(in[m][0] <=in[i][1]){
                    l = m+1;
                    pos = m;
                }
                else {
                    r = m-1;
                }

            }
            ans = ans + pos-i;
        }
        return ans;

    }
};