class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size(), fact;
        vector<int>dp(n, 0);
        dp[0] = triangle[0][0];
        for(int i = 1;i<n;i++){
            dp[i] = dp[i-1] + triangle[i][i];
            for(int j = i-1;j>0;j--){
                dp[j] = min(dp[j], dp[j-1]) + triangle[i][j];
            }
            dp[0] += triangle[i][0];
        }

        return *min_element(dp.begin(), dp.end());
    }
};