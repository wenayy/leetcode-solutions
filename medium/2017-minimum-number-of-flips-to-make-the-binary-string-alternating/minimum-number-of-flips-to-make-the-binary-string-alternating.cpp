class Solution {
public:
    int minFlips(string s) {
        int n= s.length();
        bool answer= true;
        for (int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]) continue;
            else answer = false;
            
        }
     if (answer == true ) return 0;
     
        s= s+s;
        
        string s2,s1;
        
        
        for(int i=0;i<2*n;i++){
          s1+=(i%2 ? '0':'1');
          s2+=(i%2?'1':'0');
         
        }
     int result = INT_MAX;  
      int f2=0;
      int f1=0;

    int i=0;
    int j=0;
    while(j<2*n){

        if(s1[j]!=s[j]) f1++;

        if(s2[j]!=s[j])f2++;

       
        if(j-i+1>n)  {
           
            if(s1[i]!=s[i]) f1--;
            if(s2[i]!=s[i]) f2--;
             i++;
 
        }

         if(j-i+1==n) result=min(result,min(f1,f2));
        j++;

    }

    return result;


     
     
         
    }
};