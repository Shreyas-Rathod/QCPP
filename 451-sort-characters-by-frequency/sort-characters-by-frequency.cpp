class Solution {
public:

    struct sortstruct{
        typedef pair<char, int> type;
        bool operator()(type const&a, type const&b)const{
            return a.second<b.second;
        }
    };
    string frequencySort(string s) {
        map<char, int>mp;
        int n = s.size(), mpss;
        string res;

        for(int i = 0;i<n;i++) mp[s[i]]++;

        vector<pair<char, int>>mpcy(mp.begin(), mp.end());
        sort(mpcy.rbegin(), mpcy.rend(), sortstruct());
        mpss = mpcy.size();
        for(int i = 0;i<mpss;i++){
            for(int j = 0;j<mpcy[i].second;j++) res.push_back(mpcy[i].first);
        }       

        return res;
    }
};