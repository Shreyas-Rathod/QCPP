class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>mat(n, vector<int>(n, INT_MAX));
        int m = edges.size();
        for(int i = 0;i<m;i++){
            mat[edges[i][0]][edges[i][1]] = edges[i][2];
            mat[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int i = 0;i<n;i++) mat[i][i] = 0;

        for(int k = 0;k<n;k++){
            for(int i = 0;i<n;i++){
                for(int j = 0;j<n;j++){
                    if(mat[i][k] == INT_MAX || mat[k][j] == INT_MAX) continue;
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        vector<int>count(n, 0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(i == j) continue;
                if(mat[i][j] <= distanceThreshold) count[i]++;
            }
        }

        int res = INT_MAX, ans = 0;
        for(int i = 0;i<n;i++){
            if(count[i] <= res) res = count[i], ans = i;
        }

        return ans;
    }
};