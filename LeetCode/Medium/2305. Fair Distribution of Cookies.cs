public class Solution {
    int result = int.MaxValue;
    public int DistributeCookies(int[] cookies, int k)
    {
        Backtrack(cookies, k, new int[k], 0);
        return result;
    }

    private void Backtrack(int[] cookies, int k, int[] child ,int counter)
    {
        if (counter == cookies.Length)
        {
            result = Math.Min(result, child.Max());
            return;
        }
        for (int i = 0; i < k; i++)
        {
            child[i] += cookies[counter];
            Backtrack(cookies, k, child, counter + 1);
            child[i] -= cookies[counter];
        }
    }

}
