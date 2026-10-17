class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
         vector<tuple<int,int,int>>dsum;
        
        for(int i = 0;i<n;i++){
            int num = nums[i];
            int s = 0;
            while(num>0){
                s +=num%10;
                num/=10;
            }
            dsum.push_back({s,nums[i],i});
        }
        sort(dsum.begin(),dsum.end());
        int ans = 0;
        vector<bool>vis(n,false);
        for(int i = 0;i<n;i++){
            if(vis[i] || get<2>(dsum[i]) == i){
                continue;
            }

            int ct = 0;
            int j = i;
            while(vis[j] == false){
                vis[j] = true;
                j = get<2>(dsum[j]);
                ct++;
            }
            ans = ans+ct-1;
        }
        return ans;

       
    }
};