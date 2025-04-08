class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n=nums.size();
        if(n==0) return 0;

        int ans=0;  
    unordered_set<int>st;
    for(auto x:nums){
        st.insert(x);
    }
 
for(auto x:st){
     
    if(st.find(x-1)==st.end()){
      int  curr_num=x;
       int currlength=1;
       while(st.find(curr_num+1)!=st.end()){
        curr_num=curr_num+1;
        currlength+=1;
        
       }
       ans=max(currlength,ans);

    }
   

}
        
 return ans;



    }
};