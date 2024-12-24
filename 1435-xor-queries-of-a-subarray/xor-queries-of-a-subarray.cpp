class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        vector<int>presum, res;
        presum.push_back(arr[0]);
        for(int i = 1;i<n;i++) presum.push_back(presum[i-1]^arr[i]);
        for(int i = 0;i<m;i++){
            if(queries[i][0] == 0) res.push_back(presum[queries[i][1]]);
            else res.push_back(presum[queries[i][1]]^presum[queries[i][0]-1]);
        }
        return res;
    }
};