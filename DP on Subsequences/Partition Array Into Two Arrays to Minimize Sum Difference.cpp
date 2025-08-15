class Solution {
public:
    void isSubsetSum(vector<int>& arr, int sum, vector<vector<bool>>& dp) {
        int n = arr.size();
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
    }
    int minimumDifference(vector<int>& nums) {
        int mini = INT_MAX;
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
        isSubsetSum(nums, sum, dp);
        for(int s1=0; s1<=sum/2; s1++){
            if(dp[n-1][s1]){
                mini = min(mini, abs(s1- (sum-s1)));
            }
        }
        return mini;
    }
};
