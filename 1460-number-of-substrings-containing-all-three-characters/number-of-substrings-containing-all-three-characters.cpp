class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int ans=0;
int i=0;int j=0;
unordered_map<char,int>mp;
while(j<n){
    mp[s[j]]++;
     
    while (mp['a'] >= 1 && mp['b'] >= 1 && mp['c'] >= 1) {
        ans+=(n-j);  
        mp[s[i]]--;  
        i++;
    }
     j++;
     


}
        
        return ans; 

    }
};