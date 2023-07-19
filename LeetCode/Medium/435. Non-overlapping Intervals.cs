public class Solution {
    public int EraseOverlapIntervals(int[][] intervals) {
         int ans = 0, edge = Int32.MinValue;
        Array.Sort(intervals, (a,b) =>
        {
            return a[1] - b[1];
        });

        for (int i=0; i<intervals.Length; i++){
            if (intervals[i][0]>=edge) edge = intervals[i][1];
            else ans++;
        }

        return ans;
    }
}
