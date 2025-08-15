class Solution {
  public:
    int isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));
        if(arr[0]==0) dp[0][0] = 2;
        else dp[0][arr[0]] = 1;
        if(arr[0] != 0 and arr[0] <= sum) dp[0][arr[0]] = 1;
        for(int i = 1; i < n; i++) {
            for(int target = 0; target <= sum; target++) {
                int take = 0;
                if(arr[i] <= target) take = dp[i - 1][target - arr[i]];
                int notTake = dp[i - 1][target];
                dp[i][target] = (take + notTake);
            }
        }
        return dp[n-1][sum];
    }
    int countPartitions(vector<int>& nums, int d) {
        // Code here
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum - d < 0 || (sum-d) % 2 ) return 0;
        return isSubsetSum(nums, (sum-d)/2);
    }
};
