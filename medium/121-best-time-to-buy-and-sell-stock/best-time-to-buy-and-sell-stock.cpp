class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans=0;
        int n=prices.size();
      stack<int>st;
      st.push(prices[0]);
      for(int i=1;i<n;i++){

        if(prices[i]<st.top()) st.pop(),st.push(prices[i]);
        else{
            ans=max(ans, prices[i]-st.top());
        }
      }


    return ans;
        
        
    }
};