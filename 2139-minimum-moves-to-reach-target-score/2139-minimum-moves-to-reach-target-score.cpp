class Solution {
public:
    int minMoves(int target, int md) {
        int ans = 0;
        while(target != 1){
            if(target %2 == 0){
                if(md>0){
                    target= target/2;
                    ans++;
                    md--;
                }
                else{
                    return ans + target -1;
                }
            }
            else {
                target--;
                ans++;
            }
        }
        return ans;
    }
};