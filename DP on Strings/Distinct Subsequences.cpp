// Recursion
class Solution {
public:
    int f(int i, int j, string s1, string s2){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(s1[i] == s2[j]){
            return f(i-1, j-1, s1, s2) + f(i-1, j, s1, s2);
        }
        return f(i-1, j, s1, s2);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return f(n-1, m-1, s, t);
    }
};

// Memoization
class Solution {
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if(j < 0) return 1;
        if(i < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
        }
        return dp[i][j] = f(i-1, j, s1, s2, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return f(n-1, m-1, s, t, dp);
    }
};
//-> similar
class Solution {
public:
    int f(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if(j == 0) return 1;
        if(i == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]){
            return dp[i][j] = f(i-1, j-1, s1, s2, dp) + f(i-1, j, s1, s2, dp);
        }
        return dp[i][j] = f(i-1, j, s1, s2, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s, t, dp);
    }
};

// Tabulation
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 1;
        for(int j=1; j<=m; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> dp(m+1, 0), temp(m+1, 0);
        dp[0] = temp[0] = 1;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s[i-1] == t[j-1]) temp[j] = dp[j-1] + dp[j];
                else temp[j] = dp[j];
            }
            dp = temp;
        }
        return dp[m];
    }
};
