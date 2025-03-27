class Solution {
public:
    int reverse(int x) {
        if(x==0 || x<=INT_MIN|| x>=INT_MAX) {return 0;}
      long long  ans=0;
      if(x>0){
            string s=to_string(x);
            int n=s.length();
            int i=0;
            int j=n-1;
            while(i<=j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            ans=stoll(s);
            if (ans <= INT_MIN || ans >= INT_MAX) {  
            return 0;  
        } 
        else return ans;
         
           
            
        }

      
            string s=to_string(x);
            int n=s.length();
            int i=1;
            int j=n-1;
            while(i<=j){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            ans=stoll(s);
            
             
          if (ans < INT_MIN || ans > INT_MAX) {  
            return 0;  
        } 
        else return ans;
         
    }
};