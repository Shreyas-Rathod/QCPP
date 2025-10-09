class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i = n-1;i>=0;i--){
            for(int prev = 0;prev<=n;prev++){
                int nottaken = dp[i+1][prev];
                int taken = 0;
                if(prev == 0 || nums[i] > nums[prev-1]) taken = 1 + dp[i+1][i+1];
                dp[i][prev] = max(nottaken, taken);
            }
        }

        return dp[0][0];
    }
};