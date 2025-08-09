class Solution {
public:
    int fun(int i, int j, vector<int>&nums, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int maxi = INT_MIN, ans;
        for(int x = i;x<=j;x++){
            ans = nums[i-1]*nums[x]*nums[j+1] + fun(i, x-1, nums, dp) + fun(x+1, j, nums, dp);
            maxi = max(ans, maxi);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        vector<vector<int>>dp(n+2, vector<int>(n+2, 0));

        // return fun(1, n, nums, dp);
        for(int i = n;i>=1;i--){
            for(int j = i;j<=n;j++){
                int maxi = INT_MIN, ans;
                for(int x = i;x<=j;x++){
                    ans = nums[i-1]*nums[x]*nums[j+1] + dp[i][x-1] + dp[x+1][j];
                    maxi = max(ans, maxi);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n];

    }
};