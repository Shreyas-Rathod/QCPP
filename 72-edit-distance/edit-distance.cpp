class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size(), sub, ins, del;
        vector<int>prev(n2+1, 0), curr(n2+1, 0);
        for(int i = 0;i<=n2;i++) prev[i] = i;

        for(int i = 1;i<=n1;i++){
            curr[0] = i;
            for(int j = 1;j<=n2;j++){
                ins = prev[j-1];
                if(word1[i-1] != word2[j-1]) ins++;
                del = 1 + prev[j];
                sub = 1 + curr[j-1];
                curr[j] = min(ins, min(del, sub));
            }
            prev = curr;
        }

        return prev[n2];
    }
};