class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        if(word1 == word2) return 0;

        vector<int>prev(n1+1, 0), curr(n1+1, 0);

        for(int i = 1;i<=n2;i++){
            fill(curr.begin(), curr.end(), 0);
            for(int j = 1;j<=n1;j++){
                curr[j] = (word1[j-1] == word2[i-1]) ? 1 + prev[j-1] : max(prev[j], curr[j-1]);
            }
            prev = curr;
        }

        return n2 + n1 - 2*curr[n1];
    }
};