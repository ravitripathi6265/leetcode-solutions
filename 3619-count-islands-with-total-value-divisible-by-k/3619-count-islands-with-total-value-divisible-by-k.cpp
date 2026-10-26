class Solution {
public:
    bool bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid,long long  &sum,int k){
            int n= grid.size();
            int m = grid[0].size();
            sum = sum + grid[i][j];
            vis[i][j] = 1;
            queue<pair<int,int>>q;
            q.push({i,j});
            while(!q.empty()){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                int dx[] = {-1,0,0,1};
                int dy[] = {0,-1,1,0};
                for(int k = 0;k<4;k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny] != 0){
                        vis[nx][ny] =1;
                        sum = sum + grid[nx][ny];
                        q.push({nx,ny});
                    }
                }
            }
            return sum %k == 0;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!vis[i][j] && grid[i][j] != 0){
                      long long  sum = 0;
                      if(bfs(i,j,vis,grid,sum,k))ans++;
                }
            }
        }
        return ans;
    }
};