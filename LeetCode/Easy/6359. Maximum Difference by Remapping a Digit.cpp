class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int maxi = 0, mini = 0;
        for(int i = 1; i < s.size(); i++)
        {
            mini *= 10;
            if(s[i] != s[0])
                mini += s[i] - '0';
        }
        char helper = 'a';
        for(int i = 0; i < s.size(); i++)
        {
            maxi *= 10;
            if(helper == 'a')
            {
                if(s[i] != '9')
                {
                    helper = s[i];
                    s[i] = '9';
                }
            }
            else
            {
                if(s[i] == helper)
                {
                    s[i] = '9';
                    cout << 1 << endl;
                }
            }
            maxi += s[i] - '0';
            
        }
        return maxi - mini;
    }
};
