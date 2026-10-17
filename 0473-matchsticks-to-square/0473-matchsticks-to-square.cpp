class Solution {
public:
    bool f(int i, vector<int>& mt, int tt, vector<int>& sides) {
        int n = mt.size();

        if (i == n) {
            return sides[0] == tt &&
                   sides[1] == tt &&
                   sides[2] == tt &&
                   sides[3] == tt;
        }

        for (int j = 0; j < 4; j++) {
            if (sides[j] + mt[i] > tt)
                continue;

            sides[j] += mt[i];

            if (f(i + 1, mt, tt, sides))
                return true;

            sides[j] -= mt[i];
            if (sides[j] == 0)
                break;
        }

        return false;
    }

    bool makesquare(vector<int>& mt) {
        int n = mt.size();
        if (n < 4) return false;

        int sum = 0;
        for (int x : mt)
            sum += x;

        if (sum % 4 != 0)
            return false;

        int tt = sum / 4;

        for (int x : mt) {
            if (x > tt)
                return false;
        }

        sort(mt.rbegin(), mt.rend());

        vector<int> sides(4, 0);

        return f(0, mt, tt, sides);
    }
};