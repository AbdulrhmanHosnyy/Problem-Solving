public class Solution {
    public string AddBinary(string a, string b) {
       int i = a.Length - 1, j = b.Length - 1, carry = 0;
       string answer = "";
       while(i >= 0 || j >= 0 || carry != 0)
       {
           if(i >= 0)
           {
               carry += a[i] == '0'? 0:1;
               i--;
           }
           if(j >= 0)
           {
               carry += b[j] == '0'? 0:1;
               j--;
           }

           answer += (carry % 2 == 0? "0":"1");

           carry /= 2;
       }
       string ans = "";
       for(int k = answer.Length - 1; k >= 0; k--)
       {
           ans += answer[k];
       }
       return ans;
    }
}
