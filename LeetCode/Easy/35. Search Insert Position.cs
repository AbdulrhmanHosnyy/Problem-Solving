public class Solution {
    public int SearchInsert(int[] nums, int target) {
        int tmp = Array.BinarySearch(nums, target);
        if(tmp >= 0) return tmp;
        return (tmp + 1) * -1;

    }
}
