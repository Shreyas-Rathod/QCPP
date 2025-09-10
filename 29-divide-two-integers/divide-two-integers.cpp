class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long div = abs((long)dividend);
        long dsor = abs((long)divisor);
        long bin = 0;

        while(div >= dsor){
            int count = 0;
            while(div >= (dsor << (count+1))) count++;
            bin += 1 << count;
            div -= dsor << count;
        }

        return (dividend > 0) == (divisor > 0) ? bin : -bin;
    }
};