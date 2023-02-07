class Solution {
public:
int totalFruit(vector<int>& fruits) {
    unordered_map<int, int> m;
    int n = fruits.size(), left = 0, right = 0;
    while(right < n)
    {
        m[fruits[right]]++;
        if(m.size() > 2)
        {
            if(--m[fruits[left]] == 0) m.erase(fruits[left]);
            left++;
        }
        right++;
    }
    return right - left;
}
};
