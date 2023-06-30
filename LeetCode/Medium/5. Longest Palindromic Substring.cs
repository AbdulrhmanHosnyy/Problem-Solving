public class Solution {
    public string LongestPalindrome(string s) {
    int n = s.Length;
    bool[,] dp = new bool[n, n];
    string longest = "";
    
    // base cases: single characters and length-2 substrings
    for (int i = 0; i < n; i++) {
        dp[i,i] = true;
    }
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            dp[i,i+1] = true;
        }
    }
    
    // fill dp array for substrings of length 3 or greater
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i + l - 1;
            dp[i,j] = (s[i] == s[j] && dp[i+1,j-1]);
        }
    }
    
    // find longest palindrome
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (dp[i,j] && j-i+1 > longest.Length) {
                longest = s.Substring(i, j-i+1);
            }
        }
    }
    
    return longest;
}

private bool FillDP(bool[,] dp, string s, int i, int j) {
    if (i > j) {
        return true;
    }
    
    if (dp[i,j]) {
        return dp[i,j];
    }
    
    if (i == j) {
        dp[i,j] = true;
        return dp[i,j];
    }
    
    if (s[i] == s[j]) {
        dp[i,j] = FillDP(dp, s, i+1, j-1);
        return dp[i,j];
    }
    
    dp[i,j] = false;
    return dp[i,j];
}
}
