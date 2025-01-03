class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int start = 0, end = m*n-1, mid, rowd = 0, colr = 0;
        while(start<=end){
            mid = (start+end)/2;
            rowd = mid/m;
            colr = mid%m;
            if(matrix[rowd][colr] == target) return true;
            else if(matrix[rowd][colr]<target) start = mid + 1;
            else end = mid - 1;
        }
        return false;
    }
};