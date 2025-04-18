class Solution {
public:
 

int compress(vector<char>& chars) {
    vector<string> st;
    int count = 1;
    vector<pair<char, int>> temp;

    // Grouping chars and counts
    for (int i = 1; i < chars.size(); i++) {
        if (chars[i] == chars[i - 1]) {
            count++;
        } else {
            temp.push_back({chars[i - 1], count});
            count = 1;
        }
    }
    temp.push_back({chars.back(), count}); // last group

    // Debug output
    for (auto p : temp) {
        cout << p.first << " -> " << p.second << endl;
    }

    // Build string vector
     chars.clear();  // \U0001f525 clear chars to rebuild from temp
    for (auto& p : temp) {
        chars.push_back(p.first);
        if (p.second > 1) {
            string cnt = to_string(p.second);
            for (char c : cnt) chars.push_back(c);  // split digits
        }
    }


    return chars.size();
}

};