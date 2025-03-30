class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        // Convert all times to minutes
        int start1 = convertToMinutes(event1[0]);
        int end1 = convertToMinutes(event1[1]);
        int start2 = convertToMinutes(event2[0]);
        int end2 = convertToMinutes(event2[1]);
        
        // Check for overlap
        return !(end1 < start2 || end2 < start1);
    }
    
private:
    int convertToMinutes(const string& time) {
        int hours = stoi(time.substr(0, 2));
        int minutes = stoi(time.substr(3, 2));
        return hours * 60 + minutes;
    }
};