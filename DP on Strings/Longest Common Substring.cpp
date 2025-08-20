// Tabulation
int lcs(string &str1, string &str2){
    // Write your code here.
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=0; i<=n; i++) dp[i][0] = 0;
    for(int j=0; j<=m; j++) dp[0][j] = 0;
    int ans = 0;
    for(int i = 1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
                ans = max(ans, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    return ans;
}

// Space Optimization
int lcs(string &str1, string &str2){
    // Write your code here.
    int n = str1.size();
    int m = str2.size();
    vector<int> dp(m+1, 0);
    int ans = 0;
    for(int i = 1; i<=n; i++){
        vector<int> temp(m+1, 0);
        for(int j=1; j<=m; j++){
            if(str1[i-1] == str2[j-1]){
                temp[j] = 1 + dp[j-1];
                ans = max(ans, temp[j]);
            }
            else temp[j] = 0;
        }
        dp = temp;
    }
    return ans;
}
