public class Solution {
    public int CoinChange(int[] coins, int amount) {
    // int[] memo = new int[amount + 1];
    // Array.Fill(memo, -1);
    // return CoinChangeRecursive(coins, amount, memo);
    int[] dp = new int[amount + 1];
    Array.Fill(dp, amount + 1);
    dp[0] = 0;
    for (int i = 1; i <= amount; i++) {
        foreach (int coin in coins) {
            if (coin <= i) {
                dp[i] = Math.Min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
    }

    private int CoinChangeRecursive(int[] coins, int amount, int[] memo) {
        if (amount == 0) {
            return 0;
        }
        if (memo[amount] != -1) {
            return memo[amount];
        }
        int minCoins = Int32.MaxValue;
        foreach (int coin in coins) {
            if (amount >= coin) {
                int subMinCoins = 
                CoinChangeRecursive(coins, amount - coin, memo);
                if (subMinCoins != -1) {
                    minCoins = Math.Min(minCoins, subMinCoins + 1);
                }
            }
        }
        memo[amount] = (minCoins == Int32.MaxValue) ? -1 : minCoins;
        return memo[amount];
    }
}
