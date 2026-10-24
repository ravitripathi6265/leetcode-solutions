class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int am1 = stoi(arriveAlice.substr(0, 2));
        int ad1 = stoi(arriveAlice.substr(3, 2));

        int am2 = stoi(leaveAlice.substr(0, 2));
        int ad2 = stoi(leaveAlice.substr(3, 2));

        int bm1 = stoi(arriveBob.substr(0, 2));
        int bd1 = stoi(arriveBob.substr(3, 2));

        int bm2 = stoi(leaveBob.substr(0, 2));
        int bd2 = stoi(leaveBob.substr(3, 2));

       
        int sm, sd;
        if (am1 > bm1 || (am1 == bm1 && ad1 > bd1)) {
            sm = am1;
            sd = ad1;
        } else {
            sm = bm1;
            sd = bd1;
        }

        int em, ed;
        if (am2 < bm2 || (am2 == bm2 && ad2 < bd2)) {
            em = am2;
            ed = ad2;
        } else {
            em = bm2;
            ed = bd2;
        }

        if (sm > em || (sm == em && sd > ed))
            return 0;

        int days[] = {0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31};

        int start = sd, end = ed;

        for (int i = 1; i < sm; i++)
            start += days[i];

        for (int i = 1; i < em; i++)
            end += days[i];

        return end - start + 1;
    }
};