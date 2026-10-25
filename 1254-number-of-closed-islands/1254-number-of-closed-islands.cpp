class Solution {
public:
    void bfs(int i,int j,vector<vector<int>>&vis,vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        vis[i][j] = 1;
        while(!q.empty()){
            int x = q.front().first;
            int y= q.front().second;
            q.pop();
            int dx[] = {-1,0,0,1};
            int dy[] = {0,-1,1,0};
            for(int k = 0;k<4;k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(nx>=0 && ny>=0 && nx<n && ny<m && !vis[nx][ny] && grid[nx][ny] == 0){
                      vis[nx][ny] = 1;
                      q.push({nx,ny});
                }
            }
        }
        

    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++){
            if(grid[i][0] == 0){
                bfs(i,0,vis,grid);
            }
            if(grid[i][m-1] == 0){
                bfs(i,m-1,vis,grid);
            }
        }
         for(int j = 0;j<n;j++){
            if(grid[0][j] == 0){
                bfs(0,j,vis,grid);
            }
            if(grid[n-1][j] == 0){
                bfs(n-1,j,vis,grid);
            }
        }
        int ans = 0;
        for(int i = 1;i<n-1;i++){
            for(int j = 1;j<m-1;j++){
                if(!vis[i][j] && grid[i][j] == 0){
                    ans++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return ans;
    }
};