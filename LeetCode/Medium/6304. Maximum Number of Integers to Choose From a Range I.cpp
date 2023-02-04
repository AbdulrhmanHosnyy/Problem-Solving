class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        vector<bool> v(10005, false);
        for(int i = 0; i < banned.size(); i++) v[banned[i]] = true;
        priority_queue<int, vector<int>, greater<int>> q;
        int j = 0;
        for(int i = 1; i <= n; i++)
        {
            if(!v[i]) q.push(i);
        }
        int answer = 0;
        while(!q.empty())
        {
            maxSum -= q.top();
            q.pop();
            if(maxSum < 0) break;
            answer++;
        }
        return answer;
    }
};
