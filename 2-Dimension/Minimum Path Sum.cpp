// Recursion
class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid) {
        if(i == 0 && j == 0) return grid[0][0];
        int up = INT_MAX, left = INT_MAX;
        if(i > 0) up = grid[i][j] + f(i-1, j, grid);
        if(j > 0) {
            left = grid[i][j] + f(i, j-1, grid);
        }
        return min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return f(n-1, m-1, grid);
    }
};

// Memoization
class Solution {
public:
    int f(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
        if(i == 0 && j == 0) return grid[0][0];
        if(dp[i][j] != -1) return dp[i][j];
        int up = INT_MAX, left = INT_MAX;
        if(i > 0) up = grid[i][j] + f(i-1, j, grid, dp);
        if(j > 0) {
            left = grid[i][j] + f(i, j-1, grid, dp);
        }
        return dp[i][j] = min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, grid, dp);
    }
};

// Tabulation
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = grid[0][0];
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(i==0 and j==0) continue;
                int up = INT_MAX, left = INT_MAX;
                if(i > 0) up = grid[i][j] + dp[i-1][j];
                if(j > 0) left = grid[i][j] + dp[i][j-1];
                dp[i][j] = min(up, left);
            }
        }
        return dp[n-1][m-1];
    }
};

// Space Optimization
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> dp(m,0);
        for(int i=0; i<n; i++){
            vector<int> temp(m, 0);
            for(int j=0; j<m; j++){
                if(i==0 and j==0){
                    temp[j] = grid[0][0];
                    continue;
                } 
                int up = INT_MAX, left = INT_MAX;
                if(i > 0) up = grid[i][j] + dp[j];
                if(j > 0) left = grid[i][j] + temp[j-1];
                temp[j] = min(up, left);
            }
            dp = temp;
        }
        return dp[m-1];
    }
};
