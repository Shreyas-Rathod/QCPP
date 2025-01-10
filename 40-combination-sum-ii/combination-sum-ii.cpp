class Solution {
public:
    void genfun(vector<int>&candi, int target, int i, vector<vector<int>>&res, vector<int>&temp){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        for(int k = i;k<candi.size();k++){
            if(k>i && candi[k]==candi[k-1]) continue;
            if(candi[k]>target) break;
            temp.push_back(candi[k]);
            genfun(candi, target-candi[k], k+1, res, temp);
            temp.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        sort(candi.begin(), candi.end());
        genfun(candi, target, 0, res, temp);
        return res;
    }
};