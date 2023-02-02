public class Solution {
    public int LengthOfLongestSubstring(string s) {
        HashSet<int> helper = new HashSet<int>();
        int l = 0;
        int maxi = 0;
        for(int r = 0; r < s.Length; r++)
        {
            while(helper.Contains(s[r]))
            {
                helper.Remove(s[l]);
                l++;
            }
        
            helper.Add(s[r]);
            maxi = Math.Max(maxi, r - l + 1);
            
        }
        return maxi;
    }
}
