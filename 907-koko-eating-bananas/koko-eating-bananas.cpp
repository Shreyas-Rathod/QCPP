class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 0, high = 1, mid, n = piles.size();
        auto check = [&](int x){
            long long hours = 0;
            for(int i = 0;i<n;i++) hours += (piles[i]+x-1)/x;
            return hours <= h;
        };
        while(!check(high)) high *= 2;
        while(low + 1 < high){
            mid = (low+high)>>1;
            if(check(mid)) high = mid;
            else low = mid;
        }
        return high;
    }
};