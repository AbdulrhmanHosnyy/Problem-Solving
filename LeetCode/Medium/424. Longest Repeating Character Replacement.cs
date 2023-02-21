public class Solution {
    public int CharacterReplacement(string s, int k) {
        int result = 0;
        int l = 0;
        var count = new Dictionary<char, int>();
        int helper = 0;
        for(int r = 0; r < s.Length; r++)
        {
            if(!count.ContainsKey(s[r]))
                count.Add(s[r], 0);
            count[s[r]]++;
            helper = Math.Max(helper, count[s[r]]);
            while((r - l + 1) - helper > k)
            {
                count[s[l]]--;
                l += 1;
            }
            result = Math.Max(result, r - l + 1);
        }
        return result;
    }
}
