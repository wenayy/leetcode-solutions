class Solution {
public:
    bool checkOnesSegment(string s) {
         string temp ="01";
         int c =0;
       int count1 = count(s.begin(), s.end(), '1');
cout << count1;
         for (int i=1;i<s.length()-1;i++){
            if(s[i]=='0' && s[i+1]=='1') c ++;
            

            

         }
         if(c >=1 && count1>1) return false;
         return true;
    }
};