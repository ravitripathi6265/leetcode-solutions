class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        int n = arr1.size();
        int m = arr2.size();
        for(int i = 0;i<n;i++){
            int f = 1;
            for(int j = 0;j<m;j++){
                if(abs(arr1[i] - arr2[j])<=d){
                    f = 0;
                }
            }
            if(f)ans++;
        }
        return ans;
    }
};