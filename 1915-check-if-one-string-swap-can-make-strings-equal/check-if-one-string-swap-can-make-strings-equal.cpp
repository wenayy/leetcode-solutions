class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int swap=0;
        vector<char>s11;
        vector<char>s22;
        for (int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]) {swap++; s11.push_back(s1[i]);  s22.push_back(s2[i]);}
            if(swap>2) return false;
            
            

        }if(swap==1) return false;
        return ((s11[0]==s22[1]) && (s11[1]==s22[0]));
    }
};