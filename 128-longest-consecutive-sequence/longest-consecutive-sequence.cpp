class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size(), res = 0, maxi, x;
        if(n == 0) return res;
        set<int>st;

        for(int x : nums) st.insert(x);

        maxi = 1, x;
        for(int m : st){
            if(st.find(m-1) == st.end()){
                maxi = 1, x = m;
            }
            while(st.find(x+1) != st.end()) maxi++, x++;
            res = max(res, maxi);
        }

        return res;
    }
};