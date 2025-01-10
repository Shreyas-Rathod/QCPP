class Solution {
public:
    void genfun(vector<vector<int>>&res, vector<int>&temp, int k, int n, int i){
        if(k==0 && n==0 && i==10){
            res.push_back(temp);
            return;
        }
        if(i<10){
            temp.push_back(i);
            if(i<=n) genfun(res, temp, k-1, n-i, i+1);
            temp.pop_back();
            genfun(res, temp, k, n, i+1);
        }
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>temp;
        genfun(res, temp, k, n, 1);
        return res;
    }
};