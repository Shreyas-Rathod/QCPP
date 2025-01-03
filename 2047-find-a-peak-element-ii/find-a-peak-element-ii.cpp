class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int low = 0, high = m - 1, mid, r, left, right, l1, h1, mid1, up, down;

        auto maxele = [&](int co){
            int maxi = -1, index = -1;
            for(int i = 0;i<n;i++){
                if(maxi < mat[i][co]){
                    maxi = mat[i][co];
                    index = i;
                }
            }
            return index;
        };

        while(low<=high){
            mid = (low+high)>>1;
            r = maxele(mid);
            left = (mid - 1 >= 0) ? mat[r][mid-1] : -1;
            right = (mid + 1 < m) ? mat[r][mid+1] : -1;
            if(mat[r][mid] > left && mat[r][mid] > right) return {r, mid};
            if(mat[r][mid] < left) high = mid - 1;
            else low = mid + 1;
        }

        return {0, 0};
    }
};