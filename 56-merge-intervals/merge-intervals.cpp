class Solution {
public:
    static bool fun(vector<int>&A, vector<int>&B){
        return A[0]<B[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& ivals) {
        int n = ivals.size(), temp;
        vector<int>v;
        vector<vector<int>>res;
        sort(ivals.begin(), ivals.end(), fun);
        res.push_back(ivals[0]);
        for(int i = 1;i<n;i++){
            v = res.back();
            if(v[1]>=ivals[i][0]){
                res.pop_back();
                v[1] = max(v[1], ivals[i][1]);
                res.push_back(v);
            }
             else res.push_back(ivals[i]);
        }
        return res;
    }
};



