class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ccnt = 0, maxcnt = 0, n = nums.size();
        for(int i = 0;i<n;i++){
            if(nums[i] == 1)ccnt++;
            else maxcnt = max(maxcnt, ccnt), ccnt = 0;
        }
        maxcnt = max(maxcnt, ccnt);
        return maxcnt;
    }
};