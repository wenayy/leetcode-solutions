class Solution {
public:
    int halveArray(vector<int>& nums) {
        long long sum=accumulate(nums.begin(),nums.end(),0LL);
        priority_queue<double>pq;
       for(auto x:nums){
        pq.push(x);
       }
        int ans=0;
         double k=sum;
          
        
        while((sum/2.0)<k){
             
          double x=pq.top();
            pq.pop();
            double temp=x/2;
            k-=temp;
            pq.push(temp);
             ans++;
         
       
        }
        return ans;

    }
};