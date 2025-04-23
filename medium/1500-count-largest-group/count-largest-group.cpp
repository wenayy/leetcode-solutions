class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        for(int i=1;i<=n;i++){
         int temp=i;
          int sum = 0; // To store the sum of the digits  
while (temp > 0) {  
    sum += temp % 10; // Get the last digit and add it to sum  
    temp = temp / 10;    // Remove the last digit  
}   
            mp[sum]++;

        }
        int mx=0;
        for(auto x:mp){
            int r=x.second;
mx=max(r,mx);
 

        }
       
        int ans=0;
        for(auto x:mp){
            if(x.second==mx) ans++;
        }

return ans;
    }
};