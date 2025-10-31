class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        for(int i = 0;i<n;i++) nums[i]++;
        for(int i = 0;i<n;i++){
            nums[abs(nums[i])-1] = -nums[abs(nums[i])-1]; 
        }
        for(int i = 0;i<n-2;i++) if(nums[i] > 0) res.push_back(i);
        if(res.size() == 1) res.push_back(0);

        return res;
    }
};