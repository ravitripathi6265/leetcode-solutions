class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<long long >dis(n,LLONG_MAX);
        vector<int>pc(n,0);
        vector<vector<pair<int,long long>>>adj(n);
        for(int i = 0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            long long t = roads[i][2];
            adj[u].push_back({v,t});
            adj[v].push_back({u,t});
        }
        priority_queue<pair<long long,int>,
           vector<pair<long long,int>>, greater<pair<long long,int>>>pq;
           pq.push({0,0});
        dis[0] = 0;
        pc[0] = 1;
        int m = 1e9 + 7;
        while(!pq.empty()){
            int node = pq.top().second;
            long long tt = pq.top().first;
            pq.pop();
            if(tt > dis[node])continue;

            for(auto &it : adj[node]){
                     int nd = it.first;
                     long long nt = it.second;
                     if(nt + tt <= dis[nd]){

                      if(nt + tt == dis[nd]){
                        pc[nd] = (pc[nd] + pc[node]) %m;
                      }
                      else {
                        dis[nd] = nt + tt;
                        pc[nd] = pc[node];
                        pq.push({tt+nt,nd});
                      }

                     }
            }

        }
return pc[n-1];

    }
};