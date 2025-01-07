class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int>smp, tmp;
        int n = s.size();
        for(int i = 0;i<n;i++){
            if(smp[s[i]] != tmp[t[i]]) return false;
            smp[s[i]] = i + 1;
            tmp[t[i]] = i + 1;
        }
        return true;
    }
};