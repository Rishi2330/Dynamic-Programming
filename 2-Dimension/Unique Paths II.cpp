// Recursion
class Solution {
public:
    int f(int i, int j,vector<vector<int>> obstacleGrid){
        if(i >=0 and j >= 0 and obstacleGrid[i][j]==1) return 0;
        if(i == 0 and j == 0) return 1;
        if(i < 0 or j < 0) return 0;
        int up = 0, left = 0;
        if(i > 0) up = f(i-1, j, obstacleGrid);
        if(j > 0) left = f(i, j-1, obstacleGrid);
        return up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        return f(n-1, m-1, obstacleGrid);
    }
};

// Memoization
class Solution {
public:
    int f(int i, int j,vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp){
        if(i >=0 and j >= 0 and obstacleGrid[i][j]==1) return 0;
        if(i == 0 and j == 0) return 1;
        if(i < 0 or j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = 0, left = 0;
        if(i > 0) up = f(i-1, j, obstacleGrid, dp);
        if(j > 0) left = f(i, j-1, obstacleGrid, dp);
        return dp[i][j] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, obstacleGrid, dp);
    }
};

// Tabulation
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        dp[0][0] = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(obstacleGrid[i][j]==1) continue;
                if(i==0 and j==0) continue;
                int up = 0, left = 0;
                if(i > 0) up = dp[i-1][j];
                if(j > 0) left = dp[i][j-1];
                dp[i][j] = up + left;
            }
        }
        return dp[n-1][m-1];
    }
};

// Space Optimization
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<int> dp(m, 0);
        for(int i=0; i<n; i++){
            vector<int> temp(m, 0);
            for(int j=0; j<m; j++){
                if(obstacleGrid[i][j]==1) continue;
                if(i==0 and j==0) {
                    temp[0] = 1;
                    continue;
                }
                int up = 0, left = 0;
                if(i > 0) up = dp[j];
                if(j > 0) left = temp[j-1];
                temp[j] = up + left;
            } 
            dp = temp;
        }
        return dp[m-1];
    }
};
