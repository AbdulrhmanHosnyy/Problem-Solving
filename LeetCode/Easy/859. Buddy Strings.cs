public class Solution {
    public bool BuddyStrings(string s, string goal) {
        if (s.Length != goal.Length) return false;
        var list = new List<int>();
        for (int i = 0; i < s.Length; i++)
        {
            if (s[i] != goal[i])
            {
                list.Add(i);
                if (list.Count > 2) return false;
            }
        }
        if (list.Count == 0)
        {
            if (s.Length > 26) return true;
            var set = new HashSet<char>();
            for (int i = 0; i < s.Length; i++)
            {
                if (set.Contains(s[i])) return true;
                set.Add(s[i]);
            }
            return false;
        }
        if (list.Count == 1) return false;
        return s[list[0]] == goal[list[1]] && s[list[1]] == goal[list[0]];
    }
}
