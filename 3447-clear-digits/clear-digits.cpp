class Solution {
public:
    string clearDigits(string s) {
        string res;
        for(auto i:s){
           if (i >= '0' && i <= '9' && !res.empty()) {  
    res.pop_back();  
}
            else res.push_back(i);
        }
        return res;
    }
};