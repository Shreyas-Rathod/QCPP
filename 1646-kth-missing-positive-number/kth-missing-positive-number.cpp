class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int st = 0, ed = arr.size() - 1, mid;
        while(st<=ed){
            mid = (st+ed)/2;
            if(arr[mid]-(mid+1) < k) st = mid + 1;
            else ed = mid - 1;
        }
        return ed + k + 1;
    }
};