class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = 0;
        for(auto &i: s) n += (i == '0');
        int mini = n;
        for(auto &i: s)
        {
            if(i == '0') mini = min(mini, --n);
            else n++;
        }
        return mini;
    }
};
