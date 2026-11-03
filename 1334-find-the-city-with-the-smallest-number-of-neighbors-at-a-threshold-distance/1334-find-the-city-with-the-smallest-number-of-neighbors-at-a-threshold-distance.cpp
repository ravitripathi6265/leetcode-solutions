class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i = 0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int d = edges[i][2];
            adj[u][v] = d;
            adj[v][u] = d;
        }
        for(int i = 0;i<n;i++){
                 adj[i][i] = 0;
              }

        for(int via = 0;via<n; via++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    adj[i][j] = min(adj[i][j], adj[i][via] + adj[via][j]);
                }
            }
        }
       int at = INT_MAX;
       int ans;
       for(int i = 0;i<n;i++){
            int ct = 0;
            for(int j = 0;j<n;j++){
                if(adj[i][j]<=dt)ct++;
            }
            if(at>ct){
                ans = i;
                at = ct;
            }
            if(at== ct){
                  ans = max(ans,i);
            }

       }
       return ans;

    }
};