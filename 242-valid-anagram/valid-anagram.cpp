class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>count(26, 0);
        int ns = s.size(), nt = t.size(), temp;

        if(ns != nt) return false;
        for(int i = 0;i<ns;i++) count[s[i] - 'a']++;
        for(int i = 0;i<nt;i++) count[t[i] - 'a']--;
        for(int i = 0;i<26;i++){
            if(count[i]) return false;
        }
        return true;
    }
};