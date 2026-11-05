class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans = 0;
        int n = arr1.size();
        int m = arr2.size();
        sort(arr2.begin(),arr2.end());

        for(int i = 0;i<n;i++){
              int num = arr1[i];
              bool f = true;
              int l = 0;
              int h=  m-1;
              while(l<=h){
                int m = l + (h-l)/2;
                if(abs(num - arr2[m]) <= d){
                     f= false;
                     break;
                }
                else if(num < arr2[m]){
                    h = m-1;
                }
                else if(num>arr2[m]){
                    l = m+1;
                }
                
              }

              if(f)ans++;
        }
        return ans;
    }
};