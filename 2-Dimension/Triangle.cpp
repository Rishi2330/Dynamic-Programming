// Recursive
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& t){
        if(i==t.size()-1) return t[t.size()-1][j];
        int d = t[i][j] + f(i+1, j, t);
        int dg = t[i][j] + f(i+1, j+1, t);
        return min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        return f(0, 0, triangle);
    }
};

// Memoization
class Solution {
public:
    int f(int i, int j, vector<vector<int>>& t, vector<vector<int>>& dp){
        if(i==t.size()-1) return t[i][j];
        if(dp[i][j] != INT_MAX) return dp[i][j];
        int d = t[i][j] + f(i+1, j, t, dp);
        int dg = t[i][j] + f(i+1, j+1, t, dp);
        return dp[i][j] = min(d, dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        return f(0, 0, triangle, dp);
    }
};

// Tabulation
// -> Top-Down
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        dp[0][0] = triangle[0][0];
        for(int i = 1; i < n; i++) {
            for(int j = 0; j <= i; j++) {
                int d = INT_MAX, dg = INT_MAX;
                if (j < i) d = triangle[i][j] + dp[i-1][j];
                if (j > 0) dg = triangle[i][j] + dp[i-1][j-1];
                dp[i][j] = min(d, dg);
            }
        }
        int ans = INT_MAX;
        for (int j = 0; j < n; j++) {
            ans = min(ans, dp[n-1][j]);
        }
        return ans;
    }
};
// -> Bottom-up
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for(int j=0; j<n; j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            for(int j=i; j>=0; j--){
                int d = triangle[i][j] + dp[i+1][j];
                int dg = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(d, dg);
            }
        }
        return dp[0][0];
    }
};

// Space Optimization
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        for(int j=0; j<n; j++){
            dp[j] = triangle[n-1][j];
        }
        for(int i=n-2; i>=0; i--){
            vector<int> temp(n,0);
            for(int j=i; j>=0; j--){
                int d = triangle[i][j] + dp[j];
                int dg = triangle[i][j] + dp[j+1];
                temp[j] = min(d, dg);
            }
            dp = temp;
        }
        return dp[0];
    }
};
