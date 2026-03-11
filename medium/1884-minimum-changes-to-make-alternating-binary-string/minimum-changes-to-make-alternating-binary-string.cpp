class Solution {
public:
    int minOperations(string s) {
        string s2 , s1;

        for (int i=0;i<s.length();i++){
            s1+= (i%2?'0':'1');
            s2+=(i%2?'1':'0');
        }
        
        int f2=0,f1=0;
        for (int i=0;i<s.length();i++){
            if(s[i]!=s1[i]) f1++;
            if (s[i]!=s2[i])f2++;
        }
        return min(f1,f2);
      
        
        
    }
};