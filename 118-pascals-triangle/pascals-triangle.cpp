class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>res{{1}};
        vector<int>temp;

        for(int i = 1;i<numRows;i++){
            temp.clear();
            temp.push_back(1);
            for(int j = 1;j<i;j++) temp.push_back(res[i-1][j-1]+res[i-1][j]);
            temp.push_back(1);

            res.push_back(temp);
        }

        return res;

    }
};