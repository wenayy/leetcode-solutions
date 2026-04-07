class Robot {
public:
int x,y;
int w,h;
int dir;
int perimeter;
vector<string>directions={"East","North","West","South"};

    Robot(int width, int height) {
        w=width;
        h=height;
         x=0;
         y=0;
         dir=0;
         perimeter=2*(width+height)-4;



       

    }
    
    void step(int num) {
          if (perimeter == 0) return;
        num%=perimeter;
        if(num==0 && x==0 && y==0){
           
            dir=3;
            return;
        }
        
        while(num--){
            if(dir==0){
             if(x+1<w) x++;
             else {
                 dir=1;
                y++;
             }
            }
           else if(dir==1){
                if(y+1<h) y++;
                else dir=2, x--;
            }
           else if(dir==2){
                if(x>0) x--;
                else dir=3, y--;
            }
            else {
                if(y>0)y--;
                else dir=0,x++;
            }

        }
        
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
     return   directions[dir];
        
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */