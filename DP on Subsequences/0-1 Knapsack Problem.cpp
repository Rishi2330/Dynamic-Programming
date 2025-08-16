// Recursion
class Solution {
  public:
    int f(int i, int w, vector<int> &val, vector<int> &wt){
        if(i == 0){
            if(wt[0] <= w){
                return val[0];
            }
            return 0;
        } 
        int notTake = 0 + f(i-1, w, val, wt);
        int take = INT_MIN;
        if(wt[i] <= w) take = val[i] + f(i-1, w-wt[i], val, wt);
        return max(take, notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        return f(n-1, W, val, wt);
    }
};

// Memoization
class Solution {
  public:
    int f(int i, int w, vector<int> &val, vector<int> &wt, vector<vector<int>>& dp){
        if(i == 0){
            if(wt[0] <= w){
                return val[0];
            }
            return 0;
        } 
        if(dp[i][w] != -1) return dp[i][w];
        int notTake = 0 + f(i-1, w, val, wt, dp);
        int take = INT_MIN;
        if(wt[i] <= w) take = val[i] + f(i-1, w-wt[i], val, wt, dp);
        return dp[i][w] = max(take, notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1,-1));
        return f(n-1, W, val, wt, dp);
    }
};

// Tabulation
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1,0));
        for(int i=wt[0]; i<=W; i++){
            dp[0][i] = val[0];
        }
        for(int i=1; i<n; i++){
            for(int w=0; w<=W; w++){
                int notTake = 0 + dp[i-1][w];
                int take = INT_MIN;
                if(wt[i] <= w) take = val[i] + dp[i-1][w - wt[i]];
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n-1][W];
    }
};

// Space Optimization
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<int> dp(W+1, 0);
        for(int i=wt[0]; i<=W; i++){
            dp[i] = val[0];
        }
        for(int i=1; i<n; i++){
            vector<int> temp(W+1, 0);
            for(int w=0; w<=W; w++){
                int notTake = 0 + dp[w];
                int take = INT_MIN;
                if(wt[i] <= w) take = val[i] + dp[w - wt[i]];
                temp[w] = max(take, notTake);
            }
            dp = temp;
        }
        return dp[W];
    }
};
