public class Solution {
    public IList<int> PartitionLabels(string s) {
        int [] freq = new int[26];
        foreach(char ch in s){
            freq[ch - 'a']++;
        }
        Dictionary<char, int> dic = new Dictionary<char, int>();
        List<int> answer = new List<int>();
        int counter = 0;
        foreach(char ch in s){
            if(dic.ContainsKey(ch))
            {
                dic[ch]--;
                if(dic[ch] <= 1) dic.Remove(ch);
            }
            else{
                if(freq[ch - 'a'] != 1) dic.Add(ch, freq[ch - 'a']);
            }
            counter++;
            if(dic.Count == 0){
                answer.Add(counter);
                counter = 0;
            }
        }
        return answer;

    }
}
