class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int>pres(n, 0);
        pres[0] = nums[0];
        for(int i = 1;i<n;i++) pres[i] = pres[i-1] + nums[i];

        for(int i = 0;i<n;i++){
            if(!nums[i]){
                int left = pres[i];
                int right = pres[n-1] - pres[i];
                if(abs(left - right) == 0) res += 2;
                else if(abs(left - right) == 1) res ++;
            }
        }

        return res;
    }
};