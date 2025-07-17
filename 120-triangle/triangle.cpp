class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        for(int i = 1;i<n;i++){
            int m = i + 1;
            int j = 0;
            triangle[i][j] += triangle[i-1][j];
            while(++j < m-1){
                triangle[i][j] += min(triangle[i-1][j], triangle[i-1][j-1]);
            }
            if(j == m-1) triangle[i][j] += triangle[i-1][j-1];
        }
        int res = triangle[n-1][0];
        for(auto it : triangle[n-1]) res = min(res, it);

        return res;
    }
};