class Solution {
public:
    
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false; 
            left++;
            right--;
        }
        return true;
    }

    string longestPalindrome(string s) {
        int n = s.length();
        string ans = "";

       
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isPalindrome(s, i, j)) {
                    string sub = s.substr(i, j - i + 1);
                    if (sub.size() > ans.size()) {
                        ans = sub;  
                    }
                }
            }
        }

        return ans;
    }
};
