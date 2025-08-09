#include <bits/stdc++.h> 
using namespace std;
// Memoization
int f(int n, vector<int>& heights, int k, vector<int>& dp){
    if(n == 0) return 0;
    if(dp[n] != -1) return dp[n];
    int mini = INT_MAX;
    for(int i=1; i<=k; i++){
        int steps = INT_MAX;
        if(n-i >= 0) steps = f(n-i, heights, k, dp) + abs(heights[n]  - heights[n-i]);
        mini = min(mini, steps);
    }
    return dp[n] = mini;
}
// Tabulation
int frogJump(vector<int>& heights, int k) {
    int n = heights.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= k && i - j >= 0; j++) {
            dp[i] = min(dp[i], dp[i - j] + abs(heights[i] - heights[i - j]));
        }
    }
    return dp[n-1];
}
int main(){
    vector<int> arr = {15, 4, 1, 14, 15};
    cout << frogJump(arr, 3);
}
