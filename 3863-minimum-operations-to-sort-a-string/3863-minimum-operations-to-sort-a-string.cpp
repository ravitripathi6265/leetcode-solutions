
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        bool k = true;

        for (int i = 1; i < n; i++) {
            if (s[i] < s[i - 1]) {
                k = false;
                break;
            }
        }

        if (k) return 0;
        if (n == 2) return -1;

        char sc = *min_element(s.begin(), s.end());
        char lc = *max_element(s.begin(), s.end());

        if (s[0] == sc || s[n - 1] == lc)
            return 1;

        for (int i = 1; i < n - 1; i++) {
            if (s[i] == sc || s[i] == lc)
                return 2;
        }

        return 3;
    }
};
