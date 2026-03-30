class Solution {
public:
    bool checkStrings(string s1, string s2) {
        vector<char>odd(26,0);
         vector<char>even(26,0);
        for(int i=0;i<s1.length();i++){
            if(i&1){
            odd[s1[i]-'a']++;
            odd[s2[i]-'a']--;
            }
            else {
                even[s1[i]-'a']++;
                 even[s2[i]-'a']--;
            }

        }
         

         for(auto x: odd ){
            if (x!=0)return false;
         }
         for(auto x: even ){
            if (x!=0)return false;
         }
        return true;

        
    }
};