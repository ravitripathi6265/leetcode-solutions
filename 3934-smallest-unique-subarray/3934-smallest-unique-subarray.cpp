class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxn = 2 * n + 2;

        vector<unordered_map<int, int>> nxt(maxn);
        vector<int> link(maxn, -1), len(maxn, 0), cnt(maxn, 0);

        int sz = 1, last = 0;

        for (int x : nums) {
            int cur = sz++;
            len[cur] = len[last] + 1;
            cnt[cur] = 1;               // non-clone states end at one position

            int p = last;
            while (p != -1 && !nxt[p].count(x)) {
                nxt[p][x] = cur;
                p = link[p];
            }

            if (p == -1) {
                link[cur] = 0;
            } else {
                int q = nxt[p][x];
                if (len[p] + 1 == len[q]) {
                    link[cur] = q;
                } else {
                    int clone = sz++;
                    len[clone] = len[p] + 1;
                    nxt[clone] = nxt[q];
                    link[clone] = link[q];
                    cnt[clone] = 0;

                    while (p != -1 && nxt[p].count(x) && nxt[p][x] == q) {
                        nxt[p][x] = clone;
                        p = link[p];
                    }
                    link[q] = link[cur] = clone;
                }
            }
            last = cur;
        }

        // counting sort of states by length, then propagate counts up suffix links
        vector<int> bucket(n + 2, 0), order(sz);
        for (int i = 0; i < sz; i++) bucket[len[i]]++;
        for (int i = 1; i <= n; i++) bucket[i] += bucket[i - 1];
        for (int i = sz - 1; i >= 0; i--) order[--bucket[len[i]]] = i;

        for (int i = sz - 1; i > 0; i--) {
            int v = order[i];
            cnt[link[v]] += cnt[v];
        }

        int ans = n;
        for (int v = 1; v < sz; v++) {
            if (cnt[v] == 1)
                ans = min(ans, len[link[v]] + 1);
        }
        return ans;
    }
};