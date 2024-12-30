class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size(), low, mid, high, b, t;
        if((long)m*k > n) return -1;
        low = *min_element(bloomDay.begin(), bloomDay.end());
        high = *max_element(bloomDay.begin(), bloomDay.end());

        auto check = [&](int x){
            b = 0, t = 0;
            for(int i = 0;i<n;i++){
                if(bloomDay[i] <= x) t++;
                else{
                    b += t/k;
                    t = 0;
                }
            }
            b += t/k;
            return b>=m;
        };

        while(low <= high){
            mid = (low+high)>>1;
            if(check(mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};