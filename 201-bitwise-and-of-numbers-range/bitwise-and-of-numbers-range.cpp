class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left==right) return left;
        int shift=0;
         while(left!=right){
            shift++;
            left=left>>1;
            right=right>>1;
            
         }
         left =left<<shift;
         return left;
    }
};