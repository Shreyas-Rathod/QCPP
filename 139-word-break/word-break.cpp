class Solution {
public:
    bool checkfun(string &s, set<string>&mp, int st, vector<int>&memo){
        if(st == s.length()) return true;
        if(memo[st]!=-1) return memo[st];
        for(int end = st+1;end<=s.length();end++){
            if(mp.find(s.substr(st, end-st))!=mp.end() and checkfun(s, mp, end, memo)) return memo[st]=true;
        }
        return memo[st] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> mp(wordDict.begin(), wordDict.end());
        vector<int>memo(s.size(), -1);
        return checkfun(s, mp, 0, memo);
    }
};