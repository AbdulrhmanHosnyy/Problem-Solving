public class Solution {
    private int maxRequests = 0;
    public int MaximumRequests(int n, int[][] requests) {
        int[] buildings = new int[n];
        Backtrack(buildings, requests, 0, 0);
        return maxRequests;
    }
    
    private void Backtrack(int[] buildings, int[][] requests, int index, int count) {
        // Check if all requests have been processed
        if (index == requests.Length) {
            // Check if the buildings are balanced
            if (IsBalanced(buildings)) {
                maxRequests = Math.Max(maxRequests, count);
            }
            return;
        }
        
        // Process the current request
        int from = requests[index][0];
        int to = requests[index][1];
        buildings[from]--;
        buildings[to]++;
        Backtrack(buildings, requests, index + 1, count + 1);
        buildings[from]++;
        buildings[to]--;
        
        // Skip the current request
        Backtrack(buildings, requests, index + 1, count);
    }
    
    private bool IsBalanced(int[] buildings) {
        foreach (int b in buildings) {
            if (b != 0) {
                return false;
            }
        }
        return true;
    }
}
