class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pi = -2, ni = -1;
        vector<int>v(n);
        for(int i = 0;i<n;i++){
            if(nums[i]<0){
                ni+=2;
                v[ni] = nums[i];
            }else{
                pi += 2;
                v[pi] = nums[i];
            }
        }
        return v;
    }
};