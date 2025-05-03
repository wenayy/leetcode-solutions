class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       unordered_map<int,int>mp;
    unordered_map<int,int>top;
        unordered_map<int,int>bottom;
        
        for(auto x:tops){
            mp[x]++;
            top[x]++;
           
        }
        for(auto y:bottoms){
           bottom[y]++;
            mp[y]++;
        }
        int ans=0;
        for(auto x:mp){
            ans=max(x.second,ans);
             
        }
       
        int result1=0;
        int result2=0;
     auto kt = std::max_element(top.begin(), top.end(),
    [](const auto &a, const auto &b) {
        return a.second < b.second;  // Compare frequencies (values)
    });

auto mt = std::max_element(bottom.begin(), bottom.end(),
    [](const auto &a, const auto &b) {
        return a.second < b.second;
    });

int mx = std::max(kt->second, mt->second);  // max frequency

int key_with_max_freq;
if (kt->second >= mt->second)
   { key_with_max_freq = kt->first;}
else
   { key_with_max_freq = mt->first; }
   cout<<key_with_max_freq<<endl;
   
for(int i=0;i<tops.size();i++){

 
    if(tops[i]!=key_with_max_freq)  {
      
     
        if(bottoms[i]==key_with_max_freq) {result1++;}
        else return -1;}
     
}
for(int i=0;i<bottoms.size();i++){

 
    if(bottoms[i]!=key_with_max_freq)  {
      
     
        if(tops[i]==key_with_max_freq) {result2++;}
        else return -1;}
     
}
return min(result1,result2);
        
    }
};