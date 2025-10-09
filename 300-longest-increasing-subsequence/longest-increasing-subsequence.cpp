class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size(), i;
        vector<int>tail;
        for(auto x : nums){
            if(tail.empty() || x > tail.back()) tail.push_back(x);
            else{
                i = lower_bound(tail.begin(), tail.end(), x) - tail.begin();
                tail[i] = x;
            }
        }

        return tail.size();
    }
};