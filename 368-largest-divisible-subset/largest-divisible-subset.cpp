class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        vector<int>prev(n, -1), dp(n, 1);
        sort(nums.begin(), nums.end());
        for(int i = 0;i<n;i++){
            for(int j = 0;j<i;j++){
                if((nums[i] % nums[j] == 0) && dp[i] < dp[j] + 1){
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if(dp[i] > dp[maxi]) maxi = i;
        }

        vector<int>res;
        for(int i = maxi;i >= 0;i = prev[i]){
            res.push_back(nums[i]);
        }

        return res;

    }
};