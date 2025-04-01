class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>mp;
        
        stringstream ss(s);
        vector<string>r;
        string word;
        while(ss >> word){
            r.push_back(word);
        }
        if(pattern.length()!=r.size()) return false;
        for(int i=0;i<pattern.length();i++){
            if(mp.find(pattern[i])==mp.end()) {mp[pattern[i]]=r[i];}
            else if(mp[pattern[i]]!=r[i]) return false;
        }
        int n=mp.size(); 
        set<string>repeat;
        for(auto x:mp){
            repeat.insert(x.second);
        }
        if(repeat.size()!=n) return false;
        return true;
    }
};