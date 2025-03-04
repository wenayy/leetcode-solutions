class Solution {
public:
    bool checkPowersOfThree(int n) {
        vector<int>seen;
        while(n>0){
            int temp =  (log(n)/log(3));
            while (pow(3, temp + 1) <= n) {
                temp++;
            }
            
            if( find(seen.begin(),seen.end(),temp)!=seen.end()) {return false;}
       seen.push_back(temp);

            n -= static_cast<int>(pow(3, temp));   
            
        }

return true;

    }
};