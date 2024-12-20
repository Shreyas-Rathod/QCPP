class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        int res = 0, count = 1, temp;
        unordered_set<int>s;
        for(int i = 0;i<n;i++) s.insert(nums[i]);

        for(int i : s){
            if(s.find(i-1) == s.end()){
                count = 1;
                temp = i;
                while(s.find(temp+1) != s.end()){
                    temp++;
                    count++;
                }
                res = max(res, count);
            }
        }

        return res;
    }
};