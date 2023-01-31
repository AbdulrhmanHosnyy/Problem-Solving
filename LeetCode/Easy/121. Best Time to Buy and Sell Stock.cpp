class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int helper = prices[0];
        int answer = 0;
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] > helper) answer = max(answer, prices[i] - helper);
            helper = min(helper, prices[i]);
        }
        return answer;
    }
};
