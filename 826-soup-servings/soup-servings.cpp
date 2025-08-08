class Solution {
public:
    double fun(vector<vector<double>>&dp, int a, int b){
        if(a <= 0){
            if(b <= 0) return 0.5;
            else return 1.0;
        }
        else if(b <= 0) return 0.0;

        if(dp[a][b] != -1) return dp[a][b];

        double p1, p2, p3, p4;
        p1 = 0.25 * fun(dp, a - 100, b);
        p2 = 0.25 * fun(dp, a - 75, b - 25);
        p3 = 0.25 * fun(dp, a - 50, b - 50);
        p4 = 0.25 * fun(dp, a - 25, b - 75);

        return dp[a][b] = p1 + p2 + p3 + p4;

    }
    double soupServings(int n) {
        if(n >= 25100) return 1.0;
        vector<vector<double>>dp(n+1, vector<double>(n+1, -1));

        return fun(dp, n, n);

    }
};