public class Solution {
    public int LargestVariance(string s) {
        int[] counter = new int[26];
        foreach (char ch in s)
        {
            counter[ch - 'a']++;
        }

        int globalMax = 0;

        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 26; j++)
            {
                if (i == j || counter[i] == 0 || counter[j] == 0)
                {
                    continue;
                }

                char major = (char)('a' + i);
                char minor = (char)('a' + j);
                int majorCount = 0;
                int minorCount = 0;
                int restMinor = counter[j];

                foreach (char ch in s)
                {
                    if (ch == major)
                    {
                        majorCount++;
                    }
                    if (ch == minor)
                    {
                        minorCount++;
                        restMinor--;
                    }

                    if (minorCount > 0)
                    {
                        globalMax = Math.Max(globalMax, majorCount - minorCount);
                    }

                    if (majorCount < minorCount && restMinor > 0)
                    {
                        majorCount = 0;
                        minorCount = 0;
                    }
                }
            }
        }

        return globalMax;
    }
}
