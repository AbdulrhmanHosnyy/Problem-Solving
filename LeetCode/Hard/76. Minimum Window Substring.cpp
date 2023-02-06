class Solution {
public:
    string minWindow(string s, string t) {
        int sz = s.size(), tz = t.size();
        if(t == "" || tz > sz) return "";
        unordered_map<char, int> ms, mt;
        for(int i = 0; i < tz; i++)
        {
            mt[t[i]]++;
        }
        int count = 0, start = 0, min = INT_MAX, start_ind = -1;
        for(int i = 0; i < sz; i++)
        {
            ms[s[i]]++;
            if(ms[s[i]] <= mt[s[i]]) count++;
            if(count == tz)
            {
                while(ms[s[start]] > mt[s[start]])
                {
                    ms[s[start]]--;
                    start++;
                }
                if(min > i - start + 1)
                {
                    min = i - start + 1;
                    start_ind = start;
                }
            }
        }
        if(start_ind == -1) return "";
        return s.substr(start_ind, min);
    }

};
