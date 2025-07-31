class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.size(), n2 = t.size(), mod = 1e9+7;

        vector<int>prev(n2+1, 0);
        prev[0] = 1;

        for(int i = 1;i<=n1;i++){
            for(int j = n2;j>0;j--){
                if(s[i-1] ==  t[j-1]) prev[j] = (prev[j] + prev[j-1])%mod;
            }
        }

        return prev[n2];
    }
};