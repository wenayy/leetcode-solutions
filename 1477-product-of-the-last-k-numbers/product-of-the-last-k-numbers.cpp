class ProductOfNumbers {
 public:
 vector<int>m;
  
          
         stack<int>st;
    ProductOfNumbers() {
          
    }
    
    void add(int num) {
        m.push_back(num);
        
    }
         
    
    int getProduct(int k) {
 
 int n=m.size();
 
 int ans=1;
 if(k>n) return 0;

     for(int i=n-k;i<n;i++){
        ans*=m[i];
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