class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size(), resize = 1;
        int total = pow(2, n)-1;
        vector<int>temp;
        vector<vector<int>>res;

        for(int i = 0;i<=total;i++){
            temp.clear();
            for(int j = 0;j<n;j++){
                if(resize<<j & i) temp.push_back(nums[j]);
            }
            res.push_back(temp);
        }

        return res;
    }
};