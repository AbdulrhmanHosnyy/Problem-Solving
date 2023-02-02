public class Solution {
    public bool IsAlienSorted(string[] words, string order) {
        int [] v = new int [26];
        //var v = Vector.Create<int>(order.Length);
        for(int i = 0; i < order.Length; i++) v[order[i] - 'a'] = i;
        for(int i = 0 ; i < words.Length - 1; i++)
        {
            bool flag = false;
            for(int j = 0; j < Math.Min(words[i].Length, words[i + 1].Length); j++)
            {
                //Console.WriteLine(words[i][j] + " " + words[i + 1][j]);
                //Console.WriteLine(v[words[i][j] - 'a'] + " " +
                //v[words[i + 1][j] - 'a']);
                if(v[words[i][j] - 'a'] < v[words[i + 1][j] - 'a'])
                {
                    flag = true;
                    break;
                } 
                if(v[words[i][j] - 'a'] > v[words[i + 1][j] - 'a']) return false;
            }
            if(words[i].Length > words[i + 1].Length && !flag) return false;
        }
        return true;
    }
}
