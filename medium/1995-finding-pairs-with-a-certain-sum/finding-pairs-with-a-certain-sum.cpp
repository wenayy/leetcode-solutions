class FindSumPairs {
public:
    vector<int> nums1, nums2;
    unordered_map<int,int>mp;
   
    

    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for(auto x:nums2){
            mp[x]++;
        }
        
        
    }
    
    void add(int index, int val) {
        mp[nums2[index]]--;
        nums2[index] += val;
        mp[nums2[index]]++;
        
        
           
    }
    
    int count(int tot) {
      int n=nums1.size();

 
        int ans = 0;
        for (int i = 0; i < n; i++) {
            
     long long target = tot - nums1[i];
           if (mp.count(target)){
            ans+=mp[target];

           }
        }

        return ans;
    }
};
