class ProductOfNumbers {
public:
    vector<int>n;
    ProductOfNumbers() {
      n = {};

    }
    
    void add(int num) {
    
        n.push_back(num);
    }
    
    int getProduct(int k) {
        int l = n.size();
        int i = l-1;
         int ans = 1;
         while(k>0){
             ans*= n[i];
             i--;
             k--;
         }
         return ans;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */