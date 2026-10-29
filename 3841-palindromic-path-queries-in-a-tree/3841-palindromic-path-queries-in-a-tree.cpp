class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        const int LOG = 17; // 2^16 = 65536 > 5 * 10^4
        vector<vector<int>> up(LOG, vector<int>(n, 0));
        vector<int> depth(n, 0), tin(n, 0), tout(n, 0), it(n, 0);

        // iterative DFS
        int timer = 1;
        vector<int> st;
        st.push_back(0);
        tin[0] = timer++;
        while (!st.empty()) {
            int u = st.back();
            if (it[u] < (int)adj[u].size()) {
                int w = adj[u][it[u]++];
                if (w == up[0][u]) continue; // parent (root's "parent" is 0, never a neighbor of itself)
                up[0][w] = u;
                depth[w] = depth[u] + 1;
                tin[w] = timer++;
                st.push_back(w);
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }

        for (int k = 1; k < LOG; k++)
            for (int v = 0; v < n; v++)
                up[k][v] = up[k - 1][up[k - 1][v]];

        auto lca = [&](int a, int b) {
            if (depth[a] < depth[b]) swap(a, b);
            int diff = depth[a] - depth[b];
            for (int k = 0; k < LOG; k++)
                if (diff >> k & 1) a = up[k][a];
            if (a == b) return a;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][a] != up[k][b]) {
                    a = up[k][a];
                    b = up[k][b];
                }
            }
            return up[0][a];
        };

        // Fenwick tree: range XOR update, point query
        int sz = n + 2;
        vector<int> bit(sz + 1, 0);
        auto add = [&](int i, int val) {
            for (; i <= sz; i += i & -i) bit[i] ^= val;
        };
        auto point = [&](int i) {
            int r = 0;
            for (; i > 0; i -= i & -i) r ^= bit[i];
            return r;
        };
        auto rangeXor = [&](int u, int val) {
            add(tin[u], val);
            add(tout[u] + 1, val);
        };

        vector<int> mask(n);
        for (int i = 0; i < n; i++) {
            mask[i] = 1 << (s[i] - 'a');
            rangeXor(i, mask[i]);
        }

        vector<bool> ans;
        for (auto& q : queries) {
            istringstream iss(q);
            string type;
            iss >> type;
            if (type == "update") {
                int u;
                char c;
                iss >> u >> c;
                int nm = 1 << (c - 'a');
                if (nm != mask[u]) {
                    rangeXor(u, mask[u] ^ nm);
                    mask[u] = nm;
                }
            } else {
                int u, v;
                iss >> u >> v;
                int l = lca(u, v);
                int m = point(tin[u]) ^ point(tin[v]) ^ mask[l];
                ans.push_back((m & (m - 1)) == 0);
            }
        }
        return ans;
    }
};