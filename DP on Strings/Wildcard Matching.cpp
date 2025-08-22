// Recursion
class Solution {
  public:
    bool f(int i, int j, string s1, string s2){
        if(i < 0 and j < 0) return true;
        if(i < 0 and j >= 0) return false;
        if(j < 0 and i >= 0){
            for(int k=0; k<=i; k++){
                if(s1[k] != '*') return false;
            }
            return true;
        }
        if(s1[i] == s2[j] || s1[i] == '?') return f(i-1, j-1, s1, s2);
        if(s1[i] == '*') return f(i-1, j, s1, s2) or f(i, j-1, s1, s2);
        return false;
    }
    bool match(string wild, string pattern) {
        // code here
        int n = wild.size();
        int m = pattern.size();
        return f(n-1, m-1, wild, pattern);
    }
};

// Memoization
class Solution {
  public:
    bool f(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if(i < 0 and j < 0) return true;
        if(i < 0 and j >= 0) return false;
        if(j < 0 and i >= 0){
            for(int k=0; k<=i; k++){
                if(s1[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j] || s1[i] == '?') return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        if(s1[i] == '*') return dp[i][j] = f(i-1, j, s1, s2, dp) or f(i, j-1, s1, s2, dp);
        return false;
    }
    bool match(string wild, string pattern) {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        return f(n-1, m-1, wild, pattern, dp);
    }
};
// -> Similar way with 1-Based Indexing
class Solution {
  public:
    bool f(int i, int j, string s1, string s2, vector<vector<int>>& dp){
        if(i == 0 and j == 0) return true;
        if(i == 0 and j > 0) return false;
        if(j == 0 and i > 0){
            for(int k=1; k < i; k++){
                if(s1[k-1] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1] || s1[i-1] == '?') return dp[i][j] = f(i-1, j-1, s1, s2, dp);
        if(s1[i-1] == '*') return dp[i][j] = f(i-1, j, s1, s2, dp) or f(i, j-1, s1, s2, dp);
        return false;
    }
    bool match(string wild, string pattern) {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return f(n, m, wild, pattern, dp);
    }
};

// Tabulation
class Solution {
  public:
    bool match(string wild, string pattern) {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;
        for(int i=1; i<=n; i++){
            bool flag = true;
            for(int k=1; k<=i; k++){
                if(wild[k-1] != '*'){
                    flag = false;
                    break;
                } 
            }
            dp[i][0] = flag;
            
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(wild[i-1] == pattern[j-1] || wild[i-1] == '?') dp[i][j] = dp[i-1][j-1];
                else if(wild[i-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];
                else dp[i][j] = false;
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
  public:
    bool match(string wild, string pattern) {
        // code here
        int n = wild.size();
        int m = pattern.size();
        vector<bool> dp(m+1, false), temp(m+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            bool flag = true;
            for(int k=1; k<=i; k++){
                if(wild[k-1] != '*'){
                    flag = false;
                    break;
                } 
            }
            temp[0] = flag;
        }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(wild[i-1] == pattern[j-1] || wild[i-1] == '?') temp[j] = dp[j-1];
                else if(wild[i-1] == '*') temp[j] = dp[j] or temp[j-1];
                else temp[j] = false;
            }
            dp = temp;
        }
        return dp[m];
    }
};
