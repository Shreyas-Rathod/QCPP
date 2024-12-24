class Solution {  
public:  
    vector<vector<int>> fourSum(vector<int>& nums, int target) {  
        int n = nums.size();  
        vector<vector<int>> res;  

        if (n < 4) return res;  

        sort(nums.begin(), nums.end());  

        for (int i = 0; i < n - 3; i++) {  
            // Skip duplicates for the first number  
            if (i > 0 && nums[i] == nums[i - 1]) continue;  
            for (int j = i + 1; j < n - 2; j++) {  
                // Skip duplicates for the second number  
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;  

                int l = j + 1;  
                int r = n - 1;  

                while (l < r) {  
                    long long sum = nums[i]; 
                    sum += nums[j];
                    sum += nums[l]; 
                    sum += nums[r];  

                    if (sum > target) r--;  
                    else if (sum < target) l++;  
                    else {  
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});  
                        l++;  
                        r--;  
                        // Skip duplicates for the third number  
                        while (l < r && nums[l] == nums[l - 1]) l++;  
                        // Skip duplicates for the fourth number  
                        while (l < r && nums[r] == nums[r + 1]) r--;  
                    }  
                }  
            }  
        }  

        return res;  
    }  
};