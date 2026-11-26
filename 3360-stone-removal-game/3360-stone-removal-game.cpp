class Solution {
public:
    bool canAliceWin(int n) {
        int x =10;
        int i = 0;
        while(n>=0){
            if(i%2 ==0){
                if(x<=n){
                    n-=x;
                    x--;
                    i++;
                }
                else return false;

            }
            else {
                if(x<=n){
                    n-=x;
                    x--;
                    i++;
                }
                else return true;
            }
        }
        return true;
    }
};