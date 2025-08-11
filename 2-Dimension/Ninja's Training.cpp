// Recursion
int f(int idx, int last, vector<vector<int>> &points){
    if(idx == 0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i != last){
            int point = points[idx][i] + f(idx - 1, i, points);
            maxi = max(maxi, point);
        }
    }
    return maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    return f(n-1, -1, points);
}

// Memoization
int f(int idx, int last, vector<vector<int>> &points, vector<vector<int>>& dp){
    if(idx == 0){
        int maxi = 0;
        for(int i=0; i<3; i++){
            if(i != last){
                maxi = max(maxi, points[0][i]);
            }
        }
        return maxi;
    }
    if(dp[idx][last] != -1) return dp[idx][last];
    int maxi = 0;
    for(int i=0; i<3; i++){
        if(i != last){
            int point = points[idx][i] + f(idx - 1, i, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[idx][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4,-1));
    return f(n-1, 3, points, dp);
}

// Tabulation
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<vector<int>> dp(n, vector<int>(4, 0));
    
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max({points[0][0], points[0][1], points[0][2]});

    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            //dp[day][last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}

//Space Optimization
int ninjaTraining(int n, vector<vector<int>> &points) {
    vector<int> prev(4, 0), curr(4, 0);
    // Base case for day 0
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max({points[0][0], points[0][1], points[0][2]});
    // Iterate over days
    for (int day = 1; day < n; day++) {
        for (int last = 0; last < 4; last++) {
            curr[last] = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    int point = points[day][task] + prev[task];
                    curr[last] = max(curr[last], point);
                }
            }
        }
        prev = curr; // move to next day
    }
    return prev[3]; // 3 means no restriction for last day
}
