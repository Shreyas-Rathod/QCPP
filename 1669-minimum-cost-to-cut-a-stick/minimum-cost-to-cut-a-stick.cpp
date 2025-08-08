class Solution {
public:
    int fun(vector<int>&cuts, int i, int j, vector<vector<int>>&dp){
        if(i > j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int mini = INT_MAX, ans;
        for(int ind = i;ind<=j;ind++){
            ans = cuts[j+1] - cuts[i-1] + fun(cuts, i, ind-1, dp) + fun(cuts, ind+1, j, dp);
            mini = min(mini, ans);
        }
        return dp[i][j] = mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>>dp(c+1, vector<int>(c+1, -1));

        return fun(cuts, 1, c, dp);
    }
};