class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
   
       long long  z1=0,z2=0;
     long long s1=0,s2=0;
        for(auto x:nums1){
            if(x==0)z1++;
            else  s1+=x;
        }
         for(auto x:nums2){
            if(x==0)z2++;
            else  s2+=x;
        }
          
        
                if (!z1 && s2+z2 > s1+z1 || !z2 && s1+z1 > s2+z2) {
            return -1;
        }
      return max(s1+z1,s2+z2);
   


        
    }
};