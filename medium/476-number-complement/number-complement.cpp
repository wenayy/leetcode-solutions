class Solution {
public:
    int findComplement(int num) {
        int k= floor(log2(num))+1;
        int mask = 1>>k;
        while(mask<num){
            mask= mask<<1| 1;
        }
        return mask^num;
    }
};