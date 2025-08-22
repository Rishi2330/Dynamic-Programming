// Recursion
class Solution {
public:
    int solve(int i,int j, string w1, string w2){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(w1[i]==w2[j]){
            return solve(i-1,j-1,w1,w2);
        }
        return 1+min(solve(i-1,j,w1,w2),min(solve(i,j-1,w1,w2),solve(i-1,j-1,w1,w2)));
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return solve(n-1,m-1,word1,word2);
    }
};

// Memoization
class Solution {
public:
    int solve(int i,int j, string w1, string w2, vector<vector<int>>& dp){
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j] != -1) return dp[i][j];
        if(w1[i]==w2[j]){
            return dp[i][j] = 0 + solve(i-1,j-1,w1,w2, dp);
        }
        return dp[i][j] = 1 + min({solve(i-1,j,w1,w2,dp),solve(i,j-1,w1,w2,dp),solve(i-1,j-1,w1,w2,dp)});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1,m-1,word1,word2, dp);
    }
};

// Tabulation
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for(int i=0; i<=n; i++) dp[i][0] = i; 
        for(int j=0; j<=m; j++) dp[0][j] = j;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = 0 + dp[i-1][j-1];
                else dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
        return dp[n][m];
    }
};

// Space Optimization
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int> dp(m+1, 0), temp(m+1, 0);
        for(int j=0; j<=m; j++) dp[j] = j;
        for(int i=1; i<=n; i++){
            temp[0] = i;
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]) temp[j] = 0 + dp[j-1];
                else temp[j] = 1 + min({dp[j], temp[j-1], dp[j-1]});
            }
            dp = temp;
        }
        return dp[m];
    }
};
