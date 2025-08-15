// Recursion
class Solution {
  public:
    int f(int i, int s, vector<int>& arr){
        if(i == 0){
            if(s == 0 && arr[0] == 0) return 2; // {} and {0}
            if(s == 0 || s == arr[0]) return 1;
            return 0;
        }
        int notTake = f(i-1, s, arr);
        int take = 0;
        if(arr[i] <= s) take = f(i-1, s-arr[i], arr);
        return take + notTake;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return f(n-1, target, arr);
    }
};

// Memoization
class Solution {
  public:
    int f(int i, int s, vector<int>& arr, vector<vector<int>>& dp){
        if(i == 0){
            if(s == 0 && arr[0] == 0) return 2; // {} and {0}
            if(s == 0 || s == arr[0]) return 1;
            return 0;
        }
        if(dp[i][s] != -1) return dp[i][s];
        int notTake = f(i-1, s, arr, dp);
        int take = 0;
        if(arr[i] <= s) take = f(i-1, s - arr[i], arr, dp);
        return dp[i][s] = take + notTake;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, -1));
        return f(n-1, target, arr, dp);
    }
};

// Tabulation
class Solution {
  public:
    const int MOD = 1e9+7;
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target+1, 0));
        if(arr[0] == 0) {
            dp[0][0] = 2; 
        } 
        else {
            dp[0][0] = 1; 
            if (arr[0] <= target) dp[0][arr[0]] = 1;
        }
        for (int i = 1; i < n; i++) {
            for (int sum = 0; sum <= target; sum++) {
                int notTake = dp[i-1][sum];
                int take = 0;
                if (arr[i] <= sum) take = dp[i-1][sum - arr[i]];
                dp[i][sum] = (take + notTake) % MOD;
            }
        }
        return dp[n-1][target];
    }
};

// Space Optimization
class Solution {
  public:
    const int MOD = 1e9+7;
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(target+1, 0);
        if(arr[0] == 0) {
            dp[0] = 2; 
        } 
        else {
            dp[0] = 1; 
            if (arr[0] <= target) dp[arr[0]] = 1;
        }
        for (int i = 1; i < n; i++) {
            vector<int> temp(target+1, 0);
            for (int sum = 0; sum <= target; sum++) {
                int notTake = dp[sum];
                int take = 0;
                if (arr[i] <= sum) take = dp[sum - arr[i]];
                temp[sum] = (take + notTake) % MOD;
            }
            dp = temp;
        }
        return dp[target];
    }
};
