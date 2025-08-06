class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        sort(nums.begin(), nums.end());
        vector<int>dp(n, 1);
        vector<int>hash(n, -1);
        for(int i = 0;i<n;i++){
            for(int prev = 0;prev<i;prev++){
                if(!(nums[i] % nums[prev]) && dp[i] < dp[prev] + 1){
                    dp[i] = 1 + dp[prev];
                    hash[i] = prev;
                }
                if(dp[i] > dp[maxi]) maxi = i;
            }
        }
        vector<int>res;
        for(int i = maxi;i>=0;i = hash[i]) res.push_back(nums[i]);
        return res;
    }
};