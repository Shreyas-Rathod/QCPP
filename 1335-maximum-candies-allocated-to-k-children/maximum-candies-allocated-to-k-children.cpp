class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int low = 1, high = *max_element(candies.begin(), candies.end()), mid, n = candies.size();

        auto check = [&](int x){
            long long cnt = 0;
            for(int i = 0;i<n;i++) cnt += candies[i]/x;
            return cnt >= k;
        };

        while(low<=high){
            mid = (low+high)>>1;
            if(check(mid)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};