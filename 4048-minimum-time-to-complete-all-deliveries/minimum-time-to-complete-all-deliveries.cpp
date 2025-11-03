class Solution {
public:
    bool check(long long time, vector<int>&r, vector<int>&d){
        long long res1 = time - time/r[0];
        long long res2 = time - time/r[1];
        long long lcm = (long long) r[0] * r[1] / gcd(r[0], r[1]);
        long long khali = time/lcm;
        long long available = time - khali;

        if(res1 >= d[0] && res2 >= d[1] && (d[0]+d[1] <= available)) return true;

        return false;
    }
    int gcd(int a, int b){
        return (b == 0) ? a : gcd(b, a%b);
    }
    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long low = 0, high = (long) 1e18, mid;
        while(low < high){
            mid = (low + high) >> 1;
            if(check(mid, r, d)){
                high = mid;
            }
            else low = mid + 1;
        }
        return low;
    }
};