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
       
sort(nums1.begin(),nums1.end());
       
int index=lower_bound(nums1.begin(),nums1.end(),tot)-nums1.begin();
        int ans = 0;
        for (int i = 0; i < index; i++) {
            
     long long target = tot - nums1[i];
            ans += mp[target];
        }

        return ans;
    }
};
