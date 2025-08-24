class Solution {
public:
    int mySqrt(int x) {
        int low = 0, high = x, mid, ans = -1;
        if(x < 2) return x; 
        while(low <= high){
            mid = (low + high) >> 1;
            if(x/mid == mid) return mid;
            else if(mid > x/mid) high = mid - 1;
            else ans = mid, low = mid + 1;
        }

        return ans;
    }
};