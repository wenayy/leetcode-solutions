class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n= nums.size();
        int j=0;
        string answer;
         for (int i=0;i<n;i++){
            if(nums[i][j]=='0') answer+='1';
            else answer+='0';
            j++;

         }
         return answer;
        

        
    }
};