public class Solution {
    public int CountSubstrings(string s) {
        int n = s.Length;
    bool[,] dp = new bool[n, n];
    int longest = 0;
    
    // base cases: single characters and length-2 substrings
    for (int i = 0; i < n; i++) {
        dp[i,i] = true;
        longest++;
    }
    for (int i = 0; i < n-1; i++) {
        if (s[i] == s[i+1]) {
            dp[i,i+1] = true;
            longest++;
        }
    }
    
    // fill dp array for substrings of length 3 or greater
    for (int l = 3; l <= n; l++) {
        for (int i = 0; i <= n-l; i++) {
            int j = i + l - 1;
            if(s[i] == s[j] && dp[i+1,j-1])
            {
            dp[i,j] = (s[i] == s[j] && dp[i+1,j-1]);
            longest++;
            }
        }
    }
    
    
    return longest;
    }
}
