class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int>count(value, 0);
        for(int i = 0;i<n;i++){
            int x = (nums[i] % value + value) % value;
            count[x]++;
        }

        for(int i = 0;i<n;i++){
            int required = i % value;
            if(count[required] == 0) return i;
            count[required]--;
        }

        return n;
    }
};