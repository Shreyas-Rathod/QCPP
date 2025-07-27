class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        if(n == 1) return 1;
        string s1 = s;
        reverse(s1.begin(), s1.end());
        vector<int>prev(n+1, 0), curr(n+1, 0);

        for(int r = 1;r<=n;r++){
            fill(curr.begin(), curr.end(), 0);
            for(int i = 1;i<=n;i++){
                curr[i] = (s1[r-1] == s[i-1]) ? 1 + prev[i-1] : max(curr[i-1], prev[i]);
            }
            prev = curr;
        }

        return curr[n];
    }
};