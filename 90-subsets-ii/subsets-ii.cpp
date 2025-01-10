class Solution {
public:
    void gensubset(vector<int>&nums, vector<vector<int>>&res, int k,  vector<int>&temp){
       res.push_back(temp);
       for(int i = k;i<nums.size();i++){
            if(i>k && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            gensubset(nums, res, i+1, temp);
            temp.pop_back();
       }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>>res;
        vector<int>temp;
        gensubset(nums, res, 0, temp);
        return res;
    }
};