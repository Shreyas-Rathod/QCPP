class Solution {
public:
    // Helper function to generate all subset sums for a given half of the array.
    // It stores sums based on the number of elements chosen.
    void generateSums(const vector<int>& arr, int index, int count, int current_sum, vector<vector<int>>& sums) {
        // Base case: if we've considered all elements in this half.
        if (index == arr.size()) {
            sums[count].push_back(current_sum);
            return;
        }

        // Recursive case 1: Include the current element.
        generateSums(arr, index + 1, count + 1, current_sum + arr[index], sums);

        // Recursive case 2: Do not include the current element.
        generateSums(arr, index + 1, count, current_sum, sums);
    }

    int minimumDifference(vector<int>& nums) {
        int n = nums.size();
        int m = n / 2;

        // 1. DIVIDE the array into two halves.
        vector<int> left_half(nums.begin(), nums.begin() + m);
        vector<int> right_half(nums.begin() + m, nums.end());

        // 2. CONQUER: Generate all possible sums for each half.
        // sums[k] will store a list of all sums of subsets of size k.
        vector<vector<int>> left_sums(m + 1);
        vector<vector<int>> right_sums(m + 1);

        generateSums(left_half, 0, 0, 0, left_sums);
        generateSums(right_half, 0, 0, 0, right_sums);

        // Sort the sums for the right half to enable binary search.
        for (int i = 0; i <= m; ++i) {
            sort(right_sums[i].begin(), right_sums[i].end());
        }

        long long total_sum = 0;
        for (int num : nums) {
            total_sum += num;
        }
        
        int min_diff = INT_MAX;

        // 3. COMBINE: Find the optimal pair of sums.
        // We need to pick 'k' elements from the left and 'm-k' from the right.
        for (int k = 0; k <= m; ++k) {
            // For each sum 's1' made from 'k' elements on the left...
            for (int s1 : left_sums[k]) {
                // ...we need a sum 's2' from 'm-k' elements on the right.
                // The target sum for one partition is total_sum / 2.
                // So, the target for s2 is (total_sum / 2) - s1.
                int target = (total_sum / 2) - s1;
                
                auto& s2_candidates = right_sums[m - k];
                
                // Use binary search (lower_bound) to find the s2 closest to the target.
                auto it = lower_bound(s2_candidates.begin(), s2_candidates.end(), target);

                // Check the element at the found position.
                if (it != s2_candidates.end()) {
                    int s2 = *it;
                    long long partition1_sum = s1 + s2;
                    long long partition2_sum = total_sum - partition1_sum;
                    min_diff = min(min_diff, (int)abs(partition1_sum - partition2_sum));
                }

            }
        }

        return min_diff;
    }
};