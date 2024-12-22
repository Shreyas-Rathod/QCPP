class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size(), cnt = 0, temp = 0, presum = 0;
        unordered_map<int, int>mp;
        mp[0] = 1;
        for(int i = 0;i<n;i++){
            presum += nums[i];
            temp = presum - k;
            cnt += mp[temp];
            mp[presum]++;
        }
        return cnt;
    }
};