class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int>mp;
        for(int i = 0;i<n;i++){
            if(mp.count(target - nums[i])) return {i, mp[target-nums[i]]};
            mp[nums[i]] = i;
        }
        return {};
    }
};