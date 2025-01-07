class Solution {
public:
    string reverseWords(string s) {
        int st = 0, ed = 0;
        reverse(s.begin(), s.end());
        while(s[0] == ' ') s.erase(s.begin());
        while(s[s.size()-1] == ' ') s.erase(s.begin() + s.size() - 1);
        int n = s.size();
        for(ed;ed<s.size();ed++){
            if(s[ed] == ' '){
                reverse(s.begin() + st, s.begin()+ed);
                while(s[ed+1] == ' ') s.erase(s.begin() + ed + 1);
                st = ed+1;
            }
        }
        reverse(s.begin() + st, s.begin()+ed);
        return s;
    }
};