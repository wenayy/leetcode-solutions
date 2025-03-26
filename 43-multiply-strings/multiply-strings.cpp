class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0"; // Edge case: multiplication by zero
        
        int n = num1.size(), m = num2.size();
        vector<int> res(n + m, 0);  
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + res[i + j + 1];  
                res[i + j + 1] = sum % 10; // Store last digit
                res[i + j] += sum / 10;    // Carry forward
            }
        }

        
        string ans = "";
        for (int num : res) {
            if (!(ans.empty() && num == 0))  
                ans += to_string(num);
        }

        return ans.empty() ? "0" : ans;
    }
};
