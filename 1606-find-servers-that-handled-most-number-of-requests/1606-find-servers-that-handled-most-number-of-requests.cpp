
class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        int n = arrival.size();

        set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }

        // {free time, server ID}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> count(k, 0);

        for (int i = 0; i < n; i++) {

            // Release completed servers
            while (!pq.empty() && pq.top().first <= arrival[i]) {
                available.insert(pq.top().second);
                pq.pop();
            }

            if (available.empty()) continue;

            int target = i % k;

            auto it = available.lower_bound(target);

            if (it == available.end()) {
                it = available.begin();
            }

            int server = *it;

            available.erase(it);

            count[server]++;

            pq.push({arrival[i] + load[i], server});
        }

        int maxi = *max_element(count.begin(), count.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (count[i] == maxi) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
