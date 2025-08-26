class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>res;
        int i = 0, j = 0, n1 = nums1.size(), n2 = nums2.size();
        while(i < n1 && j < n2){
            if(nums1[i] <= nums2[j]) res.push_back(nums1[i++]);
            else res.push_back(nums2[j++]);
        }
        while(i < n1) res.push_back(nums1[i++]);
        while(j < n2) res.push_back(nums2[j++]);

        if(res.size()%2) return res[(n1+n2-1)/2];
        else return (double)(res[(n1+n2-1)/2] + res[(n1+n2)/2])/2.0;
    }
};