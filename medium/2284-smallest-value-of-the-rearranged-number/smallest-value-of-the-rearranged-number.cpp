class Solution {
public:
    long long smallestNumber(long long num) {
     long long n = abs(num);
     vector<int>number;
     while(n){
        number.push_back(n%10);
        n/=10;
     }
     sort(number.begin(),number.end());
     int k= number.size();
     if(num>=0){
        for(int i=0;i<k;i++){
        if(number[i]!=0){
            swap(number[i],number[0]);
            break;
        }

     }
     
     
      

     }
    else if(num<0){
        sort(number.begin(),number.end(),greater<int>());
    }
    long long ans=0;
     for(int i=0;i<k;i++){
        ans=ans*10+number[i];
     }
     return num>0 ? ans:-ans;
    }
     
};