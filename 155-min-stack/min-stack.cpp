class MinStack {
public:
  vector<int>st;
    MinStack() {
    

        
    }
    
    void push(int val) {
       st.push_back(val);
        
    }
    
    void pop() {
        
       st.erase(st.begin()+st.size()); 
          }
    
    int top() {
        return st[st.size()-1];
        
    }
    
    int getMin() {
        int mx=INT_MAX;
        for(int i=0;i<st.size();i++){
          mx=  min(mx,st[i]);

        }return mx;
        
    }
};

/**
 * Your Minst object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */