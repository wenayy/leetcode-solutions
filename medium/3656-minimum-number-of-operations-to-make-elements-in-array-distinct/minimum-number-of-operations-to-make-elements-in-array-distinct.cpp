class Solution {
public:
    int minimumOperations(vector<int>& nums) {
       int k=0;
       int n=nums.size();
       while(n>0){
        
        set<int>s(nums.begin(),nums.end());
        if(s.size()==nums.size()) return k;
       else{ 
        if(nums.size()<3){ k++; return k;}
        nums.erase(nums.begin(),nums.begin()+3);
        k++;}

       }
       return 0;
    }
};