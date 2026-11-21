
class Solution {
public:
    vector<vector<int>> adj, newTree;
    vector<int> ans, last;

    void dfs(int u, string &s) {
        int c = s[u] - 'a';
        int prev = last[c];

        last[c] = u;

        for (int v : adj[u]) {
            int d = s[v] - 'a';

            if (last[d] != -1) {
                newTree[last[d]].push_back(v);
            } 
            else {
                newTree[u].push_back(v);
            }

            dfs(v, s);
        }

        last[c] = prev;
    }

    int dfs2(int u) {
        int sz = 1;

        for (int v : newTree[u]) {
            sz += dfs2(v);
        }

        ans[u] = sz;
        return sz;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        adj.resize(n);
        newTree.resize(n);
        ans.resize(n);
        last.assign(26, -1);

        for (int i = 1; i < n; i++) {
            adj[parent[i]].push_back(i);
        }

        dfs(0, s);
        dfs2(0);

        return ans;
    }
};
