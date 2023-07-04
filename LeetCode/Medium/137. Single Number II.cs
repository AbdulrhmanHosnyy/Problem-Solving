public class Solution {
    public int SingleNumber(int[] nums) {
        //when an element first shows up, the bits will be put into ones
    //when it shows up a second time, the bits will be moved into twos
    //when it shows up a third time, the bits will be removed from twos
    //at the end, there will only be the bits of the single non-repeating number in ones
    int ones = 0, twos = 0;
    foreach (var num in nums)
    {
        ones ^= num & ~twos;
        twos ^= num & ~ones;
    }
    return ones;
    }
}
