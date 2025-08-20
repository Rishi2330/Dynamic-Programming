// Recursion
class Solution {
  public:
    int f(int i, int j, string& s1, string& s2){
        if(i < 0 or j < 0) return 0;
        if(s1[i] == s2[j]) return 1 + f(i-1, j-1, s1, s2); 
        return max(f(i-1, j, s1, s2), f(i, j-1, s1, s2));
    }
    int lcs(string &s1) {
        // code here
        int n = s1.size(), m = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        return f(n-1, m-1, s1, s2);
    }
};

// Memoization
class Solution {
  public:
    int f(int i, int j, string& s1, string& s2, vector<vector<int>>& dp){
        if(i == 0 or j == 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i-1] == s2[j-1]) return 1 + f(i-1, j-1, s1, s2, dp); 
        return dp[i][j] = max(f(i-1, j, s1, s2, dp), f(i, j-1, s1, s2, dp));
    }
    int lcs(string &s1) {
        // code here
        int n = s1.size(), m = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return f(n, m, s1, s2, dp);
    }
};

// Tabulation
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size(), m = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = 0;
        for(int j=0; j<=m; j++) dp[0][j] = 0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1]; 
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        int n = s1.size(), m = s1.size();
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        vector<int> dp(m+1, 0);
        for(int i=1; i<=n; i++){
            vector<int> temp(m+1, 0);
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1]) temp[j] = 1 + dp[j-1]; 
                else temp[j] = max(dp[j], temp[j-1]);
            }
            dp = temp;
        }
        return dp[m];
    }
};
