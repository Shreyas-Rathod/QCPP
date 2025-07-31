class Solution {
public:
    bool isMatch(string s, string p) {
        int ns = s.size(), np = p.size();
        bool flag = true;

        vector<bool>prev(ns+1, false), curr(ns+1, false);
        prev[0] = true;

        for(int i = 1;i<=np;i++){
            flag = true;
            for(int k = 1;k<=i;k++){
                if(p[k-1] != '*') {flag = false; break;}
            }
            curr[0] = flag;
            for(int j = 1;j<=ns;j++){
                if(s[j-1] == p[i-1] || p[i-1] == '?') curr[j] = prev[j-1];
                else if(p[i-1] == '*') curr[j] = curr[j-1] || prev[j];
                else curr[j] = false;
            }
            prev = curr;
        }

        return prev[ns];

    }
};