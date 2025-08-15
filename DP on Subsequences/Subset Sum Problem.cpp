// Recursion
class Solution {
  public:
    bool f(int i, int target, vector<int>& arr){
        if(terget == 0) return true;
        if(i == 0) arr[0] == target;
        bool take = false;
        if(arr[i] <= target) take = f(i-1, target-arr[i], arr);
        bool notTake = f(i-1, target, arr);
        return take or notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        return f(0, sum, arr);
    }
};

// Memoization
class Solution {
  public:
    bool f(int i, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(i == 0) return (arr[0] == target);
        if(dp[i][target] != -1) return dp[i][target];
        bool take = false;
        if(arr[i] <= target) take = f(i-1, target-arr[i], arr, dp);
        bool notTake = f(i-1, target, arr, dp);
        return dp[i][target] = take or notTake;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return f(n-1, sum, arr, dp);
    }
};

// Tabulation
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        for(int i=0; i<n; i++){
            dp[i][0] = true;
        }
        if(arr[0] <= sum) dp[0][arr[0]] = true;
        for(int i = 1; i < n; i++) {
            for(int target = 1; target <= sum; target++) {
                bool take = false;
                if(arr[i] <= target) take = dp[i - 1][target - arr[i]];
                bool notTake = dp[i - 1][target];
                dp[i][target] = take || notTake;
            }
        }
        return dp[n - 1][sum];
    }
};

// Space Optimization
    bool f(int k, vector<int>& arr){
        int n = arr.size();
        vector<bool> prev(k+1, false), curr(k+1, false);
        prev[0] = curr[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int target = 1; target<=k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[i] <= target) take = prev[target-arr[i]];
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
