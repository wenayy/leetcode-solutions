class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int k=*max_element(nums2.begin(),nums2.end());
        vector<int>ans(k+1,-1);
        stack<int>st;
        
        
        for(int i=0;i<nums2.size();i++){
            while(!st.empty() && nums2[st.top()]<nums2[i]){
                ans[nums2[st.top()]]=nums2[i]; st.pop();  
            }
            st.push(i);

        }
        vector<int>result(n);
        for(int i=0;i<n;i++)
{
    result[i]=ans[nums1[i]];
}   

return result;
    }
};