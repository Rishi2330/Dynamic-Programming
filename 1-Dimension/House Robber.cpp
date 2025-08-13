//Recursion
class Solution {
public:
    int f(int i, vector<int>& nums){
        if(i == 0) return nums[0];
        if(i < 0) return 0;
        int pick = nums[i] + f(i - 2, nums);
        int notPick = 0 + f(i - 1, nums);
        return max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return f(n - 1, nums);
    }
};

// Memoization
class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[0];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + f(i - 2, nums, dp);
        int notPick = 0 + f(i - 1, nums, dp);
        return dp[i] = max(pick, notPick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return f(n - 1, nums, dp);
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + dp[i - 2];
            int notPick = dp[i - 1];
            dp[i] = max(pick, notPick);
        }
        return dp[n - 1];
    }
};

// Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        int prev2 = nums[0];                   // dp[i-2]
        int prev1 = max(nums[0], nums[1]);     // dp[i-1]
        for (int i = 2; i < n; i++) {
            int pick = nums[i] + prev2;        // rob current + dp[i-2]
            int notPick = prev1;               // skip current (dp[i-1])
            int curr = max(pick, notPick);
            prev2 = prev1;                     // shift
            prev1 = curr;
        }
        return prev1;  // dp[n-1]
    }
};
