class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
       uint32_t ans=0;
      string k=bitset<32>(n).to_string();
       int i=0;
       int j=31;
       while(i<=j){
        swap(k[i],k[j]);
        i++;
        j--;
       }
   
       ans=stoll(k, nullptr, 2);
       return ans;

        
    }
};