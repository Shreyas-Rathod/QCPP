class Solution {
public:
/*    int coinChange(vector<int>& coins, int V) {
        int n = coins.size(), cnt = INT_MAX, si = 0, amount = V;
        if(amount == 0) return 0;
        while(si < n && amount >= coins[si]) si++;

        for(int i = si-1;i>=0;i--){
            int cnt2 = 0;
            for(int j = i;j>=0;j--){
                while(amount >= coins[j]){
                    amount -= coins[j];
                    cnt2++;
                }
            }
            cout << cnt2 << endl;
            if(amount == 0) cnt = min(cnt, cnt2);
            amount = V;
        }
        return cnt == INT_MAX ? -1 : cnt;
    }
//memoization   
    int fun(int index, int T, vector<vector<int>>&dp, vector<int>&coins){
        
        if(index == 0){
            if(T%coins[0] == 0) return T/coins[0];
            else return 1e9+7;
        }

        if(dp[index][T] != -1) return dp[index][T];

        int notaken = fun(index-1, T, dp, coins);
        int taken = 1e9+7;
        if(coins[index] <= T) taken = 1 + fun(index, T-coins[index], dp, coins);

        return dp[index][T] = min(notaken, taken);
    }

    int coinChange(vector<int>&coins, int V){
        int n = coins.size(), amount = V;
        if(!amount) return 0;

        vector<vector<int>>dp(n, vector<int>(V+1, -1));

        int cnt = fun(n-1, V, dp, coins);
        return cnt == 1e9+7 ? -1 : cnt;
    }
*/
    int coinChange(vector<int>&coins, int T){
        int n = coins.size();
        if(!T) return 0;

        vector<vector<int>>dp(n, vector<int>(T+1, 0));

        for (int i = 0; i <= T; i++) {
            if (i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9; 
        }

        for(int i = 1;i<n;i++){
            for(int k = 0;k<=T;k++){
                int ntaken = dp[i-1][k];
                int taken = 1e9;
                if(coins[i] <= k) taken = 1 + dp[i][k-coins[i]];
                dp[i][k] = min(ntaken, taken);
            }
        }

        if(dp[n-1][T] >= 1e9) return -1;
        return dp[n-1][T];
    }
};