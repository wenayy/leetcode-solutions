class Solution {
      string invert(string m){
             for(auto & x:m){
                if(x=='1') x='0';
                else x='1';
                
             }
             return m;

        }
public:
    char findKthBit(int n, int k) {
      
    
        
        vector<string>stored;
        stored.push_back("0");
        for(int i=2;i<=n;i++){
            string inverted= invert(stored[i-2]);
            reverse(inverted.begin(),inverted.end());
           string  si=stored[i-2]+"1"+ inverted;
           stored.push_back(si);

            
        }
       // int l= stored.size();

     return stored[n-1][k-1];


        
    }
};