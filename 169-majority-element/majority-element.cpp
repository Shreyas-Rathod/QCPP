class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), cnt = 0, candi;
        for(int i = 0;i<n;i++){
            if(cnt == 0) candi = nums[i], cnt++;
            else if(candi == nums[i]) cnt++;
            else cnt--;
        }
        return candi;
    }
};