class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int m= grid.size();
        int n = grid[0].size();
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                 if(grid[i][j] == 1){
                    int f = 0;
                    for(int k = 0;k<m;k++){
                        if(k == i)continue;
                        if(grid[k][j] == 1){
                            f = 1;
                            break;
                        }
                    }
                    if(f == 0){
                          for(int k = 0;k<n;k++){
                        if(k == j)continue;
                        if(grid[i][k] == 1){
                            f = 1;
                            break;
                        }
                    }
                    }
                    if(f)ans++;
                 }
            }
        }
        return ans;
    }
};