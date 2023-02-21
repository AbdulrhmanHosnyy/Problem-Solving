public class Solution {
    public bool CheckInclusion(string s1, string s2) {
        int sz1 = s1.Length, sz2 = s2.Length;
        if(sz1 > sz2) return false;
        List<int> f1 = new List<int>(new int [26]);
        List<int> f2 = new List<int>(new int [26]);
        for(int i = 0; i < sz1; i++)
        {
            f1[s1[i] - 'a']++;
            f2[s2[i] - 'a']++;
        }
        for(int i = 0; i < sz2 - sz1; i++)
        {
            if(isPermutation(f1, f2)) return true;
            f2[s2[i] - 'a']--;
            f2[s2[i + sz1] - 'a']++;
        }
        return isPermutation(f1, f2);
    }
    public bool isPermutation(List<int> f1, List<int> f2)
    {
        for(int i = 0 ; i < 26; i++)
        {
            if(f1[i] != f2[i]) return false;
        }
            
        return true;
    }
}
