class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
int ans=0;
 for(int j=low;j<=high;j++){
    string temp=to_string(j);
    long long k=0;
    long long r=0;
    if (temp.length()%2==0){
    for(int i=0;i<temp.length()/2;i++){
        k+=(temp[i]-'0');
        r+=(temp[i+temp.length()/2]-'0');


    }
    if(k==r){ ans++; cout<<temp<<endl;}
    }
 }

       return ans; 

    }
};