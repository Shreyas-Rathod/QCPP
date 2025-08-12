class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(), maxi, res, len;
        vector<int>dp(n+1, 0);
        for(int i = n-1;i>=0;i--){
            len = 0;
            maxi = INT_MIN, res = INT_MIN;
            for(int j = i;j<min(n, i+k);j++){
                len++;
                maxi = max(maxi, arr[j]);
                res = max(maxi*len + dp[j+1], res);
            }
            dp[i] = res;
        }
        return dp[0];
    }
};