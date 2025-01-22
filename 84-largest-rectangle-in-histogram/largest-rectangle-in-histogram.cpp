class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size(), maxarea = heights[0];
        stack<int>st;
        vector<int>right(n, 0), left(n, 0);
        for(int i = 0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            left[i] = st.empty() ? 0 : st.top() + 1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]) st.pop();
            right[i] = st.empty() ? n - 1 : st.top() - 1;
            st.push(i);
        }
        for(int i = 0;i<n;i++){
            maxarea = max(maxarea, heights[i]*(right[i]-left[i]+1));
        } 
        return maxarea;
    }
};