class Solution {
public:
    void genfun(vector<int>&candidates, int target, int i, vector<vector<int>>&res, vector<int>&temp){
        if(i==candidates.size()){
            if(target==0) res.push_back(temp);
            return;
        }
        if(candidates[i]<=target){
            temp.push_back(candidates[i]);
            genfun(candidates, target-candidates[i], i, res, temp);
            temp.pop_back();
        }
        genfun(candidates, target, i+1, res, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>temp;
        genfun(candidates, target, 0, res, temp);
        return res;
    }
};