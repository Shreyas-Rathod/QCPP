class Solution {
public:
    void generate_sum(vector<int>&nums, int index, int count, int sum, vector<vector<int>>&sums){
        if(index == nums.size()){
            sums[count].push_back(sum);
            return;
        }
        generate_sum(nums, index + 1, count + 1, sum + nums[index], sums);
        generate_sum(nums, index + 1, count, sum, sums);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n/2;

        vector<int>left_half(nums.begin(), nums.begin() + m);
        vector<int>right_half(nums.begin()+m, nums.end());

        vector<vector<int>>left_sum(m + 1);
        vector<vector<int>>right_sum(m + 1);

        generate_sum(left_half, 0, 0, 0, left_sum);
        generate_sum(right_half, 0, 0, 0, right_sum);

        for(int i = 0;i<=m;i++){
            sort(right_sum[i].begin(), right_sum[i].end());
        }

        int total_sum = 0, min_diff = INT_MAX;
        for(int i = 0;i<n;i++) total_sum += nums[i];

        for(int k = 0;k<=m;k++){
            for(int s1 : left_sum[k]){
                int target = total_sum/2 - s1;
                auto& s2_candi = right_sum[m-k];

                auto it = lower_bound(s2_candi.begin(), s2_candi.end(), target);

                if(it != s2_candi.end()){
                    int s2 = *it;
                    long long partA_sum = s1 + s2;
                    long long partB_sum = total_sum - partA_sum;
                    min_diff = min(min_diff, (int)abs(partA_sum - partB_sum));
                }
            }
        }

        return min_diff;

    }
};