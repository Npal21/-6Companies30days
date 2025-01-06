
//Link: https://leetcode.com/problems/maximum-product-of-the-length-of-two-palindromic-subsequences/

class Solution {
public:
    // Function to compute the Longest Common Subsequence (LCS) of two strings
    int lcs(string a, string b) {
        int n = a.length(), m = b.length();
        // Using two 1D vectors to optimize space complexity
        vector<int> prev(m + 1, 0), curr(m + 1, 0);

        // Iterating over each character of both strings
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                // If characters match, increment LCS length
                if (a[i - 1] == b[j - 1]) 
                    curr[j] = 1 + prev[j - 1];
                else 
                    // Otherwise, take the maximum LCS length from previous states
                    curr[j] = max(prev[j], curr[j - 1]);
            }
            // Move current row to previous row for next iteration
            swap(prev, curr);
        }
        return prev[m]; // Return the LCS length
    }

    // Function to calculate the Longest Palindromic Subsequence (LPS) of a string
    int checkPalindrome(string s) {
        string s_ = s; 
        reverse(s_.begin(), s_.end()); // Reverse the string to compare with original
        return lcs(s, s_); // LPS is the LCS of the string and its reverse
    }

    // Function to compute the maximum product of lengths of two palindromic subsequences
    int maxProduct(string s) {
        int n = s.length();
        long long ans = 0; // To store the maximum product

        // Iterate over all possible subsets of the string
        for (int i = 0; i < (1 << n); i++) { //2^n subsequences
            string x = "", y = ""; // Two subsets x and y
            for (int j = 0; j < n; j++) {
                if (i & (1 << j))  //1 << 3 means 1*2*2*2
                    x += s[j]; // Include character in subset x
                else 
                    y += s[j]; // Include character in subset y
            }
            // Calculate the product of LPS lengths of x and y, and update the maximum
            ans = max(ans, 1LL * checkPalindrome(x) * checkPalindrome(y));
        }
        return ans; // Return the maximum product
    }
};
