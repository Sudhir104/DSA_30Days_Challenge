class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();   // Length of input string

        string store;          // Temporary string to store each word
        vector<string> str;    // Vector to store all words from the string
        stringstream sttr(s);  // String stream to extract words from input string

        // Extract words from the input string and store in vector
        while(sttr >> store){
            str.push_back(store);
        }

        string result = "";        // String to store the final reversed sentence
        int m = str.size() - 1;    // Index of last word in vector

        // Traverse the vector in reverse to form reversed sentence
        for(int i = m; i >= 0; i--){
            result += str[i];       // Add current word to result
            if(i != 0) result += " "; // Add space between words (except after last word)
        }

        return result;              // Return the reversed sentence
    }
};
