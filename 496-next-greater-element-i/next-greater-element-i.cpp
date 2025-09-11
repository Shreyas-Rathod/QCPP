class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int>res(n2, -1);
        stack<int>st;

        for(int i = n2-1;i>=0;i--){
            if(st.empty()){st.push(nums2[i]); continue;}
            while(!st.empty() && nums2[i] > st.top()) st.pop();
            if(!st.empty()) res[i] = st.top();
            st.push(nums2[i]);
        }

        map<int, int>mp;
        for(int i = 0;i<n2;i++) mp[nums2[i]] = res[i];
        res.clear();
        for(int i = 0;i<n1;i++) res.push_back(mp[nums1[i]]);

        return res;

    }
};