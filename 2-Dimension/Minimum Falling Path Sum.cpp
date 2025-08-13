// Recursion
class Solution {
public:
    int n,m;
    int f(int i, int j, vector<vector<int>>& mat){
        if(j < 0 or j >= m) return INT_MAX;
        if(i==0) return mat[0][j];
        int ul = INT_MAX, up = INT_MAX, ur = INT_MAX;
        if(j > 0) ul = mat[i][j] + f(i-1, j-1, mat);
        up = mat[i][j] + f(i-1, j, mat);
        if(j < m-1) ur = mat[i][j] + f(i-1, j+1, mat);
        return min({ul, up, ur});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        int mini = INT_MAX;
        for(int i=0; i<m; i++){
            mini = min(mini, f(n-1, i, matrix));
        }
        return mini;
    }
};

// Memoization
class Solution {
public:
    int n, m;
    int f(int i, int j, vector<vector<int>>& mat, vector<vector<int>>& dp) {
        if (j < 0 || j >= m) return INT_MAX;
        if (i == 0) return mat[0][j];
        if (dp[i][j] != INT_MAX) return dp[i][j];
        int ul = INT_MAX, up = INT_MAX, ur = INT_MAX;
        if (j > 0) ul = mat[i][j] + f(i-1, j-1, mat, dp);
        up = mat[i][j] + f(i-1, j, mat, dp);
        if (j < m-1) ur = mat[i][j] + f(i-1, j+1, mat, dp);
        return dp[i][j] = min({ul, up, ur});
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, f(n-1, j, matrix, dp));
        }
        return mini;
    }
};

// Tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        for(int j = 0; j < m; j++) {
            dp[0][j] = mat[0][j];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int ul = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int up = dp[i-1][j];
                int ur = (j < m-1) ? dp[i-1][j+1] : INT_MAX;
                dp[i][j] = mat[i][j] + min({ul, up, ur});
            }
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};

// Space Optimization
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> dp(m, 0);
        for(int j = 0; j < m; j++) {
            dp[j] = mat[0][j];
        }
        for(int i = 1; i < n; i++) {
            vector<int> temp(m, 0);
            for(int j = 0; j < m; j++) {
                int ul = (j > 0) ? dp[j-1] : INT_MAX;
                int up = dp[j];
                int ur = (j < m-1) ? dp[j+1] : INT_MAX;
                temp[j] = mat[i][j] + min({ul, up, ur});
            }
            dp = temp;
        }
        int mini = INT_MAX;
        for (int j = 0; j < m; j++) {
            mini = min(mini, dp[j]);
        }
        return mini;
    }
};
