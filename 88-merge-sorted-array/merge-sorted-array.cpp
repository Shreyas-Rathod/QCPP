class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0){
            nums1 = nums2;
            return;
        }
        int i = nums1.size() - 1;
        m--, n--;
        while(i>=0 && n>=0 && m>=0){
            if(nums1[m] > nums2[n]){
                nums1[i] = nums1[m];
                m--;
            }
            else nums1[i] = nums2[n], n--;
            i--;
        }
        if(n>=0) while(n>=0) nums1[i--] = nums2[n--];
    }
};