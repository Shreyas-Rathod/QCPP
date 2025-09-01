class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        long long total = 0;  // result can get big

        for (int i = 0; i < n; i++) {
            vector<int> freq(26, 0);   // reset for each start i
            int maxi = 0;              // track max incrementally

            for (int j = i; j < n; j++) {
                int idx = s[j] - 'a';
                freq[idx]++;
                maxi = max(maxi, freq[idx]);

                int mini = INT_MAX;
                for (int c = 0; c < 26; c++) {
                    if (freq[c] > 0) mini = min(mini, freq[c]);  // only positive counts
                }

                total += (maxi - mini);
            }
        }

        return (int)total;
    }
};
