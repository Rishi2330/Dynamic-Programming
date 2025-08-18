// Recursion
class Solution {
  public:
    int f(int i, int N, vector<int>& price) {
        if (i == 1) return N * price[0];
        int notTake = f(i - 1, N, price);
        int take = INT_MIN;
        if (i <= N) take = price[i - 1] + f(i, N - i, price);
        return max(take, notTake);
    }

    int cutRod(vector<int> &price) {
        int n = price.size();
        return f(n, n, price);  
    }
};

// Memoization
class Solution {
  public:
    int f(int i, int N, vector<int>& price, vector<vector<int>>& dp) {
        if (i == 1) return N * price[0];
        if (dp[i][N] != -1) return dp[i][N];
        int notTake = f(i - 1, N, price, dp);
        int take = INT_MIN;
        if (i <= N) take = price[i - 1] + f(i, N - i, price, dp);
        return dp[i][N] = max(take, notTake);
    }
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return f(n, n, price, dp);
    }
};

// Tabulation
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int N = 0; N <= n; N++) {
            dp[1][N] = N * price[0];
        }
        for (int i = 2; i <= n; i++) {
            for (int N = 0; N <= n; N++) {
                int notTake = dp[i - 1][N];
                int take = INT_MIN;
                if (i <= N) take = price[i - 1] + dp[i][N - i];
                dp[i][N] = max(take, notTake);
            }
        }
        return dp[n][n];
    }
};

// Space Optimization
class Solution {
  public:
    int cutRod(vector<int> &price) {
        int n = price.size();
        vector<int> dp(n + 1, 0);
        for (int N = 0; N <= n; N++) {
            dp[N] = N * price[0];
        }
        for (int i = 2; i <= n; i++) {
            for (int N = 0; N <= n; N++) {
                int notTake = dp[N];
                int take = INT_MIN;
                if (i <= N) take = price[i - 1] + dp[N - i];
                dp[N] = max(take, notTake);
            }
        }
        return dp[n];
    }
};
