class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0, cnt = 1, temp;
        set<int>st;
        for(int i = 0;i<n;i++) st.insert(nums[i]);
        for(auto i : st){
            if(st.find(i-1) == st.end()){
                temp = i;
                cnt = 1;
            }
            while(st.find(temp+1) != st.end()) temp++, cnt++;
            res = max(res, cnt);
        }
        return res;
    }
};