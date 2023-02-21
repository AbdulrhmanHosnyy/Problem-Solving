public class Solution {
    public string GcdOfStrings(string str1, string str2) {
        string cur = "", div = "";
        for(int i = 0; i < Math.Min(str1.Length, str2.Length); i++)
        {
            cur += str1[i];
            if(isDivisor(cur, str1) && isDivisor(cur, str2)) div = cur;
        }
        return div;
    }
    public static bool isDivisor(string div, string str)
    {
        string divisor = div;
        while(divisor.Length < str.Length) divisor += div;
        return divisor == str;
    }
}
