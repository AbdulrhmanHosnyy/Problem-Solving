public class Solution {
    public double KnightProbability(int n, int k, int row, int column) {
         int[][] directions = new int[][] {
            new int[] { 2, 1 },
            new int[] { 1, 2 },
            new int[] { -1, 2 },
            new int[] { -2, 1 },
            new int[] { -2, -1 },
            new int[] { -1, -2 },
            new int[] { 1, -2 },
            new int[] { 2, -1 }
        };

        double[,,] dp = new double[n, n, k + 1];
        dp[row, column, 0] = 1;

        for (int s = 1; s <= k; s++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    foreach (var dir in directions) {
                        int prevRow = i + dir[0];
                        int prevCol = j + dir[1];
                    
                        if (prevRow >= 0 && prevRow < n && prevCol >= 0 && prevCol < n) {
                            dp[i, j, s] += dp[prevRow, prevCol, s - 1] / 8;
                        }
                    }
                }
            }
        }
        double totalProbability = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                totalProbability += dp[i, j, k];
            }
        }
    
        return totalProbability;
    }
}
