class Solution {
public:
    string removeOccurrences(string s, string part) {
        
    size_t pos = s.find(part);  // Find the first occurrence  

    while (pos != string::npos) { // While occurrences are found  
        s.erase(pos, part.length()); // Erase the occurrence  
        pos = s.find(part);          // Find the next occurrence  
    }  

    return s;      
              
        
        
    }
};