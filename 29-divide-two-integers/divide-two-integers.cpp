class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        // Convert to absolute values
        long div = abs((long)dividend);
        long dsor = abs((long)divisor);

        long bins = 0; // Stores the quotient

        // Use bit manipulation to calculate the quotient
        while (div >= dsor) {
            int count = 0;

            // Find the largest power of 2 such that (divisor * 2^count) <= dividend
            while (dsor << (count + 1) <= div) {
                count++;
            }

            // Add the power of 2 to the quotient
            bins += 1 << count;

            // Subtract (divisor * 2^count) from the dividend
            div -= dsor << count;
        }

        // Determine the sign of the quotient
        return ((dividend > 0) == (divisor > 0)) ? bins : -bins;
    }
};