public class Solution {
    public bool MergeTriplets(int[][] triplets, int[] target) {
        var temp = new bool[] { false, false, false };
        foreach(var triplet in triplets) {
            if(triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2]) {
                temp[0] |= target[0] == triplet[0];
                temp[1] |= target[1] == triplet[1];
                temp[2] |= target[2] == triplet[2];
            }
        }

        return temp[0] && temp[1] && temp[2];
    }
}
