class Solution {
public:
    int fun(vector<int>&height){
        stack<int>st;
        int area = 0, h, w, n = height.size();
        for(int i = 0;i<=n;i++){
            while(!st.empty() && ((i==n) || height[st.top()] >= height[i])){
                h = height[st.top()];
                st.pop();
                if(st.empty()) w = i;
                else w = i - st.top() - 1;
                area = max(area, w * h);
            }
            st.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(), maxArea = 0;
        vector<int>height(m, 0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(matrix[i][j] == '1') height[j]++;
                else height[j] = 0;
            }
            maxArea = max(maxArea, fun(height));
        }

        return maxArea;
    }
};