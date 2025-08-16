// Recursion
class Solution {
public:
    int f(int i, int T, vector<int>& coins) {
        if(i == 0) {
            if (T % coins[0] == 0) return T / coins[0];
            return 1e9;
        }
        int notTake = f(i - 1, T, coins);
        int take = 1e9;
        if(coins[i] <= T) take = 1 + f(i, T - coins[i], coins);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = f(n - 1, amount, coins);
        return (ans >= 1e9 ? -1 : ans);
    }
};

// Memoization
class Solution {
public:
    int f(int i, int T, vector<int>& coins, vector<vector<int>>& dp) {
        if(i == 0) {
            if (T % coins[0] == 0) return T / coins[0];
            return 1e9;
        }
        if(dp[i][T] != -1) return dp[i][T];
        int notTake = f(i - 1, T, coins, dp);
        int take = 1e9;
        if(coins[i] <= T) take = 1 + f(i, T - coins[i], coins, dp);
        return dp[i][T] = min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        int ans = f(n - 1, amount, coins, dp);
        return (ans >= 1e9 ? -1 : ans);
    }
};

// Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 1e9));
        for(int T = 0; T <= amount; T++) {
            if(T % coins[0] == 0) dp[0][T] = T / coins[0];
        }
        for(int i=1; i<n; i++){
            for(int T=0; T<=amount; T++){
                int notTake = 0 + dp[i-1][T];
                int take = 1e9;
                if(coins[i] <= T) take = 1 + dp[i][T - coins[i]];
                dp[i][T] = min(take, notTake);
            }
        }
        return (dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount]);
    }
};

// Space Optimization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount+1, 1e9);
        for(int T = 0; T <= amount; T++) {
            if(T % coins[0] == 0) dp[T] = T / coins[0];
        }
        for(int i=1; i<n; i++){
            vector<int> temp(amount+1, 1e9);
            for(int T=0; T<=amount; T++){
                int notTake = 0 + dp[T];
                int take = 1e9;
                if(coins[i] <= T) take = 1 + temp[T - coins[i]];
                temp[T] = min(take, notTake);
            }
            dp = temp;
        }
        return (dp[amount] >= 1e9 ? -1 : dp[amount]);
    }
};
