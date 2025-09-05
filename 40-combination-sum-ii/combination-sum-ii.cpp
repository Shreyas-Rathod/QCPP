class Solution {
public:
    void findcomb(vector<int>&cand, int k, int csum, int idx, vector<vector<int>>&res, vector<int>&cc){
        int prev = -1;
        for(int i = idx;i<cand.size();i++){
            if(csum + cand[i] > k) break;
            if(prev == cand[i]) continue;
            cc.push_back(cand[i]);
            findcomb(cand, k, csum + cand[idx], i+1, res, cc);
            cc.pop_back();
            prev = cand[i];
        }
        if(accumulate(cc.begin(), cc.end(), 0) == k) res.push_back(cc);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>>res;
        vector<int>cc;
        findcomb(candidates, target, 0, 0, res, cc);
        return res;
    }
};