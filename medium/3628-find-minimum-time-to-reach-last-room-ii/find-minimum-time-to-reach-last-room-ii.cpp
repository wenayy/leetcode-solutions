class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n=moveTime.size();
        int m=moveTime[0].size();
       priority_queue<
    pair<int, pair<int, int>>,
    vector<pair<int, pair<int, int>>>,
    greater<pair<int, pair<int, int>>>
> pq;
         
        int k=0;
        pq.push({0,{0,0}});
       
        vector<pair<int,int>>dir={{1,0},{-1,0},{0,-1},{0,1}};
        vector<vector<int>>ans(n,vector<int>(m,INT_MAX));
               vector<vector<int>> v(n, vector<int>(m, 0));
        while(!pq.empty()){
            int a=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            if(v[x][y]) continue;
            v[x][y]=1;
            for(auto r:dir){
                int nx=x+r.first;
                int ny=y+r.second;
                if(nx<0 || nx>=n|| ny<0 || ny>=m) continue;
                int temp=2;
                int diff=max(moveTime[nx][ny]-a,0) ;// for adding 1 or 2 
                int vinay=a+diff;
                if((nx+ny)%2)  temp=1;

                
                 
                vinay+=temp;
             
    if  (  ans[nx][ny]>vinay){
        ans[nx][ny]=vinay;
        pq.push({vinay,{nx,ny}});

    }
              
                
;            }
            


        }
        return ans[n-1][m-1];
        
    }
};