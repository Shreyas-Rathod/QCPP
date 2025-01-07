class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int maxi = INT_MIN, mini = INT_MAX, count = 0, k;
        vector<int>mp(26, 0);

        auto minfun = [&](){
            k = INT_MAX;
            for(int it : mp){
                if(it <= k && it > 0) k = it;
            }
            return k;
        };

        auto maxfun = [&](){
            k = INT_MIN;
            for(int it : mp){
                if(it >= k) k = it;
            }
            return k;
        };

        for(int i = 0;i<n;i++){
            for(int j = i;j<n;j++){
                mp[s[j] - 'a']++;
                maxi = maxfun();
                mini = minfun();
                count += (maxi - mini);
            }
            fill(mp.begin(), mp.end(), 0);
        }

        return count;
    }
};