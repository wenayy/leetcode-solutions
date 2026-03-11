class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        double k=floor(log2(n))+1;
          int temp= pow(2,k)-1;
          return temp^n ;

    }
};