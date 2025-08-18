// Recursive
class Solution {
  public:
    int f(int i, int w, vector<int>& val, vector<int>& wt){
        if(i==0){
            if(wt[0] <= w){
                return (w / wt[0]) * val[0];
            }
            return 0;
        }
        int notTake = 0 + f(i-1, w, val, wt);
        int take = INT_MIN;
        if(wt[i] <= w) take = val[i] + f(i, w - wt[i], val, wt);
        return max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        return f(n-1, capacity, val, wt);
    }
};

// Memoization
class Solution {
  public:
    int f(int i, int w, vector<int>& val, vector<int>& wt, vector<vector<int>>& dp){
        if(i==0){
            if(wt[0] <= w){
                return (w / wt[0]) * val[0];
            }
            return 0;
        }
        if(dp[i][w] != -1) return dp[i][w];
        int notTake = 0 + f(i-1, w, val, wt, dp);
        int take = INT_MIN;
        if(wt[i] <= w) take = val[i] + f(i, w - wt[i], val, wt, dp);
        return dp[i][w] = max(take, notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return f(n-1, capacity, val, wt, dp);
    }
};

// Tabulation
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));
        for(int i=0; i<=capacity; i++){
            dp[0][i] = (int)(i / wt[0]) * val[0];
        }
        for(int i=1; i<n; i++){
            for(int w=0; w<=capacity; w++){
                int notTake = 0 + dp[i-1][w];
                int take = INT_MIN;
                if(wt[i] <= w) take = val[i] + dp[i][w - wt[i]];
                dp[i][w] = max(take, notTake);
            }
        }
        return dp[n-1][capacity];
    }
};

// Space Optimization
class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = wt.size();
        vector<int> dp(capacity + 1, 0);
        for(int i=0; i<=capacity; i++){
            dp[i] = (int)(i / wt[0]) * val[0];
        }
        for(int i=1; i<n; i++){
            vector<int> temp(capacity+1, 0);
            for(int w=0; w<=capacity; w++){
                int notTake = 0 + dp[w];
                int take = INT_MIN;
                if(wt[i] <= w) take = val[i] + temp[w - wt[i]];
                temp[w] = max(take, notTake);
            }
            dp = temp;
        }
        return dp[capacity];
    }
};
