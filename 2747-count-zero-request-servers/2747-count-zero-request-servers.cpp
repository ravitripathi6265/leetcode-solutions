
class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        vector<pair<int,int>> q;

        for(int i = 0; i < queries.size(); i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        vector<int> freq(n + 1, 0);
        vector<int> ans(queries.size(), 0);

        int l = 0, r = 0;
        int cnt = 0;

        for(auto &it : q) {

            int t = it.first;
            int idx = it.second;

            // Add logs inside the right boundary
            while(r < logs.size() && logs[r][1] <= t) {

                int id = logs[r][0];

                if(freq[id] == 0) cnt++;

                freq[id]++;
                r++;
            }

            // Remove logs outside the left boundary
            while(l < r && logs[l][1] < t - x) {

                int id = logs[l][0];

                freq[id]--;

                if(freq[id] == 0) cnt--;

                l++;
            }

            ans[idx] = n - cnt;
        }

        return ans;
    }
};
