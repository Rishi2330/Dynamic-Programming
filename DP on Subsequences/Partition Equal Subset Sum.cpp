class Solution {
  public:
    bool f(int k, vector<int>& arr){
        int n = arr.size();
        vector<bool> prev(k+1, false), curr(k+1, false);
        prev[0] = curr[0] = true;
        if(arr[0] <= k) prev[arr[0]] = true;
        for(int i=1; i<n; i++){
            for(int target = 1; target<=k; target++){
                bool notTake = prev[target];
                bool take = false;
                if(arr[i] <= target) take = prev[target-arr[i]];
                curr[target] = take | notTake;
            }
            prev = curr;
        }
        return prev[k];
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum % 2) return false;
        int target = sum / 2;
        return f(target, arr);
    }
};
