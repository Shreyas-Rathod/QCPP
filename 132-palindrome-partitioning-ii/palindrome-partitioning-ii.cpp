class Solution {
public:
    bool fun(int i, int j, string &s){
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCut(string s) {
        int n = s.size(), res = INT_MAX;
        vector<int>dp(n+1, 0);
        dp[n] = 0;

        for(int i = n-1;i>=0;i--){
            res = INT_MAX;
            for(int j = i;j<n;j++){
                if(fun(i, j, s)){
                    res = min(res, 1 + dp[j+1]);
                }
            }
            dp[i] = res;
        }

        return dp[0]-1;

    }
};