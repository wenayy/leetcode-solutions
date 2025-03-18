class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
     bitset<32>binary(left);
           string l = binary.to_string();
        string r = bitset<32>(right).to_string();

        int len = 32;

        int sum = 0;

        for(int i =0;i<len;i++){
            if(l[i]==r[i]){
                if(l[i]=='1'){
                    sum+=(pow(2,len-i-1));
                }
            }
            else{
                break;
            }
        }

        return sum;

    }
};