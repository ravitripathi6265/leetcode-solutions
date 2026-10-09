class Solution {
public:
    int hammingDistance(int x, int y) {
       int ans = x^y;
       int a  = 0;
       while(ans!= 0){
          int r = ans%2;
          if(r)a++;
          ans = ans/2;
       }
       return a;
    }
};