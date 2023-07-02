public class Solution {
    public int MaxProduct(int[] nums) {
         int n = nums.Length;
         int[] maxMemo = new int[n];
         int[] minMemo = new int[n];
         maxMemo[0] = nums[0];
         minMemo[0] = nums[0];
         int maxProduct = nums[0];
        
         for (int i = 1; i < n; i++) {
             maxMemo[i] = Math.Max(Math.Max(maxMemo[i - 1] * nums[i], 
             minMemo[i - 1] * nums[i]), nums[i]);
             minMemo[i] = Math.Min(Math.Min(maxMemo[i - 1] * nums[i], 
             minMemo[i - 1] * nums[i]), nums[i]);
             maxProduct = Math.Max(maxProduct, maxMemo[i]);
         }
         return maxProduct;
    }
}
