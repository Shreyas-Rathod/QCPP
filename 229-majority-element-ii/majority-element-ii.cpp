class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = 0, cnt2 = 0, candi1 = INT_MIN, candi2 = INT_MIN;
        for(int i = 0;i<n;i++){
            if(candi1 == nums[i]) cnt1++;
            else if(candi2 == nums[i]) cnt2++;
            else if(cnt1 == 0) candi1 = nums[i], cnt1++;
            else if(cnt2 == 0) candi2 = nums[i], cnt2++;
            else cnt1--, cnt2--; 
        }

        int c1 = 0, c2 = 0;
        for(int x : nums){
            if(x == candi1) c1++;
            if(x == candi2) c2++;
        }

        vector<int>res;
        if((int)(n/3) < c1) res.push_back(candi1);
        if((int)(n/3) < c2) res.push_back(candi2);

        return res;
    }
};