public class Solution {
    public string Convert(string s, int numRows) {
        if(numRows == 1) return s;
        string answer = "";
        int i = 0, k = 0;
        int helper = (numRows - 1) * 2;
        while(k < s.Length)
        {
            int j = i;
            if(i == 0 || i == numRows - 1)
            {
                while(j < s.Length)
                {
                    answer += s[j];
                    j += helper;
                    k++;
                }
                i++;
            }
            else
            {
                int helper2 = helper - 2 * i;
                bool flag = false;
                while(j < s.Length)
                {
                    answer += s[j];
                    if(!flag)
                    {
                        j += helper2;
                        flag = true;
                    }
                    else
                    {
                        j += (helper - helper2);
                        flag = false;
                    }
                    k++;
                }
                i++;
            }
        }
        
        return answer;
    }
}
