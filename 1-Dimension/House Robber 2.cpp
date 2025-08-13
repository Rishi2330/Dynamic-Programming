// My Brute Force Recursion Approch
class Solution {
public:
    int f1(int i, vector<int>& nums){
        if(i == 1) return nums[i];
        if(i < 1) return 0;
        int pick = nums[i] + f1(i - 2, nums);
        int notPick = 0 + f1(i - 1, nums);
        return max(pick, notPick);
    }
    int f(int i, vector<int>& nums){
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        int pick = nums[i] + f(i - 2, nums);
        int notPick = 0 + f(i - 1, nums);
        return max(pick, notPick); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return max(f(n-2, nums), f1(n-1, nums));
    }
};

// Recursion
class Solution {
public:
    int f(int i, vector<int>& nums){
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        int pick = nums[i] + f(i - 2, nums);
        int notPick = 0 + f(i - 1, nums);
        return max(pick, notPick); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> num(nums.begin()+1, nums.end());
        return max(f(n-2, nums), f(n-2, num));
    }
};

// Memoization
class Solution {
public:
    int f(int i, vector<int>& nums, vector<int>& dp){
        if(i == 0) return nums[i];
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + f(i - 2, nums, dp);
        int notPick = 0 + f(i - 1, nums, dp);
        return dp[i] = max(pick, notPick); 
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        vector<int> num(nums.begin()+1, nums.end());
        vector<int> dp1(n, -1), dp2(n, -1);
        return max(f(n-2, nums, dp1), f(n-2, num, dp2));
    }
};

// Tabulation
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> dp1(n - 1, 0), dp2(n - 1, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[1], nums[0]);
        for(int i=2; i<n-1; i++){
            int pick = nums[i] + dp1[i - 2];
            int notPick = 0 + dp1[i - 1];
            dp1[i] = max(pick, notPick);
        }
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for(int i=3; i<n; i++){
            int pick = nums[i] + dp2[i - 3];
            int notPick = 0 + dp2[i - 2];
            dp2[i-1] = max(pick, notPick);
        }
        return max(dp1[n-2], dp2[n-2]);
    }
};

// Space Optimization
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        int p2 = nums[0];
        int p1 = max(nums[1], nums[0]);
        for(int i=2; i<n-1; i++){
            int pick = nums[i] + p2;
            int notPick = 0 + p1;
            int curr = max(pick, notPick);
            p2 = p1;
            p1 = curr;
        }
        int q2 = nums[1];
        int q1 = max(nums[1], nums[2]);
        for(int i=3; i<n; i++){
            int pick = nums[i] + q2;
            int notPick = 0 + q1;
            int curr = max(pick, notPick);
            q2 = q1;
            q1 = curr;
        }
        return max(p1, q1);
    }
};

// Eliminate 2 loop by using function
class Solution {
public:
    int robLinear(vector<int>& nums) {
        int prev2 = 0, prev1 = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int pick = nums[i] + prev2;
            int notPick = prev1;
            int cur = max(pick, notPick);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);
        vector<int> nums1(nums.begin(), nums.end() - 1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(robLinear(nums1), robLinear(nums2));
    }
};
