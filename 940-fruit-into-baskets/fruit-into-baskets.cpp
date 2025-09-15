class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int start = 0, res = 0;

        unordered_map<int, int>mp;
        for(int i = 0;i<n;i++){
            mp[fruits[i]]++;
            while(mp.size() > 2){
                mp[fruits[start]]--;
                if(mp[fruits[start]] == 0) mp.erase(fruits[start]);
                start++;
            }
            res = max(res, i - start + 1);
        }

        return res; 
    }
};