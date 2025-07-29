class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n1 = str1.size(), n2 = str2.size();
        if(str1 == str2) return str1;

        vector<vector<int>>dp(n1+1, vector<int>(n2+1, 0));

        for(int i = 1;i<=n1;i++){
            for(int j = 1;j<=n2;j++){
                dp[i][j] = (str1[i-1] == str2[j-1]) ? 1 + dp[i-1][j-1] : max(dp[i-1][j], dp[i][j-1]);
            }
        }

        string common = "";
        int i = n1, j = n2;

        while(i > 0 && j > 0){
            if(str1[i-1] == str2[j-1]) {
                common += str1[i-1];
                i--;
                j--;
            }
            else if(dp[i][j-1] < dp[i-1][j]){
                common += str1[i-1];
                i--;
            }
            else{
                common += str2[j-1];
                j--;
            }
        }

        while(i > 0){
            common += str1[i-1];
            i--;
        }
        while(j > 0){
            common += str2[j-1];
            j--;
        }

        reverse(common.begin(), common.end());

        return common;

    }
};