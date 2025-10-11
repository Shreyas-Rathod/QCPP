class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 0, res = 0;
        vector<int>cnt(n, 1), dp(n, 1);

        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    cnt[i] = cnt[j];
                }
                else if(dp[i] == dp[j] + 1) cnt[i] += cnt[j];
            }
            if(dp[maxi] < dp[i]) maxi = i;
        }

        for(int i = 0;i<n;i++){
            if(dp[maxi] == dp[i]) res+=cnt[i];
        }

        return res;
    }
};