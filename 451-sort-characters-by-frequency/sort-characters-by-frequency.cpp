class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        map<char, int>mp;
        for(char x : s) {
            if(x != ' ') mp[x]++;
        }
        vector<pair<char, int>>mpss(mp.begin(), mp.end());
        sort(mpss.begin(), mpss.end(), [](auto &a, auto &b){
            return a.second > b.second;
        });
        string res = "";
        for(auto &p : mpss){
            res.append(p.second, p.first);
        }

        return res;
    }
};