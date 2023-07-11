public class Solution {
    public int MaxConsecutiveAnswers(string answerKey, int k) {
        int longestConsecutiveCount = 0;  // Maximum number of consecutive 'T's or 'F's
        int left = 0;  // Left pointer of the sliding window
        int maxChanges = k;  // Maximum changes allowed
        int tCount = 0;  // Count of consecutive 'T's
        int fCount = 0;  // Count of consecutive 'F's
        
        // Iterate through the answerKey using the right pointer
        for (int right = 0; right < answerKey.Length; right++) {
            char currentAnswer = answerKey[right];
            
            // Increment the count of the current answer
            if (currentAnswer == 'T') {
                tCount++;
            } else {
                fCount++;
            }
            
            // If the number of changes needed exceeds the maximum changes allowed,
            // move the left pointer and update the counts
            while (Math.Min(tCount, fCount) > maxChanges) {
                char leftAnswer = answerKey[left];
                
                // Decrement the count of the left answer and move the left pointer
                if (leftAnswer == 'T') {
                    tCount--;
                } else {
                    fCount--;
                }
                
                left++;  // Move the left pointer
            }
            
            // Update the longest consecutive count
            longestConsecutiveCount = Math.Max(longestConsecutiveCount, right - left + 1);
        }
        
        return longestConsecutiveCount;
    }
}
