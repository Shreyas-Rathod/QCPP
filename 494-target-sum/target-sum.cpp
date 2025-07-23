class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(), mod = (int)1e9+7;
        int total = accumulate(nums.begin(), nums.end(), 0);
    
        if((total+target)%2 || total < abs(target)) return 0;
        target = (total + target)/2;
        vector<int>dp(target+1, 0);
        
        dp[0] = (nums[0] == 0) ? 2 : 1;
        if(nums[0] != 0 && nums[0] <= target) dp[nums[0]] = 1;

        for(int i = 1;i<n;i++){
            for(int k = target;k>=nums[i];k--){
                dp[k] = (dp[k] + dp[k-nums[i]])%mod;
            }
        }

        return dp[target];
        

    }
};