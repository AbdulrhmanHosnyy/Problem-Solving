public class Solution {
    public IList<int> FindAnagrams(string s, string p) {
        int sz = s.Length, pz = p.Length;
        if(pz > sz) return new List<int>();
        List<int> f1 = new List<int>(new int [26]);
        List<int> f2 = new List<int>(new int [26]);
        for(int i = 0; i < pz; i++)
        {
            f1[p[i] - 'a']++;
            f2[s[i] - 'a']++;
        }
        List<int> answer = new List<int>();
        for(int i = 0; i < sz - pz; i++)
        {
            if(isPermutation(f1, f2)) answer.Add(i);
            f2[s[i] - 'a']--;
            f2[s[i + pz] - 'a']++;
        }
        if(isPermutation(f1, f2)) answer.Add(sz - pz);
        return answer;
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
