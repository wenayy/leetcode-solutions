class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
      priority_queue<int>pq;
      for(auto x:stones){
        pq.push(x);
      }

      while(pq.size()>0){
        if(pq.size()==1) return pq.top() ;
        int y=pq.top();
        pq.pop();
        int x=pq.top();
        pq.pop();
        int rem=abs(y-x);
        if(rem==0) continue;
        else pq.push(rem);


      }
      return 0;
      

    }
};