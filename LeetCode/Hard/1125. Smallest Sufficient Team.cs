public class Solution {
    List<int> res = new List<int>();
    
    public int[] SmallestSufficientTeam(string[] req_skills, IList<IList<string>> people) {
        int n = people.Count;
        int m = req_skills.Length;

        Dictionary<string, int> mpp = new Dictionary<string, int>();
        for (int i = 0; i < m; i++) {
            mpp[req_skills[i]] = (1 << i);
        }

        List<int> people_skill = new List<int>();
        foreach (var person in people) {
            int mask = 0;
            foreach (string skill in person) {
                if (mpp.ContainsKey(skill)) {
                    mask |= mpp[skill];
                }
            }
            people_skill.Add(mask);
        }

        int[][] dp = new int[n][];
        for (int i = 0; i < n; i++) {
            dp[i] = new int[(1 << m)];
            for (int j = 0; j < (1 << m); j++) {
                dp[i][j] = -1;
            }
        }

        List<int> ans = new List<int>();
        Helper(0, people_skill, m, 0, ans, dp);
        //res.Sort();
        return res.ToArray();
    }
    
    private void Helper(int i, List<int> people_skill, int m, int mask, List<int> ans, int[][] dp) {
        if (i == people_skill.Count) {
            if (mask == ((1 << m) - 1)) {
                if (res.Count == 0 || ans.Count < res.Count) {
                    res = new List<int>(ans);
                }
            }
            return;
        }

        if (dp[i][mask] != -1 && dp[i][mask] <= ans.Count) {
            return;
        }

        Helper(i + 1, people_skill, m, mask, ans, dp);

        ans.Add(i);

        Helper(i + 1, people_skill, m, (mask | people_skill[i]), ans, dp);

        ans.RemoveAt(ans.Count - 1);

        if (ans.Count > 0) {
            dp[i][mask] = ans.Count;
        }
    }
}
