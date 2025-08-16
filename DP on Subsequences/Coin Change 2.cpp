// Recursion
class Solution {
public:
    int f(int i, int t, vector<int>& coins){
        if(i == 0) return (t % coins[0] == 0);
        int notTake = f(i-1, t, coins);
        int take = 0;
        if(coins[i] <= t) f(i, t - coins[i], coins);
        return take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return f(n-1, amount, coins);
    }
};

// Memoization
class Solution {
public:
    int f(int i, int t, vector<int>& coins, vector<vector<int>>& dp){
        if(i == 0) return (t % coins[0] == 0);
        if(dp[i][t] != -1) return dp[i][t];
        int notTake = f(i-1, t, coins, dp);
        int take = 0;
        if(coins[i] <= t) take = f(i, t - coins[i], coins, dp);
        return dp[i][t] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, -1));
        return f(n-1, amount, coins, dp);
    }
};

// Tabulation
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));
        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0) dp[0][t] = 1;
        }
        for(int i = 1; i < n; i++){
            for(int t = 0; t <= amount; t++){
                int notTake = dp[i-1][t];
                int take = 0;
                if(coins[i] <= t) take = dp[i][t - coins[i]];
                dp[i][t] = take + notTake;
            }
        }
        return dp[n-1][amount];
    }
};

// Space Optimization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> dp(amount+1, 0);
        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0) dp[t] = 1;
        }
        for(int i = 1; i < n; i++){
            vector<int> temp(amount+1, 0);
            for(int t = 0; t <= amount; t++){
                int notTake = dp[t];
                int take = 0;
                if(coins[i] <= t) take = temp[t - coins[i]];
                temp[t] = take + notTake;
            }
            dp = temp;
        }
        return dp[amount];
    }
};
// -> more optimized version
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1, 0);
        dp[0] = 1;
        for(int coin : coins){
            for(int t = coin; t <= amount; t++){
                dp[t] += dp[t - coin];
            }
        }
        return dp[amount];
    }
};
