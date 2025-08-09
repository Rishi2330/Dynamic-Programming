#include <bits/stdc++.h> 
using namespace std;
// Memoization
int f(int n, vector<int> &h, vector<int>& dp){
    if(n == 0) return 0;
    if (dp[n] != -1) return dp[n];
    int l = f(n-1, h, dp) + abs(h[n] - h[n-1]);
    int r = INT_MAX;
    if(n > 1) r = f(n-2, h, dp) + abs(h[n] - h[n-2]);
    return dp[n] = min(l, r);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return f(n-1, heights, dp);
}
// Tabulization
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, 0);
    //dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int oneStep = dp[i - 1] + abs(height[i] - height[i - 1]);
        int twoStep = INT_MAX;
        if (i > 1) twoStep = dp[i - 2] + abs(height[i] - height[i - 2]);        
        dp[i] = min(oneStep, twoStep);
    }
    return dp[n - 1];
}

int main(){
    vector<int> arr = {30,10,60,10,60,50};
    cout << frogJump(6,arr);
}
