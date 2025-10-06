class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int target = 0;

        for(int i = 0;i<n;i++) target += nums[i];
        if(target%2) return false;
        int tar = target/2;

        vector<vector<bool>>dp(tar+1, vector<bool>(n, false));

        for(int i = 0;i<n;i++) dp[0][i] = true;
        if(nums[0] <= tar) dp[nums[0]][0] = true;

        for(int i = 1;i<n;i++){
            for(int sum = 1;sum<=tar;sum++){
                bool nottaken = dp[sum][i-1], taken = false;
                if(nums[i] <= sum) taken = dp[sum-nums[i]][i-1];
                dp[sum][i] = nottaken || taken;
            }
        }

        return dp[tar][n-1];
    }
};