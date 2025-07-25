class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();

        vector<int>prev(n1, 0), curr(n1, 0);
        int j = 0;
        while(j<n1 && text1[j] != text2[0]) j++;
        if(j<n1) prev[j++] = 1;
        while(j<n1){ prev[j] = prev[j-1]; j++;}

        for(int r = 1;r<n2;r++){
            fill(curr.begin(), curr.end(), 0);
            curr[0] = prev[0];
            if(text1[0] == text2[r]) curr[0] = 1;
            for(int i = 1;i<n1;i++){
                curr[i] = (text1[i] == text2[r]) ? prev[i-1] + 1 : max(curr[i-1], prev[i]);
            }
            prev = curr;
        }

        return prev[n1-1];
    }
};