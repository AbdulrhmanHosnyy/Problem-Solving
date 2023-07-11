public class Solution {
    public bool CheckValidString(string s) {
        Stack<int> openStack = new Stack<int>();
       Stack<int> stars = new Stack<int>();
       for(int i = 0; i < s.Length; i++)
       {
           char c = s[i];
           if (c == '(')
           {
               openStack.Push(i);
           }
           else if(c == ')')
           {
               if (openStack.Count > 0)
                   openStack.Pop();
               else if (stars.Count > 0)
                   stars.Pop();
               else
                   return false;
           }
           else if (c == '*')
           {
               stars.Push(i);
           }
       }

       while (openStack.Count > 0)
       {
           if (stars.Count  ==0 )
               return false;
           if (stars.Pop() < openStack.Pop())
               return false;
       }
       return true;
    }
}
