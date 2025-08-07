class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        vector<int>dp(n, 1), cnt(n, 1);

        for(int i = 0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(nums[i] > nums[prev] && dp[prev] + 1 > dp[i]){
                    dp[i] = dp[prev] + 1;
                    cnt[i] = cnt[prev];
                }
                else if(nums[i] > nums[prev] && dp[prev] + 1 == dp[i]){
                    cnt[i] += cnt[prev];
                }
            }
            if(maxi < dp[i]) maxi = dp[i];
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(maxi == dp[i]) res += cnt[i];
        }
        return res;
    }
};