public class Solution {
    public bool IsNStraightHand(int[] hand, int groupSize) {
      if (hand.Length % groupSize != 0) {
            return false;
        }

        Dictionary<int, int> count = new Dictionary<int, int>();
        foreach (int n in hand) {
            if (count.ContainsKey(n)) {
                count[n]++;
            } else {
                count[n] = 1;
            }
        }

        List<int> minH = count.Keys.ToList();
        minH.Sort();
        while (minH.Any()) {
            int first = minH[0];
            for (int i = first; i < first + groupSize; i++) {
                if (!count.ContainsKey(i) || count[i] == 0) {
                    return false;
                }
                count[i]--;
                if (count[i] == 0) {
                    if (i != minH[0]) {
                        return false;
                    }
                    minH.RemoveAt(0);
                }
            }
        }
        return true;
        
    }
}
