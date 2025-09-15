class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), res = heights[0];
        vector<int>left(n, -1), right(n, n);
        stack<int>st;

        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) right[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            if(!st.empty()) left[i] = st.top();
            st.push(i);
        }

        for(int i = 0;i<n;i++){
            res = max(res, heights[i]*(right[i] - left[i] - 1));
        }

        return res;
    }
};