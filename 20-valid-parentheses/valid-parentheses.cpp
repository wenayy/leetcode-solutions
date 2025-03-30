
class Solution {
 
public:
    bool isValid(string s) {
        if(s.length()==1) return false;
         stack<char>st;
        int n=s.length();
        
        for(int i=0;i<n;i++){
    if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            }
  else if(s[i]==')' && st.size()>0  ){
    
    if(st.top()!='(') return false;
    st.pop();
  }
  else if(s[i]=='}' && st.size()>0  ){
    if(st.top()!='{') return false;
    st.pop();
  }
else if(s[i]==']' && st.size()>0  ){
    if(st.top()!='[') return false;
    st.pop();
  }   

     else return false; 
   
        }
      if(st.size()>0) return false;
       return true;
        
    }
};